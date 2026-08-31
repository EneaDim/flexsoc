"""Core FlexSoC context, clock, PDK, run-layout and filesystem structures."""

from __future__ import annotations

import json
import os
import re
import shutil
import subprocess
import sys
import urllib.request
from contextlib import contextmanager
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Any, Iterable, Mapping


# ---------------------------------------------------------------------------
# Clock/reset intent
# ---------------------------------------------------------------------------

@dataclass(frozen=True, slots=True)
class ClockDomain:
    """One named clock/reset domain."""

    name: str
    signal: str
    reset: str
    period_ns: float
    reset_polarity: str = "low"
    rise_ns: float = 0.0
    fall_ns: float | None = None
    source_latency_ns: float = 0.0
    setup_uncertainty_ns: float = 0.0
    hold_uncertainty_ns: float = 0.0
    transition_ns: float = 0.0

    def encode(self) -> str:
        return f"{self.name}:{self.signal}:{self.reset}:{self.period_ns:g}:{self.reset_polarity}"


@dataclass(frozen=True, slots=True)
class ClockRelationship:
    """Relationship between two named domains."""

    kind: str
    source: str
    target: str
    divide_by: int = 1

    def encode(self) -> str:
        suffix = f":{self.divide_by}" if self.kind == "generated" else ""
        return f"{self.kind}:{self.source}:{self.target}{suffix}"


@dataclass(frozen=True, slots=True)
class ClockConfig:
    """Clock domains plus explicitly declared relationships."""

    domains: tuple[ClockDomain, ...]
    relationships: tuple[ClockRelationship, ...] = ()

    @property
    def n_clocks(self) -> int:
        return len(self.domains)

    @property
    def multiclock(self) -> bool:
        return self.n_clocks > 1

    @property
    def fastest_period_ns(self) -> float:
        return min(domain.period_ns for domain in self.domains)

    def to_settings(self) -> dict[str, str]:
        """Return canonical FlexSoC clock settings."""

        return {
            "N_CLOCKS": str(self.n_clocks),
            "CLOCK_DOMAINS": ",".join(domain.encode() for domain in self.domains),
            "CLOCK_RELATIONSHIPS": ",".join(rel.encode() for rel in self.relationships),
            "CLK_PERIOD": f"{self.fastest_period_ns:g}",
        }


def _items(value: str | None) -> tuple[str, ...]:
    return tuple(item.strip() for item in (value or "").replace(";", ",").split(",") if item.strip())


def _domains(value: str) -> tuple[ClockDomain, ...]:
    domains: list[ClockDomain] = []
    for item in _items(value):
        parts = [part.strip() for part in item.split(":")]
        if len(parts) not in {4, 5}:
            raise ValueError(f"invalid CLOCK_DOMAINS entry {item!r}; expected name:clock:reset:period[:low|high]")
        name, signal, reset, period = parts[:4]
        polarity = parts[4].lower() if len(parts) == 5 else "low"
        if polarity not in {"low", "high"}:
            raise ValueError(f"invalid reset polarity {polarity!r} for clock domain {name!r}")
        try:
            period_ns = float(period)
        except ValueError as exc:
            raise ValueError(f"invalid clock period {period!r} for domain {name!r}") from exc
        if not name or not signal or not reset or period_ns <= 0:
            raise ValueError(f"invalid clock domain {item!r}")
        domains.append(ClockDomain(name, signal, reset, period_ns, polarity))
    names = [domain.name for domain in domains]
    signals = [domain.signal for domain in domains]
    if len(set(names)) != len(names) or len(set(signals)) != len(signals):
        raise ValueError("clock domain names and clock signals must be unique")
    return tuple(domains)


def _relationships(value: str, names: set[str]) -> tuple[ClockRelationship, ...]:
    relationships: list[ClockRelationship] = []
    for item in _items(value):
        parts = [part.strip() for part in item.split(":")]
        if len(parts) not in {3, 4}:
            raise ValueError(f"invalid CLOCK_RELATIONSHIPS entry {item!r}; expected kind:source:target[:divide_by]")
        kind, source, target = parts[:3]
        kind = kind.lower()
        if kind not in {"async", "sync", "generated"}:
            raise ValueError(f"invalid clock relationship kind {kind!r}")
        if source not in names or target not in names or source == target:
            raise ValueError(f"invalid clock relationship endpoints in {item!r}")
        divide_by = 1
        if kind == "generated":
            try:
                divide_by = int(parts[3]) if len(parts) == 4 else 1
            except ValueError as exc:
                raise ValueError(f"invalid generated-clock divider in {item!r}") from exc
            if divide_by <= 0:
                raise ValueError(f"generated-clock divider must be positive in {item!r}")
        elif len(parts) == 4:
            raise ValueError(f"only generated clock relationships accept a divider: {item!r}")
        relationships.append(ClockRelationship(kind, source, target, divide_by))
    return tuple(relationships)


def clock_config(values: Mapping[str, object] | None = None) -> ClockConfig:
    """Parse the canonical N_CLOCKS/CLOCK_* settings."""

    raw = {str(key).upper(): str(value) for key, value in (values or os.environ).items() if value is not None}
    domains_text = raw.get("CLOCK_DOMAINS", "").strip()
    relationships_text = raw.get("CLOCK_RELATIONSHIPS", "").strip()
    requested = int(raw.get("N_CLOCKS", "1") or "1")
    if requested < 1:
        raise ValueError("N_CLOCKS must be >= 1")

    if domains_text:
        domains = _domains(domains_text)
    elif requested == 1:
        period = float(raw.get("CLK_PERIOD", "10") or "10")
        domains = (ClockDomain("core", "clk_i", "rst_ni", period),)
    else:
        raise ValueError("CLOCK_DOMAINS is required when N_CLOCKS > 1")

    if requested != len(domains):
        raise ValueError(f"N_CLOCKS={requested} but CLOCK_DOMAINS defines {len(domains)} domain(s)")
    relationships = _relationships(relationships_text, {domain.name for domain in domains})
    return ClockConfig(domains, relationships)


# ---------------------------------------------------------------------------
# PDK catalogue, installation and discovered views
# ---------------------------------------------------------------------------

@dataclass(frozen=True, slots=True)
class PDKSpec:
    """Describe one known PDK/source bundle."""

    name: str
    title: str
    node: str
    classification: str
    source_url: str
    orfs_platform: str
    stdcell_hint: str
    driving_cell: str = ""
    note: str = ""
    fetch_provider: str = "git"
    formal_adapter_url: str = ""
    tie_hi: tuple[str, str] | None = None
    tie_lo: tuple[str, str] | None = None
    min_buffer: tuple[str, str, str] | None = None


