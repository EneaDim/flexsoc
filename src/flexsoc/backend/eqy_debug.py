"""Discover, summarize, and open EQY equivalence counterexamples."""

from __future__ import annotations

import hashlib
import json
import os
import re
import shutil
import subprocess
import time
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Callable, Iterable

from flexsoc.run_layout import pdk_run_layout, run_root


_STATUS_ORDER = {"FAIL": 5, "ERROR": 4, "TIMEOUT": 3, "UNKNOWN": 2, "PASS": 1, "MISSING": 0}
_TRACE_NAMES = ("trace.vcd", "trace_induct.vcd", "trace.yw", "trace.smtc", "trace_tb.v")
_LOG_NAMES = ("logfile.txt", "logfile_basecase.txt", "logfile_induction.txt")
_INTERESTING_WORDS = (
    "gold", "gate", "clk", "clock", "rst", "reset", "valid", "ready", "ack",
    "outstanding", "equiv", "trigger", "assert", "compare",
)


@dataclass(frozen=True, slots=True)
class StrategyResult:
    """One EQY strategy result for one partition."""

    name: str
    status: str
    directory: Path
    traces: tuple[Path, ...]
    logs: tuple[Path, ...]

    def to_dict(self) -> dict[str, object]:
        data = asdict(self)
        data["directory"] = str(self.directory)
        data["traces"] = [str(path) for path in self.traces]
        data["logs"] = [str(path) for path in self.logs]
        return data


@dataclass(frozen=True, slots=True)
class Counterexample:
    """Aggregate EQY result for one partition."""

    partition: str
    status: str
    directory: Path
    strategies: tuple[StrategyResult, ...]

    @property
    def failing_strategy(self) -> StrategyResult | None:
        """Return the non-PASS strategy that carries the best diagnostic evidence.

        EQY can propagate a partition FAIL status to later strategy directories even
        when those strategies were never executed.  Prefer the strategy that owns
        concrete artifacts (trace/log files) so ``show``/``wave`` land on the run
        that actually produced the counterexample.
        """

        candidates = [item for item in self.strategies if item.status != "PASS"]
        if not candidates:
            return None

        def diagnostic_rank(item: StrategyResult) -> tuple[int, int, int, int]:
            vcd_count = sum(path.suffix.lower() == ".vcd" for path in item.traces)
            evidence_count = len(item.traces) + len(item.logs)
            executed = int(evidence_count > 0 or item.directory.name == self.partition)
            return (
                int(vcd_count > 0),
                int(evidence_count > 0),
                executed,
                _STATUS_ORDER.get(item.status, 0),
            )

        return max(candidates, key=diagnostic_rank)

    def to_dict(self) -> dict[str, object]:
        return {
            "partition": self.partition,
            "status": self.status,
            "directory": str(self.directory),
            "strategies": [item.to_dict() for item in self.strategies],
            "failing_strategy": self.failing_strategy.name if self.failing_strategy else None,
        }


def _status(path: Path) -> str:
    if not path.is_file():
        return "MISSING"
    words = path.read_text(encoding="utf-8", errors="replace").strip().upper().split()
    return words[0] if words else "UNKNOWN"


def _best_status(values: Iterable[str]) -> str:
    return max(values, key=lambda value: _STATUS_ORDER.get(value, 0), default="MISSING")


def _nested_run_dir(strategy_dir: Path, partition: str) -> Path:
    direct = strategy_dir / partition
    if direct.is_dir():
        return direct
    nested = [path for path in strategy_dir.iterdir() if path.is_dir()] if strategy_dir.is_dir() else []
    return nested[0] if len(nested) == 1 else strategy_dir


def discover_result_dir(
    project_root: Path,
    workspace: Path,
    *,
    top: str,
    run_top: str,
    run_id: str,
    pdk: str | None = None,
) -> Path:
    """Find the EQY result directory for the selected run/technology.

    ``pdk=None`` preserves the legacy layout for callers inspecting old runs.
    The ``fx`` CLI always supplies the active PDK and therefore never silently
    falls back to stale equivalence results from another technology.
    """

    shared = run_root(workspace, run_top=run_top, run_id=run_id)
    if pdk:
        layout = pdk_run_layout(shared, pdk=pdk, top=top)
        expected = layout.equivalence_dir / f"{top}_rtl_vs_syn"
    else:
        # Explicit legacy mode only. The fx CLI always supplies PDK and never
        # falls back to an artifact generated for another technology.
        expected = shared / "dv" / "formal" / "equivalence" / "rtl_vs_syn" / f"{top}_rtl_vs_syn"
    if expected.is_dir():
        return expected

    base = expected.parent
    candidates = sorted(
        (path for path in base.glob("*_rtl_vs_syn") if path.is_dir()),
        key=lambda path: path.stat().st_mtime,
        reverse=True,
    ) if base.is_dir() else []
    if candidates:
        return candidates[0]

    technology = f" PDK={pdk}" if pdk else " legacy-layout"
    raise FileNotFoundError(
        f"EQY result directory not found for TOP={top} RUN_TOP={run_top} RUN_ID={run_id}{technology}: {expected}"
    )


