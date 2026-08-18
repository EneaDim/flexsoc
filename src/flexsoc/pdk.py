"""PDK catalogue, fetch, discovery, and FlexSoC activation helpers.

The generic flow consumes abstract views (Liberty + gate-level Verilog + an
OpenROAD platform name) instead of embedding foundry-specific paths in Python.
The catalogue deliberately labels real/open, predictive, and reference kits so
users do not mistake an academic PDK for a manufacturable process.
"""

from __future__ import annotations

import json
import re
import shutil
import subprocess
import urllib.request
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Iterable


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
    """Resolve only an explicit or FlexSoC-managed PDK installation.

    The historical ``pdks/<name>`` tree is deliberately *not* considered.
    Technology selection must be explicit and reproducible through
    ``.flexsoc/pdks`` (``fx pdk fetch``) or an explicit ``PDK_ROOT``
    (``fx pdk use --set PDK_ROOT=...``).  This prevents an old repository-local
    SKY130 bundle from silently influencing RTL, synthesis, or signoff.
    """

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
    """Return the functional Verilog view for the selected stdcell library.

    Open-PDKs/Ciel and IHP both place reference Verilog under a library-local
    ``verilog`` directory. Prefer aggregate library models (plus primitives)
    over thousands of per-cell files, while retaining a generic fallback for
    other prepared PDK layouts.
    """

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

    # Some libraries split helper primitives/UDPs from the aggregate cell
    # model. Keep those support views first so simulators elaborate the cell
    # model with every referenced primitive already defined.
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


def make_overrides(project_root: Path, name: str, root: str | Path | None = None) -> dict[str, str]:
    """Return PDK-dependent Make variables when usable views are available."""

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

    # Ciel exposes enabled variants at PDK_ROOT/<variant>.  FlexSoC keeps a
    # canonical family alias so existing settings remain PDK=sky130,
    # PDK_ROOT=.flexsoc/pdks/sky130 rather than leaking the Ciel variant name.
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
    """Fetch a usable managed PDK into ``.flexsoc/pdks/<name>``.

    SKY130 and GF180 are source PDKs that normally need an Open-PDKs build
    before Liberty/Verilog views are useful to downstream EDA tools.  FlexSoC
    therefore uses Ciel's pre-built Open-PDKs releases for those families.
    PDKs already distributed in prepared form continue to use a shallow Git
    clone.
    """

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