@dataclass(frozen=True, slots=True)
class PDKViews:
    """Resolved digital views used by synthesis, GLS, EQY, STA and PnR."""

    root: Path
    liberty_typ: Path | None
    liberty_slow: Path | None
    liberty_fast: Path | None
    verilog_models: tuple[Path, ...]

    @property
    def usable(self) -> bool:
        return self.liberty_typ is not None and bool(self.verilog_models)

    def to_dict(self) -> dict[str, object]:
        return {
            "root": str(self.root),
            "usable": self.usable,
            "liberty_typ": str(self.liberty_typ) if self.liberty_typ else None,
            "liberty_slow": str(self.liberty_slow) if self.liberty_slow else None,
            "liberty_fast": str(self.liberty_fast) if self.liberty_fast else None,
            "verilog_models": [str(path) for path in self.verilog_models],
        }


PDKS: dict[str, PDKSpec] = {
    "sky130": PDKSpec(
        "sky130",
        "SkyWater SKY130",
        "130 nm",
        "open-real-preview",
        "https://github.com/google/skywater-pdk.git",
        "sky130hd",
        "sky130_fd_sc_hd",
        "sky130_fd_sc_hd__buf_1",
        "Real SkyWater process; open release is an experimental/preview PDK.",
        "ciel",
        "https://raw.githubusercontent.com/YosysHQ/eqy/6a8421db37b72826f39b560139fb95e327a63f5c/examples/spm/formal_pdk_proc.py",
        tie_hi=("sky130_fd_sc_hd__conb_1", "HI"),
        tie_lo=("sky130_fd_sc_hd__conb_1", "LO"),
        min_buffer=("sky130_fd_sc_hd__buf_4", "A", "X"),
    ),
    "gf180mcu": PDKSpec(
        "gf180mcu",
        "GlobalFoundries GF180MCU",
        "180 nm",
        "open-real-preview",
        "https://github.com/google/gf180mcu-pdk.git",
        "gf180",
        "gf180mcu_fd_sc_mcu7t5v0",
        "",
        "Real GlobalFoundries process; open release is an experimental/preview PDK.",
        "ciel",
        tie_hi=("gf180mcu_fd_sc_mcu7t5v0__tieh", "Z"),
        tie_lo=("gf180mcu_fd_sc_mcu7t5v0__tiel", "ZN"),
        min_buffer=("gf180mcu_fd_sc_mcu7t5v0__dlya_4", "I", "Z"),
    ),
    "ihp-sg13g2": PDKSpec(
        "ihp-sg13g2",
        "IHP SG13G2",
        "130 nm BiCMOS",
        "open-real-preview",
        "https://github.com/IHP-GmbH/IHP-Open-PDK.git",
        "ihp-sg13g2",
        "sg13g2_stdcell",
        "sg13g2_buf_1",
        "Real IHP process; open release is currently a preview.",
        tie_hi=("sg13g2_tiehi", "L_HI"),
        tie_lo=("sg13g2_tielo", "L_LO"),
        min_buffer=("sg13g2_buf_1", "A", "X"),
    ),
    "asap7": PDKSpec(
        "asap7",
        "ASAP7 predictive PDK",
        "7 nm",
        "predictive-academic",
        "https://github.com/The-OpenROAD-Project/asap7.git",
        "asap7",
        "asap7",
        "BUFx2_ASAP7_75t_R",
        "Predictive research PDK; resulting designs are not manufacturable.",
        tie_hi=("TIEHIx1_ASAP7_75t_R", "H"),
        tie_lo=("TIELOx1_ASAP7_75t_R", "L"),
        min_buffer=("BUFx2_ASAP7_75t_R", "A", "Y"),
    ),
    "nangate45": PDKSpec(
        "nangate45",
        "Nangate45 / FreePDK45",
        "45 nm",
        "reference-academic",
        "https://github.com/The-OpenROAD-Project/OpenROAD-flow-scripts.git",
        "nangate45",
        "NangateOpenCellLibrary",
        "BUF_X1",
        "Reference/academic platform, not a foundry production PDK.",
        tie_hi=("LOGIC1_X1", "Z"),
        tie_lo=("LOGIC0_X1", "Z"),
        min_buffer=("BUF_X1", "A", "Z"),
    ),
}

ALIASES = {
    "sky130hd": "sky130",
    "sky130hs": "sky130",
    "gf180": "gf180mcu",
    "sg13g2": "ihp-sg13g2",
    "ihp": "ihp-sg13g2",
    "freepdk45": "nangate45",
}

CIEL_DEFAULT_VARIANTS = {
    "sky130": "sky130A",
    "gf180mcu": "gf180mcuD",
}


def normalize_name(name: str) -> str:
    """Return the canonical catalogue key."""

    key = name.strip().lower()
    key = ALIASES.get(key, key)
    if key not in PDKS:
        raise ValueError(f"unknown PDK {name!r}; choose one of: {', '.join(PDKS)}")
    return key


def spec(name: str) -> PDKSpec:
    """Return one canonical PDK specification."""

    return PDKS[normalize_name(name)]


def default_root(project_root: Path, name: str) -> Path:
    """Return the ignored project-local cache root for one fetched PDK."""

    return project_root / ".flexsoc" / "pdks" / normalize_name(name)


def legacy_root(project_root: Path, name: str) -> Path:
    """Return the pre-abstraction bundled-PDK location for migration only."""

    return project_root / "pdks" / normalize_name(name)


def installed_root(project_root: Path, name: str, root: str | Path | None = None) -> Path:
    """Resolve only an explicit or FlexSoC-managed PDK installation."""

    if root:
        return Path(root).expanduser().resolve()
    return default_root(project_root, name).expanduser().resolve()


def _files(root: Path, suffixes: Iterable[str]) -> list[Path]:
    wanted = {suffix.lower() for suffix in suffixes}
    return sorted(
        path.resolve()
        for path in root.rglob("*")
        if path.is_file() and path.suffix.lower() in wanted
    )


def _score_lib(path: Path, hint: str, kind: str) -> tuple[int, int, str]:
    text = path.as_posix().lower()
    name = path.name.lower()
    score = 0
    if hint.lower() in text:
        score += 20
    tokens = {
        "typ": ("typ", "typical", "_tt", "tt_", "nom"),
        "slow": ("slow", "_ss", "ss_", "worst"),
        "fast": ("fast", "_ff", "ff_", "best"),
    }[kind]
    if any(token in name for token in tokens):
        score += 15
    if "lib" in path.parts:
        score += 2
    # Prefer uncompressed Liberty when both are present and smaller paths.
    return (score, -len(path.parts), path.as_posix())


def _pick_lib(libs: list[Path], hint: str, kind: str) -> Path | None:
    if not libs:
        return None
    ranked = sorted(libs, key=lambda path: _score_lib(path, hint, kind), reverse=True)
    best = ranked[0]
    # A slow/fast view is optional. Do not silently call a typical file a corner.
    if kind != "typ" and _score_lib(best, hint, kind)[0] < 15:
        return None
    return best