def scan(result_dir: Path) -> tuple[Counterexample, ...]:
    """Scan all EQY partitions and strategy result directories."""

    strategy_root = result_dir / "strategies"
    if not strategy_root.is_dir():
        return ()

    output: list[Counterexample] = []
    for partition_dir in sorted(path for path in strategy_root.iterdir() if path.is_dir()):
        strategies: list[StrategyResult] = []
        for strategy_dir in sorted(path for path in partition_dir.iterdir() if path.is_dir()):
            nested = _nested_run_dir(strategy_dir, partition_dir.name)
            statuses = [_status(strategy_dir / "status"), _status(nested / "status")]
            status = _best_status(value for value in statuses if value != "MISSING")
            traces: list[Path] = []
            logs: list[Path] = []
            engine_dirs = sorted(path for path in nested.glob("engine_*") if path.is_dir())
            search_dirs = [nested, *engine_dirs]
            for directory in search_dirs:
                for name in _TRACE_NAMES:
                    path = directory / name
                    if path.is_file() and path not in traces:
                        traces.append(path)
                for name in _LOG_NAMES:
                    path = directory / name
                    if path.is_file() and path not in logs:
                        logs.append(path)
            strategies.append(
                StrategyResult(
                    name=strategy_dir.name,
                    status=status,
                    directory=nested,
                    traces=tuple(traces),
                    logs=tuple(logs),
                )
            )
        overall = _best_status(item.status for item in strategies)
        output.append(Counterexample(partition_dir.name, overall, partition_dir, tuple(strategies)))
    return tuple(output)


def select(items: Iterable[Counterexample], partition: str | None = None) -> Counterexample:
    """Select an explicit partition or the unique non-PASS partition."""

    rows = tuple(items)
    if partition:
        exact = [item for item in rows if item.partition == partition]
        if exact:
            return exact[0]
        partial = [item for item in rows if partition in item.partition]
        if len(partial) == 1:
            return partial[0]
        if partial:
            names = ", ".join(item.partition for item in partial[:10])
            raise ValueError(f"partition {partition!r} is ambiguous: {names}")
        raise ValueError(f"partition not found: {partition}")

    failing = [item for item in rows if item.status != "PASS"]
    if len(failing) == 1:
        return failing[0]
    if not failing:
        raise ValueError("no EQY counterexamples found: all discovered partitions PASS")
    names = ", ".join(item.partition for item in failing[:10])
    suffix = " ..." if len(failing) > 10 else ""
    raise ValueError(f"multiple non-PASS partitions; choose one explicitly: {names}{suffix}")


def interesting_log_lines(strategy: StrategyResult, *, limit: int = 40) -> list[str]:
    """Extract compact diagnostic lines from SBY/EQY logs."""

    pattern = re.compile(r"fail|counter|assert|basecase|induction|equiv|unreached|timeout|error|trace", re.I)
    lines: list[str] = []
    for path in strategy.logs:
        for raw in path.read_text(encoding="utf-8", errors="replace").splitlines():
            if pattern.search(raw):
                line = raw.strip()
                if line and line not in lines:
                    lines.append(line)
                if len(lines) >= limit:
                    return lines
    return lines


def parse_vcd_signals(vcd: Path) -> tuple[str, ...]:
    """Return fully-qualified signal names found in a VCD header."""

    scope: list[str] = []
    signals: list[str] = []
    try:
        with vcd.open("r", encoding="utf-8", errors="replace") as handle:
            for raw in handle:
                line = raw.strip()
                if line.startswith("$scope "):
                    parts = line.split()
                    if len(parts) >= 3:
                        scope.append(parts[2])
                elif line.startswith("$upscope"):
                    if scope:
                        scope.pop()
                elif line.startswith("$var "):
                    parts = line.split()
                    if len(parts) >= 5:
                        reference = parts[4]
                        if len(parts) >= 6 and parts[5].startswith("["):
                            reference += parts[5]
                        signals.append(".".join((*scope, reference)))
                elif line.startswith("$enddefinitions"):
                    break
    except OSError:
        return ()
    return tuple(signals)