def _stdcell_verilog_models(root: Path, hint: str) -> tuple[Path, ...]:
    """Return the functional Verilog view for the selected stdcell library."""

    hint_l = hint.lower()
    direct = [
        root / "libs.ref" / hint / "verilog",
        root / hint / "verilog",
        *(root.glob(f"*/libs.ref/{hint}/verilog")),
    ]
    directories = [path.resolve() for path in direct if path.is_dir()]
    if not directories:
        directories = sorted(
            path.resolve()
            for path in root.rglob("verilog")
            if path.is_dir() and hint_l in path.as_posix().lower()
        )
    candidates: list[Path] = []
    for directory in directories:
        candidates.extend(
            sorted(
                path.resolve()
                for path in directory.iterdir()
                if path.is_file() and path.suffix.lower() in {".v", ".sv"}
            )
        )

    # Legacy compact FlexSoC bundles used PDK_ROOT/verilog directly.
    compact = root / "verilog"
    if compact.is_dir():
        candidates.extend(
            path.resolve()
            for path in sorted(compact.iterdir())
            if path.is_file() and path.suffix.lower() in {".v", ".sv"}
        )

    unique = list(dict.fromkeys(candidates))
    functional = [path for path in unique if "blackbox" not in path.name.lower()]
    if not functional:
        return ()

    # Some libraries split helper primitives/UDPs from the aggregate cell model.
    # Keep support views first so every referenced primitive is already defined.
    support = [
        path
        for path in functional
        if path.name.lower() == "primitives.v"
        or "udp" in path.stem.lower()
    ]
    preferred_names = (
        f"{hint}.v",
        f"{hint}.functional.v",
        f"{hint}.no_tc.v",
    )
    aggregate = [
        path
        for name in preferred_names
        for path in functional
        if path.name.lower() == name.lower()
    ]
    preferred = support + aggregate
    return tuple(dict.fromkeys(preferred or functional))


def discover_views(root: Path, name: str) -> PDKViews:
    """Discover Liberty and functional standard-cell Verilog views."""

    root = root.expanduser().resolve()
    item = spec(name)
    if not root.is_dir():
        return PDKViews(root, None, None, None, ())

    libs = _files(root, (".lib",))
    hint = item.stdcell_hint.lower()
    hinted_libs = [path for path in libs if hint in path.as_posix().lower()] or libs
    models = _stdcell_verilog_models(root, item.stdcell_hint)

    return PDKViews(
        root=root,
        liberty_typ=_pick_lib(hinted_libs, item.stdcell_hint, "typ"),
        liberty_slow=_pick_lib(hinted_libs, item.stdcell_hint, "slow"),
        liberty_fast=_pick_lib(hinted_libs, item.stdcell_hint, "fast"),
        verilog_models=models,
    )


def pdk_settings(project_root: Path, name: str, root: str | Path | None = None) -> dict[str, str]:
    """Return PDK-dependent FlexSoC settings for discovered views."""

    item = spec(name)
    install = installed_root(project_root, item.name, root)
    views = discover_views(install, item.name)
    values = {
        "PDK": item.name,
        "PDK_ROOT": str(views.root),
        "PDK_CLASS": item.classification,
        "ORS_TECH": item.orfs_platform,
        "DRIVING_CELL": item.driving_cell,
    }
    if item.tie_hi:
        values["TIEHI_CELL_AND_PORT"] = " ".join(item.tie_hi)
    if item.tie_lo:
        values["TIELO_CELL_AND_PORT"] = " ".join(item.tie_lo)
    if item.min_buffer:
        values["MIN_BUF_CELL_AND_PORTS"] = " ".join(item.min_buffer)
    if views.liberty_typ:
        values["LIB_SYN"] = str(views.liberty_typ)
    corners = [path for path in (views.liberty_slow, views.liberty_typ, views.liberty_fast) if path]
    if corners:
        values["LIBS"] = " ".join(str(path) for path in dict.fromkeys(corners))
    if views.verilog_models:
        values["PRIM"] = " ".join(str(path) for path in views.verilog_models)
    adapter = formal_adapter_path(project_root, item.name)
    if adapter is not None and adapter.is_file():
        values["FORMAL_PDK_PROC"] = str(adapter)
    return values



def formal_adapter_path(project_root: Path, name: str) -> Path | None:
    """Return the managed formal adapter path for a PDK when one is defined."""

    item = spec(name)
    if not item.formal_adapter_url:
        return None
    return (
        project_root.expanduser().resolve()
        / ".flexsoc"
        / "pdks"
        / ".flexsoc-tools"
        / item.name
        / "formal_pdk_proc.py"
    )


def _fetch_formal_adapter(project_root: Path, item: PDKSpec, install: Path) -> Path | None:
    """Fetch a pinned EQY cell-model adapter alongside the managed PDK."""

    path = formal_adapter_path(project_root, item.name)
    if path is None:
        return None
    try:
        with urllib.request.urlopen(item.formal_adapter_url, timeout=30) as response:
            data = response.read()
    except OSError as exc:
        raise ValueError(
            f"failed to fetch formal adapter for {item.name}: {item.formal_adapter_url}\n{exc}"
        ) from exc
    marker = b"Preprocessor for formal-friendly Verilog models for the SkyWater PDK"
    if marker not in data:
        raise ValueError(
            f"unexpected formal adapter content for {item.name}: {item.formal_adapter_url}"
        )
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_suffix(".tmp")
    temp.write_bytes(data)
    temp.chmod(0o755)
    temp.replace(path)
    metadata = fetch_metadata(install)
    metadata["formal_adapter"] = {
        "path": str(path),
        "source_url": item.formal_adapter_url,
    }
    _write_fetch_metadata(install, metadata)
    return path

def _fetch_metadata_path(root: Path) -> Path:
    """Return metadata location without modifying a Ciel-managed PDK tree."""

    if root.is_symlink():
        return root.parent / ".flexsoc-pdk-meta" / f"{root.name}.json"
    return root / ".flexsoc-pdk.json"