def ranked_signals(vcd: Path, partition: str, *, limit: int = 48) -> tuple[str, ...]:
    """Rank VCD signals for a useful counterexample first view."""

    signals = parse_vcd_signals(vcd)
    tokens = [token.lower() for token in re.split(r"[^A-Za-z0-9_]+", partition) if len(token) >= 2]

    def score(name: str) -> tuple[int, str]:
        lower = name.lower()
        value = 0
        for token in tokens:
            if token in lower:
                value += 8
        for word in _INTERESTING_WORDS:
            if word in lower:
                value += 4
        if "gold" in lower or "gate" in lower:
            value += 4
        return (-value, name)

    ranked = sorted(signals, key=score)
    selected = [name for name in ranked if score(name)[0] < 0][:limit]
    if not selected:
        selected = ranked[: min(limit, len(ranked))]
    return tuple(selected)


def choose_trace(strategy: StrategyResult, kind: str = "auto") -> Path:
    """Choose the VCD trace to open."""

    vcdb = [path for path in strategy.traces if path.suffix.lower() == ".vcd"]
    if not vcdb:
        raise FileNotFoundError(f"no VCD trace found for strategy {strategy.name}")
    normalized = kind.lower().replace("-", "_")
    if normalized in {"induction", "induct"}:
        for path in vcdb:
            if "induct" in path.name:
                return path
        raise FileNotFoundError("induction VCD trace not found")
    if normalized in {"base", "basecase", "auto"}:
        for path in vcdb:
            if "induct" not in path.name:
                return path
        return vcdb[0]
    raise ValueError("trace kind must be auto, basecase, or induction")


def write_gtkwave_session(vcd: Path, partition: str, *, output: Path | None = None) -> Path:
    """Write a small GTKWave save file focused on likely counterexample signals."""

    output = output or vcd.with_name(f"{partition.replace('/', '_')}.gtkw")
    signals = ranked_signals(vcd, partition)
    lines = [
        "[*] FlexSoC EQY counterexample session",
        f'[dumpfile] "{vcd}"',
        "[timestart] 0",
    ]
    for signal in signals:
        lines.extend(("@28", signal))
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    return output


def open_wave(vcd: Path, partition: str, *, viewer: str = "gtkwave", background: bool = True) -> tuple[Path | None, tuple[str, ...]]:
    """Open a counterexample waveform and return session/command metadata."""

    viewer = viewer.strip().lower()
    if viewer == "gtkwave":
        executable = shutil.which("gtkwave")
        if not executable:
            raise FileNotFoundError("gtkwave not found in PATH")
        session = write_gtkwave_session(vcd, partition)
        command = (executable, str(vcd), str(session))
    elif viewer == "surfer":
        executable = shutil.which("surfer")
        if not executable:
            raise FileNotFoundError("surfer not found in PATH")
        session = None
        command = (executable, str(vcd))
    else:
        raise ValueError("WAVE_VIEWER must be gtkwave or surfer")

    kwargs: dict[str, object] = {}
    if background:
        kwargs.update(stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True)
    subprocess.Popen(command, **kwargs)  # noqa: S603 - explicit local EDA viewer command.
    return session, command


def json_text(items: Iterable[Counterexample]) -> str:
    return json.dumps([item.to_dict() for item in items], indent=2)


def failure_metadata(strategy: StrategyResult) -> dict[str, object]:
    """Extract the failing phase, bounded step and assertion from SBY logs."""

    result: dict[str, object] = {
        "phase": None,
        "step": None,
        "assertion": None,
    }
    phase_patterns = (
        ("basecase", re.compile(r"basecase.*(?:FAIL|failed)|BMC failed", re.I)),
        ("induction", re.compile(r"induction.*(?:FAIL|failed)|Temporal induction failed", re.I)),
    )
    step_re = re.compile(r"failed assertion .*? step\s+(\d+)", re.I)
    assertion_re = re.compile(r"Assert failed in\s+([^:]+):([^\s]+)", re.I)

    lines: list[str] = []
    for path in strategy.logs:
        lines.extend(path.read_text(encoding="utf-8", errors="replace").splitlines())

    for line in lines:
        if result["phase"] is None:
            for phase, pattern in phase_patterns:
                if pattern.search(line):
                    result["phase"] = phase
                    break
        if result["step"] is None:
            match = step_re.search(line)
            if match:
                result["step"] = int(match.group(1))
        if result["assertion"] is None:
            match = assertion_re.search(line)
            if match:
                result["assertion"] = f"{match.group(1)}:{match.group(2)}"

    return result


def _vcd_header(vcd: Path) -> tuple[dict[str, str], dict[str, str]]:
    """Return VCD identifier-to-name and name-to-identifier maps."""

    scope: list[str] = []
    by_id: dict[str, str] = {}
    by_name: dict[str, str] = {}
    with vcd.open("r", encoding="utf-8", errors="replace") as handle:
        for raw in handle:
            line = raw.strip()
            if line.startswith("$scope "):
                parts = line.split()
                if len(parts) >= 3:
                    scope.append(parts[2])
            elif line.startswith("$upscope"):
                if scope:
                    scope.pop()
            elif line.startswith("$var "):
                parts = line.split()
                if len(parts) >= 5:
                    identifier = parts[3]
                    reference = parts[4]
                    if len(parts) >= 6 and parts[5].startswith("["):
                        reference += parts[5]
                    full = ".".join((*scope, reference))
                    by_id[identifier] = full
                    by_name[full] = identifier
            elif line.startswith("$enddefinitions"):
                break
    return by_id, by_name


def _pair_candidates(names: Iterable[str], partition: str) -> list[tuple[str, str, str]]:
    """Return likely gold/gate VCD signal pairs, ordered by diagnostic value."""

    available = set(names)
    tokens = [token.lower() for token in re.split(r"[^A-Za-z0-9_]+", partition) if token]
    pairs: list[tuple[int, str, str, str]] = []

    def add(gold: str, gate: str, kind: str) -> None:
        if gate not in available:
            return
        lower = gold.lower()
        score = 0
        if all(token in lower for token in tokens[-2:]):
            score += 20
        if "__po_" in lower or "assert" in lower:
            score += 15
        if kind == "value":
            score += 8
        elif kind == "xmask":
            score += 6
        elif kind == "data":
            score += 4
        pairs.append((-score, gold, gate, kind))

    for name in sorted(available):
        lower = name.lower()
        if ".gold." in lower:
            index = lower.index(".gold.")
            gate = name[:index] + ".gate." + name[index + len(".gold."):]
            add(name, gate, "value")
        if "__gold_x" in lower:
            index = lower.index("__gold_x")
            gate = name[:index] + "__gate_x" + name[index + len("__gold_x"):]
            add(name, gate, "xmask")
        elif "__gold_d" in lower:
            index = lower.index("__gold_d")
            gate = name[:index] + "__gate_d" + name[index + len("__gold_d"):]
            add(name, gate, "data")
        elif "__gold" in lower:
            index = lower.index("__gold")
            gate = name[:index] + "__gate" + name[index + len("__gold"):]
            add(name, gate, "value")

    seen: set[tuple[str, str]] = set()
    output: list[tuple[str, str, str]] = []
    for _, gold, gate, kind in sorted(pairs):
        key = (gold, gate)
        if key not in seen:
            seen.add(key)
            output.append((gold, gate, kind))
    return output


def _normalize_vcd_value(raw: str) -> str:
    value = raw.strip().lower()
    if not value:
        return value
    if value[0] in "bBrR":
        return value[1:].split()[0].lower()
    return value[0]


def _xprop_quartets(names: Iterable[str], partition: str) -> list[tuple[str, str, str, str]]:
    """Return ``gold_d/gold_x/gate_d/gate_x`` groups ordered by relevance.

    EQY's formal X-propagation miter exposes both data and X-mask signals.
    Comparing the raw ``gold`` and ``gate`` value wires first can therefore
    misclassify an X-compatible trace as a Boolean mismatch.
    """

    available = set(names)
    tokens = [token.lower() for token in re.split(r"[^A-Za-z0-9_]+", partition) if token]
    ranked: list[tuple[int, tuple[str, str, str, str]]] = []
    for gold_d in sorted(available):
        lower = gold_d.lower()
        marker = "__gold_d"
        if marker not in lower:
            continue
        index = lower.index(marker)
        prefix = gold_d[:index]
        suffix = gold_d[index + len(marker):]
        gold_x = prefix + "__gold_x" + suffix
        gate_d = prefix + "__gate_d" + suffix
        gate_x = prefix + "__gate_x" + suffix
        if not all(name in available for name in (gold_x, gate_d, gate_x)):
            continue
        score = 0
        if all(token in lower for token in tokens[-2:]):
            score += 20
        if "__po_" in lower or "assert" in lower:
            score += 15
        ranked.append((-score, (gold_d, gold_x, gate_d, gate_x)))
    return [quartet for _, quartet in sorted(ranked)]