def _write_fetch_metadata(root: Path, data: dict[str, object]) -> None:
    path = _fetch_metadata_path(root)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(
        json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


def _remove_path(path: Path) -> None:
    """Remove a file/symlink/tree without following symlink targets."""

    if path.is_symlink() or path.is_file():
        path.unlink()
    elif path.exists():
        shutil.rmtree(path)


def fetch_metadata(root: Path) -> dict[str, object]:
    """Read FlexSoC fetch metadata when available."""

    path = _fetch_metadata_path(root)
    if not path.is_file():
        return {}
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return {}
    return data if isinstance(data, dict) else {}


def _ciel_executable() -> str:
    """Return the Ciel executable or raise an actionable error."""

    executable = shutil.which("ciel")
    if executable:
        return executable
    raise ValueError(
        "Ciel is required to fetch prepared SKY130/GF180 digital PDKs. "
        "Install it with `python -m pip install --upgrade 'ciel>=2.3.1'`, "
        "then rerun `fx pdk fetch <pdk> --force`."
    )


def _run_ciel(command: list[str]) -> subprocess.CompletedProcess[str]:
    """Run Ciel and convert CLI failures into actionable FlexSoC errors."""

    result = subprocess.run(command, check=False, text=True, capture_output=True)
    if result.returncode != 0:
        detail = (result.stderr or result.stdout).strip()
        rendered = " ".join(command)
        raise ValueError(
            f"Ciel command failed ({result.returncode}): {rendered}"
            + (f"\n{detail}" if detail else "")
        )
    return result


def _latest_ciel_version(executable: str, pdk_root: Path, family: str) -> str:
    """Return the newest pre-built PDK revision reported by Ciel."""

    command = [
        executable,
        "ls-remote",
        "--pdk-root",
        str(pdk_root),
        "--pdk-family",
        family,
    ]
    result = _run_ciel(command)
    matches = re.findall(r"\b([0-9a-f]{40})\b", result.stdout, flags=re.IGNORECASE)
    if not matches:
        raise ValueError(
            f"Ciel did not report a pre-built revision for {family}; "
            f"run `ciel ls-remote --pdk-root {pdk_root} --pdk-family {family}` "
            "to inspect availability."
        )
    return matches[0]


def _fetch_with_ciel(
    project_root: Path,
    item: PDKSpec,
    *,
    force: bool,
    version: str | None,
) -> Path:
    """Install one Open-PDKs build under the FlexSoC-managed PDK root."""

    executable = _ciel_executable()
    pdk_root = project_root / ".flexsoc" / "pdks"
    dest = default_root(project_root, item.name)
    if dest.exists() or dest.is_symlink():
        if not force:
            raise ValueError(f"PDK path already exists: {dest}; use --force to replace it")
        _remove_path(dest)
    pdk_root.mkdir(parents=True, exist_ok=True)
    selected = version or _latest_ciel_version(executable, pdk_root, item.name)
    if not re.fullmatch(r"[0-9a-fA-F]{40}", selected):
        raise ValueError(
            f"invalid Ciel PDK revision {selected!r}; expected a 40-character commit hash"
        )
    command = [
        executable,
        "enable",
        "--pdk-root",
        str(pdk_root),
        "--pdk-family",
        item.name,
        selected,
    ]
    _run_ciel(command)

    variant_name = CIEL_DEFAULT_VARIANTS.get(item.name)
    variant = pdk_root / variant_name if variant_name else None
    if variant is None or not variant.exists():
        raise ValueError(
            f"Ciel enabled {item.name} but the expected default variant "
            f"{variant_name or '<unknown>'} was not created under {pdk_root}"
        )

    # Ciel exposes variants below PDK_ROOT; FlexSoC keeps a stable family alias.
    # This avoids leaking variant names such as sky130A into project settings.
    dest.symlink_to(variant.name, target_is_directory=True)
    _write_fetch_metadata(
        dest,
        {
            "name": item.name,
            "provider": "ciel",
            "revision": selected.lower(),
            "variant": variant.name,
            "pdk_root": str(pdk_root.resolve()),
        },
    )
    return dest


def fetch(
    project_root: Path,
    name: str,
    *,
    force: bool = False,
    version: str | None = None,
) -> Path:
    """Fetch a usable managed PDK into ``.flexsoc/pdks/<name>``."""

    item = spec(name)
    if item.fetch_provider == "ciel":
        dest = _fetch_with_ciel(
            project_root, item, force=force, version=version
        )
        _fetch_formal_adapter(project_root, item, dest)
        return dest

    if version:
        raise ValueError(
            f"PDK_VERSION is only supported for Ciel-managed PDKs; {item.name} uses Git"
        )
    dest = default_root(project_root, item.name)
    if dest.exists():
        if not force:
            raise ValueError(f"PDK path already exists: {dest}; use --force to replace it")
        shutil.rmtree(dest)
    dest.parent.mkdir(parents=True, exist_ok=True)
    command = ["git", "clone", "--depth", "1"]
    if item.name in {"ihp-sg13g2", "asap7"}:
        command += ["--recurse-submodules", "--shallow-submodules"]
    command += [item.source_url, str(dest)]
    subprocess.run(command, check=True)
    _write_fetch_metadata(
        dest,
        {
            "name": item.name,
            "provider": "git",
            "source_url": item.source_url,
        },
    )
    _fetch_formal_adapter(project_root, item, dest)
    return dest


def describe(project_root: Path, name: str, root: str | Path | None = None) -> dict[str, object]:
    """Return catalogue metadata plus discovered local view status."""

    item = spec(name)
    install = installed_root(project_root, item.name, root)
    legacy = legacy_root(project_root, item.name).expanduser().resolve()
    adapter = formal_adapter_path(project_root, item.name)
    return {
        **asdict(item),
        "views": discover_views(install, item.name).to_dict(),
        "fetch": fetch_metadata(install),
        "formal_adapter": str(adapter) if adapter is not None and adapter.is_file() else None,
        "formal_adapter_required": bool(item.formal_adapter_url),
        "legacy_root": str(legacy),
        "legacy_present": legacy.is_dir(),
    }


def list_data(project_root: Path) -> list[dict[str, object]]:
    """Return every catalogue row with local install status."""

    return [describe(project_root, name) for name in PDKS]


def json_text(data: object) -> str:
    """Render stable JSON for CLI/tests."""

    return json.dumps(data, indent=2, sort_keys=True)


def _slug(value: str) -> str:
    """Return a safe deterministic directory component."""

    text = re.sub(r"[^A-Za-z0-9_.-]+", "_", str(value).strip())
    text = text.strip("._")
    if not text or text in {".", ".."}:
        raise ValueError(f"invalid path component {value!r}")
    return text


def run_root(workspace: Path, *, run_top: str, run_id: str) -> Path:
    """Return the PDK-independent root for one logical run."""

    return workspace.expanduser().resolve() / "runs" / _slug(run_top) / _slug(run_id)


# ---------------------------------------------------------------------------
# Canonical run and PDK-scoped artifact layout
# ---------------------------------------------------------------------------

@dataclass(frozen=True, slots=True)
class PDKRunLayout:
    """Technology-dependent artifact locations for one selected PDK."""

    run_root: Path
    pdk: str
    top: str

    @property
    def syn_dir(self) -> Path:
        return self.run_root / "syn" / self.pdk

    @property
    def synthesis_log_dir(self) -> Path:
        return self.run_root / "logs" / "synthesis" / self.pdk

    @property
    def signoff_pdk_root(self) -> Path:
        return self.signoff_root / self.pdk

    def signoff_stage_root(self, stage: str) -> Path:
        """Return the stage-specific sign-off root without moving post-synthesis outputs."""

        if stage == "post_syn":
            return self.signoff_pdk_root
        if stage in {"post_route", "post_pnr"}:
            return self.signoff_pdk_root / "post_pnr"
        raise ValueError(f"unsupported sign-off stage: {stage}")

    def signoff_stage_log_root(self, stage: str) -> Path:
        """Return the matching stage-specific sign-off log root."""

        root = self.run_root / "logs" / "signoff" / self.pdk
        if stage == "post_syn":
            return root
        if stage in {"post_route", "post_pnr"}:
            return root / "post_pnr"
        raise ValueError(f"unsupported sign-off stage: {stage}")

    @property
    def equivalence_dir(self) -> Path:
        return self.signoff_pdk_root / "equivalence" / "rtl_vs_syn"

    @property
    def equivalence_log(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "equivalence" / f"{self.top}_rtl_vs_syn.log"

    @property
    def post_syn_sim_dir(self) -> Path:
        return self.run_root / "dv" / "functional" / "sim" / "post_syn" / self.pdk

    @property
    def post_pnr_sim_dir(self) -> Path:
        return self.run_root / "dv" / "functional" / "sim" / "post_pnr" / self.pdk

    @property
    def post_syn_log_dir(self) -> Path:
        return self.run_root / "logs" / "dv" / "functional" / "post_syn" / self.pdk

    @property
    def post_pnr_log_dir(self) -> Path:
        return self.run_root / "logs" / "dv" / "functional" / "post_pnr" / self.pdk

    @property
    def pnr_dir(self) -> Path:
        """Return the physical-implementation branch for the selected PDK."""

        return self.run_root / "impl" / self.pdk

    @property
    def signoff_sdc(self) -> Path:
        """Return the single authored SDC shared by every technology stage."""

        return self.run_root / "constraints" / "design.sdc"

    @property
    def pnr_log_dir(self) -> Path:
        return self.run_root / "logs" / "pnr" / self.pdk

    @property
    def signoff_root(self) -> Path:
        return self.run_root / "signoff"

    @property
    def sta_dir(self) -> Path:
        return self.signoff_pdk_root / "sta"

    @property
    def power_dir(self) -> Path:
        return self.signoff_pdk_root / "power"

    @property
    def sdf_dir(self) -> Path:
        return self.signoff_pdk_root / "sdf"


    @property
    def fusion_dir(self) -> Path:
        return self.signoff_pdk_root / "fusion"

    @property
    def fusion_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "fusion"

    @property
    def path_view_dir(self) -> Path:
        return self.signoff_pdk_root / "path_view"

    @property
    def sta_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "sta"

    @property
    def power_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "power"

    @property
    def sdf_log_dir(self) -> Path:
        return self.run_root / "logs" / "signoff" / self.pdk / "sdf"

    @property
    def meta_dir(self) -> Path:
        return self.run_root / "meta" / self.pdk

    @property
    def command_log_dir(self) -> Path:
        return self.run_root / "logs" / "commands" / self.pdk

    def as_dict(self) -> dict[str, str]:
        """Return stable paths suitable for manifests and diagnostics."""

        return {
            "synthesis": str(self.syn_dir),
            "equivalence": str(self.equivalence_dir),
            "post_syn_sim": str(self.post_syn_sim_dir),
            "post_pnr_sim": str(self.post_pnr_sim_dir),
            "implementation": str(self.pnr_dir),
            "post_pnr_signoff": str(self.signoff_stage_root("post_route")),
            "sdc": str(self.signoff_sdc),
            "sta": str(self.sta_dir),
            "power": str(self.power_dir),
            "fusion": str(self.fusion_dir),
            "sdf": str(self.sdf_dir),
            "path_view": str(self.path_view_dir),
            "meta": str(self.meta_dir),
        }


def pdk_run_layout(run_dir: Path, *, pdk: str, top: str) -> PDKRunLayout:
    """Build the canonical PDK-scoped layout below an existing run root."""

    return PDKRunLayout(run_dir.expanduser().resolve(), _slug(pdk), _slug(top))


def layout_from_values(project_root: Path, values: Mapping[str, str]) -> PDKRunLayout:
    """Resolve the canonical layout from standard FlexSoC values."""

    workspace = Path(values.get("WORKSPACE", project_root / "workspace"))
    top = values.get("TOP", "test")
    run_top = values.get("RUN_TOP") or top
    run_id = values.get("RUN_ID", "default")
    pdk = values.get("PDK", "sky130")
    shared = run_root(workspace, run_top=run_top, run_id=run_id)
    return pdk_run_layout(shared, pdk=pdk, top=top)


def pdk_paths(project_root: Path, values: Mapping[str, str]) -> dict[str, str]:
    """Return canonical technology-dependent run paths as settings."""

    layout = layout_from_values(project_root, values)
    return {
        "RUN_ROOT": str(layout.run_root),
        "SIGNOFF_SDC_FILE": str(layout.signoff_sdc),
        "SYNDIR": str(layout.syn_dir),
        "SYNTH_LOGDIR": str(layout.synthesis_log_dir),
        "EQUIVDIR": str(layout.equivalence_dir),
        "EQUIV_LOG": str(layout.equivalence_log),
        "SIGNOFFDIR": str(layout.signoff_root),
        "SIGNOFF_PDK_DIR": str(layout.signoff_pdk_root),
        "SIGNOFF_STA_DIR": str(layout.sta_dir),
        "SIGNOFF_POWER_DIR": str(layout.power_dir),
        "SIGNOFF_SDF_DIR": str(layout.sdf_dir),
        "SIGNOFF_FUSION_DIR": str(layout.fusion_dir),
        "SIGNOFF_PATH_VIEW_DIR": str(layout.path_view_dir),
        "STA_LOGDIR": str(layout.sta_log_dir),
        "POWER_LOGDIR": str(layout.power_log_dir),
        "SDF_LOGDIR": str(layout.sdf_log_dir),
        "FUSION_LOGDIR": str(layout.fusion_log_dir),
        "ORSDIR": str(layout.pnr_dir),
        "OR_WORKDIR": str(layout.pnr_dir),
        "OR_LOGDIR": str(layout.pnr_log_dir),
        "POST_SYN_SIMDIR": str(layout.post_syn_sim_dir),
        "POST_LAYOUT_SIMDIR": str(layout.post_pnr_sim_dir),
        "METADIR": str(layout.meta_dir),
        "METRICS_JSON": str(layout.meta_dir / "metrics.json"),
        "MANIFEST_JSON": str(layout.meta_dir / "manifest.json"),
        "COMMAND_LOGDIR": str(layout.command_log_dir),
    }


# ---------------------------------------------------------------------------
# Generated-file and SystemVerilog helpers
# ---------------------------------------------------------------------------

def colorize(text: str, color_code: str = "\033[38;5;214m") -> str:
    """Return colored text when stdout supports color output."""

    if not sys.stdout.isatty() or os.environ.get("NO_COLOR"):
        return text
    return f"{color_code}{text}\033[0m"


def ensure_dir(path: str | os.PathLike[str]) -> None:
    """Create a directory and parents when they do not already exist."""

    Path(path).mkdir(parents=True, exist_ok=True)


def safe_write_file(
    path: str | os.PathLike[str],
    content: str,
    *,
    overwrite: bool = False,
) -> None:
    """Write text while protecting existing files unless overwrite is enabled."""

    p = Path(path)
    if p.exists() and not overwrite:
        raise FileExistsError(str(p))
    p.write_text(content, encoding="utf-8")


@contextmanager
def replace_generated_tree(path: str | os.PathLike[str]):
    """Replace one generated directory atomically, restoring it on failure."""

    tree = Path(path)
    backup = tree.with_name(f".{tree.name}.flexsoc-backup")
    if backup.exists():
        raise RuntimeError(
            f"stale generated-tree backup exists: {backup}; "
            "remove or restore it before retrying"
        )

    tree.parent.mkdir(parents=True, exist_ok=True)
    had_tree = tree.exists()
    if had_tree:
        tree.rename(backup)
    tree.mkdir(parents=True, exist_ok=False)

    try:
        yield tree
    except BaseException:
        shutil.rmtree(tree, ignore_errors=True)
        if had_tree:
            backup.rename(tree)
        raise
    else:
        if had_tree:
            shutil.rmtree(backup)


def _strip_line_comment(line: str) -> str:
    """Remove one SystemVerilog line comment from a line."""

    if "//" in line:
        return line.split("//", 1)[0]
    return line


def _read_module_header_text(sv_path: Path) -> str:
    """Return a comment-free SystemVerilog module header snippet."""

    text = sv_path.read_text(encoding="utf-8", errors="ignore")

    start = text.find("module")
    if start != -1:
        text = text[start:]

    end = text.find(");")
    if end != -1:
        text = text[: end + 2]

    out: list[str] = []
    i = 0
    in_block = False
    while i < len(text):
        if not in_block and text.startswith("/*", i):
            in_block = True
            i += 2
            continue
        if in_block and text.startswith("*/", i):
            in_block = False
            i += 2
            continue
        if not in_block:
            out.append(text[i])
        i += 1

    clean = "".join(out)
    return "\n".join(_strip_line_comment(line) for line in clean.splitlines())


def parse_sv_signature(rtldir: str | os.PathLike[str], top: str) -> dict[str, Any]:
    """Parse parameters, ports, clocks, and resets from one top module header."""

    sv = Path(rtldir) / f"{top}.sv"
    if not sv.exists():
        raise FileNotFoundError(str(sv))

    lines = _read_module_header_text(sv).splitlines()

    parameters: list[tuple[str, str]] = []
    localparams: list[tuple[str, str]] = []
    ports_in: list[tuple[str, Any]] = []
    ports_out: list[tuple[str, Any]] = []
    clks: list[str] = []
    rsts: list[str] = []

    def push_param(line: str, kind: str) -> None:
        """Append one parsed parameter or localparam line."""

        if "=" not in line:
            return
        left, right = line.split("=", 1)
        name = left.split()[-1].strip()
        value = re.sub(r"\)\s*\($", "", right.strip()).rstrip(",)")
        if kind == "parameter":
            parameters.append((name, value))
        else:
            localparams.append((name, value))

    def push_port(line: str, direction: str) -> None:
        """Append one parsed input or output port line."""

        toks = line.strip().rstrip(",)").split()
        if not toks:
            return
        if toks[0] in ("input", "output"):
            toks = toks[1:]
        if toks and toks[0] == "logic":
            toks = toks[1:]
        if not toks:
            return

        width = toks[-2] if len(toks) >= 2 else 1
        name = toks[-1].rstrip(",")

        if direction == "in":
            ports_in.append((name, width))
        else:
            ports_out.append((name, width))

        if "clk_" in name:
            clks.append(name)
        if "rst_" in name:
            rsts.append(name)

    for raw in lines:
        line = raw.strip()
        if not line:
            continue
        if "parameter" in line and "localparam" not in line:
            push_param(line, "parameter")
        elif "localparam" in line:
            push_param(line, "localparam")
        elif line.startswith("input"):
            push_port(line, "in")
        elif line.startswith("output"):
            push_port(line, "out")

    return {
        "parameters": parameters,
        "localparams": localparams,
        "ports_in": ports_in,
        "ports_out": ports_out,
        "clks": clks,
        "rsts": rsts,
    }


def has_reg_pkg(rtldir: str | os.PathLike[str], top: str) -> bool:
    """Return True when the RTL directory contains the generated register package."""

    return (Path(rtldir) / f"{top}_reg_pkg.sv").exists()


def list_hdl_files(root: str | os.PathLike[str], *, recursive: bool = True) -> list[Path]:
    """List Verilog/SystemVerilog files under a root in deterministic order."""

    rootp = Path(root)
    if not rootp.exists():
        return []

    exts = {".sv", ".svh", ".v", ".vh"}
    it: Iterable[Path]
    if recursive:
        it = rootp.rglob("*")
    else:
        it = rootp.glob("*")

    files = [p.resolve() for p in it if p.is_file() and p.suffix.lower() in exts]
    return sorted(set(files))


# ---------------------------------------------------------------------------
# RTL discovery, dependency resolution and ordered filelists
# ---------------------------------------------------------------------------

def gather_rtl_sources(root: Path) -> list[Path]:
    """Return all RTL source files under a root directory."""

    return list_hdl_files(root, recursive=True)


def find_top_sv(rtldir: str | os.PathLike[str], top: str) -> Path | None:
    """Return the top-level SystemVerilog file when it exists."""

    p = Path(rtldir) / f"{top}.sv"
    return p if p.exists() else None


def always_include_packages(ips_root: Path) -> list[Path]:
    """Canonical package order."""
    return [
        ips_root / "pkgs" / "top_pkg.sv",
        ips_root / "prim" / "prim_reg_pkg.sv",
        ips_root / "pkgs" / "prim_mubi_pkg.sv",
        ips_root / "pkgs" / "prim_secded_pkg.sv",
        ips_root / "pkgs" / "prim_subreg_pkg.sv",
        ips_root / "pkgs" / "prim_util_pkg.sv",
        ips_root / "pkgs" / "tlul_pkg.sv",
        ips_root / "pkgs" / "prim_assert.sv",
        ips_root / "pkgs" / "prim_count_pkg.sv",
        ips_root / "pkgs" / "prim_flop_macros.sv",
        ips_root / "pkgs" / "prim_alert_pkg.sv",
    ]


def candidate_ips_in_order(ips_root: Path) -> list[Path]:
    """Return backend IP support files in their canonical dependency order."""

    rel = [
        "prim/prim_bin2gray.sv",
        "prim/prim_cdc_2phase.sv",
        "prim/prim_clk_div.sv",
        "prim/prim_clk_gate.sv",
        "prim/prim_counter.sv",
        "prim/prim_deglitch.sv",
        "prim/prim_edge_detect.sv",
        "prim/prim_ff.sv",
        "prim/prim_ff_2sync.sv",
        "prim/prim_fifo.sv",
        "prim/prim_gray2bin.sv",
        "prim/prim_lifo.sv",
        "prim/prim_lzc.sv",
        "prim/prim_ram.sv",
        "prim/prim_reg.sv",
        "prim/prim_rom.sv",
        "prim/prim_rrarbiter.sv",
        "prim/prim_shreg.sv",
        "prim_opentitan/prim_arbiter_ppc.sv",
        "prim_opentitan/prim_buf.sv",
        "prim_opentitan/prim_cdc_rand_delay.sv",
        "prim_opentitan/prim_count.sv",
        "prim_opentitan/prim_diff_decode.sv",
        "prim_opentitan/prim_fifo_async.sv",
        "prim_opentitan/prim_fifo_async_simple.sv",
        "prim_opentitan/prim_fifo_async_sram_adapter.sv",
        "prim_opentitan/prim_fifo_sync.sv",
        "prim_opentitan/prim_fifo_sync_cnt.sv",
        "prim_opentitan/prim_filter.sv",
        "prim_opentitan/prim_filter_ctr.sv",
        "prim_opentitan/prim_flop.sv",
        "prim_opentitan/prim_flop_2sync.sv",
        "prim_opentitan/prim_intr_hw.sv",
        "prim_opentitan/prim_onehot_check.sv",
        "prim_opentitan/prim_pulse_sync.sv",
        "prim_opentitan/prim_reg_cdc.sv",
        "prim_opentitan/prim_reg_cdc_arb.sv",
        "prim_opentitan/prim_reg_we_check.sv",
        "prim_opentitan/prim_sec_anchor_buf.sv",
        "prim_opentitan/prim_sec_anchor_flop.sv",
        "prim_opentitan/prim_secded_inv_39_32_dec.sv",
        "prim_opentitan/prim_secded_inv_39_32_enc.sv",
        "prim_opentitan/prim_secded_inv_64_57_dec.sv",
        "prim_opentitan/prim_secded_inv_64_57_enc.sv",
        "prim_opentitan/prim_subreg.sv",
        "prim_opentitan/prim_subreg_arb.sv",
        "prim_opentitan/prim_subreg_ext.sv",
        "prim_opentitan/prim_sync_reqack.sv",
        "prim_opentitan/prim_alert_sender.sv",
        "tlul/sram2tlul.sv",
        "tlul/tlul_adapter_host.sv",
        "tlul/tlul_adapter_reg.sv",
        "tlul/tlul_adapter_sram.sv",
        "tlul/tlul_assert.sv",
        "tlul/tlul_assert_multiple.sv",
        "tlul/tlul_cmd_intg_chk.sv",
        "tlul/tlul_cmd_intg_gen.sv",
        "tlul/tlul_data_integ_dec.sv",
        "tlul/tlul_data_integ_enc.sv",
        "tlul/tlul_err.sv",
        "tlul/tlul_err_resp.sv",
        "tlul/tlul_fifo_async.sv",
        "tlul/tlul_fifo_sync.sv",
        "tlul/tlul_rsp_intg_chk.sv",
        "tlul/tlul_rsp_intg_gen.sv",
        "tlul/tlul_socket_1n.sv",
        "tlul/tlul_socket_m1.sv",
        "tlul/tlul_sram_byte.sv",
    ]
    return [ips_root / p for p in rel]


def _parse_instantiated_modules_from_sv(path: Path) -> list[str]:
    """Small multiline-aware instantiation parser."""
    try:
        text = path.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return []

    # Remove block comments
    out: list[str] = []
    i = 0
    in_block = False
    while i < len(text):
        if not in_block and text.startswith("/*", i):
            in_block = True
            i += 2
            continue
        if in_block and text.startswith("*/", i):
            in_block = False
            i += 2
            continue
        if not in_block:
            out.append(text[i])
        i += 1
    text = "".join(out)

    # Remove line comments
    text = "\n".join(line.split("//", 1)[0] for line in text.splitlines())

    rx = re.compile(
        r"(?<!\bmodule\s)"
        r"(?<!\binterface\s)"
        r"(?<!\bpackage\s)"
        r"\b(?P<mod>[A-Za-z_]\w*)\s*"
        r"(?:#\s*\([^;]*?\))?\s+"
        r"(?P<inst>[A-Za-z_]\w*)\s*"
        r"(?:\[[^\]]+\]\s*)?"
        r"\(",
        re.M | re.S,
    )

    blacklist = {
        "if",
        "for",
        "case",
        "assign",
        "always",
        "always_ff",
        "always_comb",
        "always_latch",
        "function",
        "task",
        "typedef",
        "struct",
        "union",
        "enum",
        "logic",
        "wire",
        "reg",
        "genvar",
        "begin",
        "end",
        "unique",
        "priority",
        "virtual",
        "static",
        "automatic",
        "import",
        "export",
        "assert",
        "cover",
        "property",
        "sequence",
        "bind",
        "generate",
    }

    mods: list[str] = []
    for m in rx.finditer(text):
        mod = m.group("mod")
        if mod not in blacklist:
            mods.append(mod)
    return mods


def file_contains_any_token(path: Path, tokens: Iterable[str]) -> bool:
    """Return True when a file contains any token as a standalone word."""

    try:
        text = path.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return False

    for tok in tokens:
        if re.search(rf"\b{re.escape(tok)}\b", text):
            return True
    return False


def select_used_ips_in_order(ip_candidates: list[Path], rtl_root: Path) -> list[Path]:
    """Select candidate IP files referenced by the RTL sources."""

    rtl_files = gather_rtl_sources(rtl_root)

    used: list[Path] = []
    for ip in ip_candidates:
        token = ip.stem
        if any(file_contains_any_token(rtl, (token,)) for rtl in rtl_files):
            used.append(ip)

    return used


def resolve_ip_dependencies(initial_used: list[Path], ip_candidates: list[Path]) -> list[Path]:
    """Expand the initial used IP set by following submodule instantiations recursively."""
    name_to_path = {p.stem: p for p in ip_candidates}
    used_stems = {p.stem for p in initial_used}
    queue = list(initial_used)

    while queue:
        cur = queue.pop(0)
        for sub in _parse_instantiated_modules_from_sv(cur):
            if sub in name_to_path and sub not in used_stems:
                used_stems.add(sub)
                queue.append(name_to_path[sub])

    return [p for p in ip_candidates if p.stem in used_stems]




def _read_filelist_entries(filelist: Path) -> list[Path]:
    """Read source entries from one .f file."""

    out: list[Path] = []
    if not filelist.exists():
        return out

    base = filelist.parent
    for raw in filelist.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = raw.strip()
        if not line or line.startswith("#") or line.startswith("+incdir+"):
            continue
        p = Path(line)
        if not p.is_absolute():
            p = (base / p).resolve()
        else:
            p = p.resolve()
        out.append(p)
    return out


def collect_nested_ip_sources(run_root: Path) -> list[Path]:
    """If the current run is a SoC run with loaded IPs under:"""
    ips_dir = run_root / "ips"
    if not ips_dir.exists():
        return []

    out: list[Path] = []
    seen: set[Path] = set()

    for ip_dir in sorted(p for p in ips_dir.iterdir() if p.is_dir()):
        rtl_dir = ip_dir / "rtl"
        lists = [rtl_dir / "rtl_common.f", rtl_dir / "rtl_ip.f"]

        entries: list[Path] = []
        for filelist in lists:
            entries.extend(_read_filelist_entries(filelist))
        if not entries:
            entries = _read_filelist_entries(rtl_dir / "rtl_list.f")
        if not entries:
            entries = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))

        for path in entries:
            rp = path.resolve()
            if rp not in seen and rp.exists():
                seen.add(rp)
                out.append(rp)

    return out