def _mask_is_unknown(value: str) -> bool:
    """Return true when a one-bit/vector X mask contains an asserted bit."""

    value = value.lower()
    return any(bit in value for bit in ("1", "x", "z"))


def first_vcd_divergence(vcd: Path, partition: str) -> dict[str, object] | None:
    """Find the first semantic gold/gate mismatch in an EQY VCD trace.

    Prefer EQY's formal-X data/mask quartet when present.  A differing raw data
    bit is *not* a Boolean mismatch if the corresponding gold X-mask says that
    the value is unknown/don't-care.  This distinction is essential when
    ``xprop on`` is used by the SBY equivalence strategy.
    """

    by_id, by_name = _vcd_header(vcd)
    quartets = _xprop_quartets(by_name, partition)
    pairs = _pair_candidates(by_name, partition)
    if not quartets and not pairs:
        return None

    watched_names = {name for quartet in quartets for name in quartet}
    watched_names.update(name for pair in pairs for name in pair[:2])
    context_names = tuple(
        name for name in ranked_signals(vcd, partition, limit=40)
        if any(word in name.lower() for word in ("clk", "clock", "rst", "reset"))
    )[:12]
    watched_names.update(context_names)
    watched_ids = {by_name[name] for name in watched_names if name in by_name}

    state: dict[str, str] = {}
    time = 0
    header_done = False

    def context() -> list[dict[str, str]]:
        return [
            {"signal": name, "value": state.get(by_name[name], "?")}
            for name in context_names
            if name in by_name
        ]

    def check() -> dict[str, object] | None:
        # Formal-X semantic comparison first.  Gold X is a don't-care under
        # EQY safe-replacement semantics; known gold data must match gate data.
        for gold_d, gold_x, gate_d, gate_x in quartets:
            ids = [by_name[name] for name in (gold_d, gold_x, gate_d, gate_x)]
            if any(identifier not in state for identifier in ids):
                continue
            gd, gx, td, tx = (state[identifier] for identifier in ids)
            gold_unknown = _mask_is_unknown(gx)
            gate_unknown = _mask_is_unknown(tx)
            if gate_unknown or (not gold_unknown and gd != td):
                return {
                    "time": time,
                    "gold_signal": gold_d,
                    "gate_signal": gate_d,
                    "gold": gd,
                    "gate": td,
                    "gold_x_signal": gold_x,
                    "gate_x_signal": gate_x,
                    "gold_x": gx,
                    "gate_x": tx,
                    "kind": "xprop",
                    "class": "x-init" if gate_unknown else "boolean-data",
                    "context": context(),
                }

        # Fall back to ordinary gold/gate pairs only when no formal-X quartet
        # exists for that logical pair.  This keeps old/non-xprop traces useful.
        quartet_names = {name for quartet in quartets for name in quartet}
        for gold, gate, kind in pairs:
            if gold in quartet_names or gate in quartet_names:
                continue
            gold_id = by_name[gold]
            gate_id = by_name[gate]
            if gold_id not in state or gate_id not in state:
                continue
            gold_value = state[gold_id]
            gate_value = state[gate_id]
            if gold_value != gate_value:
                category = (
                    "x-init"
                    if kind == "xmask" or any(char in gold_value + gate_value for char in "xz")
                    else "boolean-data"
                )
                return {
                    "time": time,
                    "gold_signal": gold,
                    "gate_signal": gate,
                    "gold": gold_value,
                    "gate": gate_value,
                    "kind": kind,
                    "class": category,
                    "context": context(),
                }
        return None

    with vcd.open("r", encoding="utf-8", errors="replace") as handle:
        pending_check = False
        for raw in handle:
            line = raw.strip()
            if not header_done:
                if line.startswith("$enddefinitions"):
                    header_done = True
                continue
            if not line:
                continue
            if line.startswith("#"):
                if pending_check:
                    found = check()
                    if found:
                        return found
                try:
                    time = int(line[1:])
                except ValueError:
                    pass
                pending_check = False
                continue
            if line.startswith("$"):
                continue
            if line[0] in "bBrR":
                parts = line.split()
                if len(parts) >= 2 and parts[1] in watched_ids:
                    state[parts[1]] = _normalize_vcd_value(parts[0])
                    pending_check = True
            else:
                identifier = line[1:]
                if identifier in watched_ids:
                    state[identifier] = _normalize_vcd_value(line[0])
                    pending_check = True
        if pending_check:
            return check()
    return None




def _eqy_config_for_result(result_dir: Path) -> Path:
    """Return the generated EQY config associated with one result directory."""

    result_dir = result_dir.expanduser().resolve()
    eqy_root = result_dir.parent
    config = eqy_root / f"{result_dir.name}.eqy"
    if config.is_file():
        return config
    candidates = tuple(sorted(eqy_root.glob("*.eqy")))
    if len(candidates) != 1:
        raise FileNotFoundError(f"cannot identify EQY config beside result: {result_dir}")
    return candidates[0]


def _probe_target(result_dir: Path, partition: str) -> str:
    """Return the final generated Make target for one EQY partition."""

    path = result_dir / "summary_targets.list"
    if not path.is_file():
        raise RuntimeError(f"EQY setup did not create {path}")
    prefix = f"strategies/{partition}/"
    matches = [line.strip() for line in path.read_text(encoding="utf-8").splitlines()
               if line.strip().startswith(prefix) and line.strip().endswith("/status")]
    if len(matches) != 1:
        raise RuntimeError(
            f"cannot identify final EQY strategy target for {partition}: "
            f"found {len(matches)}"
        )
    return matches[0]


def _run_eqy_probe(
    result_dir: Path,
    *,
    name: str,
    config_text: str,
    partition: str,
    eqy: str = "eqy",
) -> dict[str, object]:
    """Set up EQY, then prove only ``partition`` instead of the full design.

    EQY's setup mode generates matching, partitions, ``strategies.mk`` and
    ``summary_targets.list`` without running proofs.  The generated final target
    for one partition already carries the dependency chain between strategies,
    so invoking that target is equivalent to the normal EQY strategy ordering
    without re-proving every unrelated partition.
    """

    result_dir = result_dir.expanduser().resolve()
    config = _eqy_config_for_result(result_dir)
    diagnostic_dir = result_dir.parent / "diagnostics" / name
    diagnostic_dir.mkdir(parents=True, exist_ok=True)
    diagnostic_config = diagnostic_dir / config.name
    diagnostic_result = diagnostic_dir / config.stem
    log = diagnostic_dir / "eqy_debug.log"
    stamp = diagnostic_dir / ".probe.json"
    digest = hashlib.sha256(config_text.encode("utf-8")).hexdigest()
    key = {"config_sha256": digest, "partition": partition}

    executable = shutil.which(eqy) or (eqy if Path(eqy).is_file() else None)
    if executable is None:
        raise FileNotFoundError(f"EQY executable not found: {eqy}")

    cached = False
    target = None
    if diagnostic_result.is_dir() and stamp.is_file():
        try:
            cached = json.loads(stamp.read_text(encoding="utf-8")) == key
            if cached:
                target = _probe_target(diagnostic_result, partition)
                cached = (diagnostic_result / target).is_file()
        except (OSError, ValueError, json.JSONDecodeError, RuntimeError):
            cached = False

    setup_seconds = 0.0
    prove_seconds = 0.0
    if not cached:
        diagnostic_config.write_text(config_text, encoding="utf-8")
        if diagnostic_result.exists():
            shutil.rmtree(diagnostic_result)
        started = time.monotonic()
        with log.open("w", encoding="utf-8") as handle:
            setup = subprocess.run(
                (str(executable), "-f", "-m", diagnostic_config.name),
                cwd=diagnostic_dir, stdout=handle, stderr=subprocess.STDOUT,
                text=True, check=False,
            )
        setup_seconds = time.monotonic() - started
        if setup.returncode != 0 or not diagnostic_result.is_dir():
            tail = log.read_text(encoding="utf-8", errors="replace").splitlines()[-20:]
            raise RuntimeError("EQY diagnostic setup failed (rc=%d)%s" % (
                setup.returncode, "\n" + "\n".join(tail) if tail else ""
            ))
        target = _probe_target(diagnostic_result, partition)
        started = time.monotonic()
        with log.open("a", encoding="utf-8") as handle:
            handle.write(f"\n[eqy_debug] make {target}\n")
            prove = subprocess.run(
                ("make", "--no-print-directory", "-C", str(diagnostic_result),
                 "-f", "strategies.mk", target),
                stdout=handle, stderr=subprocess.STDOUT, text=True, check=False,
            )
        prove_seconds = time.monotonic() - started
        stamp.write_text(json.dumps(key, sort_keys=True) + "\n", encoding="utf-8")
        if prove.returncode != 0 and not (diagnostic_result / target).is_file():
            tail = log.read_text(encoding="utf-8", errors="replace").splitlines()[-20:]
            raise RuntimeError("EQY partition probe failed (rc=%d)%s" % (
                prove.returncode, "\n" + "\n".join(tail) if tail else ""
            ))

    assert target is not None
    item = select(scan(diagnostic_result), partition)
    log_tail = [line.rstrip() for line in log.read_text(encoding="utf-8", errors="replace").splitlines()[-16:] if line.strip()] if log.is_file() else []
    return {
        "config": str(diagnostic_config), "result_dir": str(diagnostic_result),
        "log": str(log), "valid": item.status != "MISSING",
        "partition": partition, "status": item.status, "pass": item.status == "PASS",
        "strategy": item.failing_strategy.name if item.failing_strategy else None,
        "cached": cached, "setup_seconds": setup_seconds, "prove_seconds": prove_seconds,
        "log_tail": log_tail,
    }