def build_ordered_sources(
    top: str,
    rtl_root: Path,
    ips_root: Path,
    *,
    out_file: Path | None = None,
) -> list[Path]:
    """Canonical source ordering for generated filelists:"""
    rtl_root = Path(rtl_root).resolve()
    ips_root = Path(ips_root).resolve()

    fixed_packages = always_include_packages(ips_root)
    ip_candidates = candidate_ips_in_order(ips_root)

    used_ips_seed = select_used_ips_in_order(ip_candidates, rtl_root)
    used_ips = resolve_ip_dependencies(used_ips_seed, ip_candidates)

    tail_candidates = [
        rtl_root / f"{top}_reg_pkg.sv",
        rtl_root / f"{top}_reg_top.sv",
        rtl_root / f"{top}_core.sv",
        rtl_root / f"{top}.sv",
    ]
    tail = [p for p in tail_candidates if p.exists()]

    all_rtl = gather_rtl_sources(rtl_root)

    exclude = {
        *(p.resolve() for p in fixed_packages if p.exists()),
        *(p.resolve() for p in used_ips if p.exists()),
        *(p.resolve() for p in tail),
    }

    rest = [p for p in all_rtl if p.resolve() not in exclude]
    rest_pkgs = [p for p in rest if p.name.endswith("_pkg.sv")]
    rest_others = [p for p in rest if not p.name.endswith("_pkg.sv")]
    rest_pkgs.sort(key=lambda p: p.as_posix())
    rest_others.sort(key=lambda p: p.as_posix())

    ordered: list[Path] = []

    for p in fixed_packages:
        if p.exists():
            ordered.append(p)

    for p in used_ips:
        if p.exists():
            ordered.append(p)

    ordered.extend(rest_pkgs)
    ordered.extend(rest_others)

    for p in tail:
        if p not in ordered:
            ordered.append(p)

    # Merge nested IP filelist sources while keeping SoC-local tail files last.
    run_root = rtl_root.parent
    nested_ip_sources = collect_nested_ip_sources(run_root)
    if nested_ip_sources:
        tail_resolved = [p.resolve() for p in tail]
        ordered_wo_tail = [p for p in ordered if p.resolve() not in set(tail_resolved)]
        ordered = ordered_wo_tail + nested_ip_sources + tail

    # Remove duplicate source paths while preserving the computed order.
    final: list[Path] = []
    seen: set[Path] = set()
    for p in ordered:
        rp = p.resolve()
        if rp in seen:
            continue
        seen.add(rp)
        final.append(rp)

    if out_file is not None:
        out_path = Path(out_file)
        out_path.parent.mkdir(parents=True, exist_ok=True)
        out_path.write_text("\n".join(p.as_posix() for p in final) + "\n", encoding="utf-8")

    return final