def _inject_reset_initialization(
    source: str,
    *,
    clock: str,
    reset: str,
    reset_active: str,
    reset_cycles: int,
) -> str:
    """Inject reset initialization into the common or legacy EQY preprocessing.

    Modern FlexSoC EQY configs normalize gold and gate through one shared
    ``[script]`` section.  Insert the replay there so both designs receive the
    exact same transformation.  Legacy configs with per-side ``prep`` commands
    remain supported for already-generated runs.
    """

    if reset_active not in {"low", "high"}:
        raise ValueError("reset_active must be 'low' or 'high'")
    if reset_cycles <= 0:
        raise ValueError("reset_cycles must be > 0")
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_$]*", clock):
        raise ValueError(f"invalid clock port name: {clock!r}")
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_$]*", reset):
        raise ValueError(f"invalid reset port name: {reset!r}")

    reset_opt = "-resetn" if reset_active == "low" else "-reset"
    command = (
        f"sim -clock {clock} {reset_opt} {reset} -rstlen {reset_cycles} "
        f"-n {reset_cycles} -w"
    )
    lines = source.splitlines()

    # Preferred path: one shared formal-normalization script applied by EQY to
    # both gold and gate. Insert after async2sync, i.e. after reset semantics are
    # normalized but before matching/partitioning.
    section = ""
    if any(line.strip() == "async2sync" for line in lines):
        out: list[str] = []
        inserted = False
        for line in lines:
            stripped = line.strip()
            if stripped.startswith("[") and stripped.endswith("]"):
                section = stripped[1:-1].split()[0].lower()
            out.append(line)
            if section == "script" and stripped == "async2sync" and not inserted:
                out.extend(("uniquify", command))
                inserted = True
        if inserted:
            return "\n".join(out) + ("\n" if source.endswith("\n") else "")

    # Compatibility path for old generated configs that prepared each side
    # independently. Technology libraries reuse cell modules, so uniquify before
    # sim -w to make state writeback legal.
    out = []
    section = ""
    inserted_sides: set[str] = set()
    for line in lines:
        stripped = line.strip()
        if stripped.startswith("[") and stripped.endswith("]"):
            section = stripped[1:-1].split()[0].lower()
        out.append(line)
        if section in {"gold", "gate"} and stripped.startswith("prep "):
            out.extend(("uniquify", command))
            inserted_sides.add(section)
    missing = {"gold", "gate"} - inserted_sides
    if missing:
        raise ValueError(
            "cannot inject reset initialization; missing shared async2sync or prep "
            "command in EQY section(s): " + ", ".join(sorted(missing))
        )
    return "\n".join(out) + ("\n" if source.endswith("\n") else "")

def run_reset_normalized_diagnostic(
    result_dir: Path,
    *,
    partition: str,
    clock: str = "clk_i",
    reset: str = "rst_ni",
    reset_active: str = "low",
    reset_cycles: int = 1,
    eqy: str = "eqy",
) -> dict[str, object]:
    """Replay EQY after initializing both sides through the real reset port."""

    config = _eqy_config_for_result(result_dir)
    source = config.read_text(encoding="utf-8")
    rewritten = _inject_reset_initialization(
        source,
        clock=clock,
        reset=reset,
        reset_active=reset_active,
        reset_cycles=reset_cycles,
    )
    baseline = hashlib.sha256()
    for name in ("gold.il", "gate.il"):
        path = result_dir / name
        if path.is_file():
            baseline.update(path.read_bytes())
    rewritten += f"# FlexSoC baseline_sha256 {baseline.hexdigest()}\n"
    result = _run_eqy_probe(
        result_dir, name="reset_normalized", config_text=rewritten,
        partition=partition, eqy=eqy,
    )
    result.update(
        {
            "clock": clock,
            "reset": reset,
            "reset_active": reset_active,
            "reset_cycles": reset_cycles,
        }
    )
    return result