# ---------------------------------------------------------------------------
# Shared backend context and canonical flow paths
# ---------------------------------------------------------------------------

@dataclass(frozen=True, slots=True)
class BackendContext:
    """Immutable inputs shared by backend flow objects."""

    project_root: Path
    workspace: Path
    values: Mapping[str, str]

    @property
    def clocks(self) -> ClockConfig:
        return clock_config(self.values)

    @property
    def layout(self) -> PDKRunLayout:
        return layout_from_values(self.project_root, self.values)

    @property
    def paths(self) -> "FlowPaths":
        """Return canonical non-technology and technology run paths."""
        return flow_paths(self.project_root, self.workspace, self.values)


class PdkManager:
    """Object-oriented facade for PDK catalogue, fetch, activation and views."""

    def __init__(self, project_root: Path):
        self.project_root = Path(project_root).resolve()

    def list(self) -> list[dict[str, object]]:
        return list_data(self.project_root)

    def info(self, name: str, root: str | Path | None = None) -> dict[str, object]:
        return describe(self.project_root, name, root)

    def fetch(self, name: str, *, force: bool = False, version: str | None = None) -> Path:
        return fetch(self.project_root, name, force=force, version=version)

    def use(self, name: str, root: str | Path | None = None) -> dict[str, str]:
        return pdk_settings(self.project_root, name, root)

    def views(self, name: str, root: str | Path | None = None) -> PDKViews:
        canonical = normalize_name(name)
        path = Path(root).expanduser().resolve() if root else default_root(self.project_root, canonical)
        return discover_views(path, canonical)


@dataclass(frozen=True, slots=True)
class FlowPaths:
    """Canonical project/run paths shared by all backend domains."""

    project_root: Path
    workspace: Path
    top: str
    run_top: str
    run_id: str
    pdk: str

    @property
    def run(self) -> Path: return self.workspace / "runs" / self.run_top / self.run_id
    @property
    def data(self) -> Path: return self.run / "data"
    @property
    def rtl(self) -> Path: return self.run / "rtl"
    @property
    def doc(self) -> Path: return self.run / "doc"
    @property
    def drivers(self) -> Path: return self.run / "drivers"
    @property
    def logs(self) -> Path: return self.run / "logs"
    @property
    def dv(self) -> Path: return self.run / "dv"
    @property
    def functional(self) -> Path: return self.dv / "functional"
    @property
    def model(self) -> Path: return self.functional / "model"
    @property
    def tests(self) -> Path: return self.functional / "tests"
    @property
    def tb(self) -> Path: return self.functional / "tb"
    @property
    def sim(self) -> Path: return self.functional / "sim"
    @property
    def coverage(self) -> Path: return self.functional / "coverage"
    @property
    def formal(self) -> Path: return self.dv / "formal"
    @property
    def constraints(self) -> Path: return self.run / "constraints"
    @property
    def syn(self) -> Path: return self.run / "syn" / self.pdk
    @property
    def signoff(self) -> Path: return self.run / "signoff" / self.pdk
    @property
    def impl(self) -> Path: return self.run / "impl" / self.pdk
    @property
    def meta(self) -> Path: return self.run / "meta" / self.pdk

    @property
    def rtl_common(self) -> Path: return self.rtl / "rtl_common.f"
    @property
    def rtl_ip(self) -> Path: return self.rtl / "rtl_ip.f"
    @property
    def sdc(self) -> Path: return self.constraints / "design.sdc"
    @property
    def metrics(self) -> Path: return self.meta / "metrics.json"
    @property
    def manifest(self) -> Path: return self.meta / "manifest.json"

    def ensure(self) -> "FlowPaths":
        """Create the canonical run directories and return this layout."""
        for path in (
            self.data, self.rtl, self.doc, self.drivers, self.logs,
            self.model, self.tests, self.tb, self.sim, self.coverage,
            self.formal, self.constraints, self.syn, self.signoff, self.impl, self.meta,
        ):
            path.mkdir(parents=True, exist_ok=True)
        return self


def flow_paths(project_root: Path, workspace: Path, values: Mapping[str, str]) -> FlowPaths:
    """Build the canonical path view for one configured run."""
    top = values.get("TOP", "test")
    return FlowPaths(
        Path(project_root).resolve(), Path(workspace).resolve(), top,
        values.get("RUN_TOP", top), values.get("RUN_ID", "default"),
        values.get("PDK", "sky130"),
    )