def _replace_gate_netlist(source: str, checkpoint: Path) -> str:
    """Point the generated EQY gate section at one RTLIL synthesis checkpoint."""

    lines = source.splitlines()
    section = ""
    candidates: list[int] = []
    for index, line in enumerate(lines):
        stripped = line.strip()
        if stripped.startswith("[") and stripped.endswith("]"):
            section = stripped[1:-1].split()[0].lower()
        elif section == "gate" and stripped.startswith("read_verilog "):
            candidates.append(index)
        elif section == "gate" and stripped.startswith("prep "):
            break
    if not candidates:
        raise ValueError("cannot identify mapped netlist read in EQY [gate] section")
    checkpoint = checkpoint.expanduser().resolve()
    lines[candidates[-1]] = f"read_rtlil {checkpoint}"
    digest = hashlib.sha256(checkpoint.read_bytes()).hexdigest()
    lines.append(f"# FlexSoC checkpoint_sha256 {digest}")
    return "\n".join(lines) + ("\n" if source.endswith("\n") else "")


def run_synthesis_boundary_diagnostics(
    result_dir: Path,
    *,
    top: str,
    syn_dir: Path,
    partition: str,
    eqy: str = "eqy",
    progress: Callable[[str], None] | None = None,
) -> dict[str, object]:
    """Probe only one failing partition at natural synthesis boundaries."""

    config = _eqy_config_for_result(result_dir)
    source = config.read_text(encoding="utf-8")
    checkpoints = {
        "generic": syn_dir / f"{top}_generic.il",
        "dffmap": syn_dir / f"{top}_dffmap.il",
        "abc": syn_dir / f"{top}_abc.il",
        "clean": syn_dir / f"{top}_clean.il",
    }
    stages: dict[str, object] = {}
    for name, checkpoint in checkpoints.items():
        if not checkpoint.is_file():
            stages[name] = {"valid": False, "missing": str(checkpoint)}
            continue
        if progress:
            progress(name)
        try:
            stages[name] = _run_eqy_probe(
                result_dir, name=f"synthesis_{name}",
                config_text=_replace_gate_netlist(source, checkpoint),
                partition=partition, eqy=eqy,
            )
        except (FileNotFoundError, ValueError, RuntimeError, OSError) as exc:
            stages[name] = {"valid": False, "error": str(exc), "checkpoint": str(checkpoint)}
        else:
            stages[name]["checkpoint"] = str(checkpoint)  # type: ignore[index]
    return {"partition": partition, "stages": stages}


def explain_counterexample(item: Counterexample, *, trace_kind: str = "auto") -> dict[str, object]:
    """Build a machine-readable explanation of one EQY counterexample."""

    strategy = item.failing_strategy
    if strategy is None:
        raise ValueError(f"partition {item.partition} has no failing strategy")
    metadata = failure_metadata(strategy)
    result: dict[str, object] = {
        "partition": item.partition,
        "status": item.status,
        "strategy": strategy.name,
        "failure": metadata,
        "diagnostics": interesting_log_lines(strategy),
        "trace": None,
        "first_divergence": None,
        "classification": "unclassified",
        "interpretation": [],
    }
    try:
        trace = choose_trace(strategy, trace_kind)
    except FileNotFoundError:
        return result

    result["trace"] = str(trace)
    divergence = first_vcd_divergence(trace, item.partition)
    result["first_divergence"] = divergence
    interpretation: list[str] = []
    if divergence:
        category = str(divergence.get("class", "unclassified"))
        result["classification"] = category
        if category == "x-init":
            interpretation.append(
                "Gold/gate X-state encoding diverges first; inspect reset, initialization, and xprop semantics before treating this as a Boolean logic mismatch."
            )
        elif category == "boolean-data":
            interpretation.append(
                "Gold/gate known data values diverge; inspect the mapped sequential/data cone and technology-cell semantics."
            )
    phase = metadata.get("phase")
    step = metadata.get("step")
    if phase == "basecase":
        suffix = f" at step {step}" if step is not None else ""
        interpretation.append(
            f"The failure is a concrete bounded counterexample in the basecase{suffix}, not a solver timeout or incomplete induction."
        )
    elif phase == "induction":
        interpretation.append(
            "The bounded basecase did not identify the first failure; inspect the induction trace and reachable-state assumptions."
        )
    result["interpretation"] = interpretation
    return result
