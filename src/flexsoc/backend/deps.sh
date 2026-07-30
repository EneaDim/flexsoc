#!/usr/bin/env bash
set -euo pipefail

HERE=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
LOCK=${FLEXSOC_TOOLCHAIN_LOCK:-"$HERE/toolchain.lock"}
[[ -f "$LOCK" ]] || { echo "ERROR: missing toolchain lock: $LOCK" >&2; exit 2; }
# shellcheck disable=SC1090
source "$LOCK"

MODE=user
PROFILE=base
JOBS=${FLEXSOC_JOBS:-$(nproc 2>/dev/null || echo 2)}
FORCE=0

usage() {
    cat <<'TXT'
Usage: deps.sh COMMAND [options]

Commands:
  bootstrap              Check/install host build prerequisites
  install                Install one pinned FlexSoC tool profile
  doctor                 Verify one installed profile
  env                    Print shell exports for the selected toolchain
  versions               Print locked versions grouped by profile

Options:
  --user                  Rootless toolchain under ~/.local/share/flexsoc (default)
  --system                Shared toolchain under /opt/flexsoc
  --profile base|impl|riscv
  --jobs N                Parallel build jobs
  --force                 Rebuild selected tools

Profiles:
  base    DV, synthesis, formal, STA and waveform/debug tooling
  impl    Physical implementation tooling (reserved until pinned)
  riscv   RISC-V GNU toolchain (reserved until pinned)

Bootstrap:
  --user    checks host prerequisites only; never invokes sudo/apt
  --system  installs Debian/Ubuntu prerequisites; intended for Docker/shared hosts
TXT
}

die() { echo "ERROR: $*" >&2; exit 2; }
info() { printf '\033[38;5;214m[deps]\033[0m %s\n' "$*" >&2; }

sha256_file() {
    if command -v sha256sum >/dev/null 2>&1; then sha256sum "$1" | awk '{print $1}'
    else shasum -a 256 "$1" | awk '{print $1}'; fi
}

LOCK_HASH=$(sha256_file "$LOCK")
TOOLCHAIN_ID=${LOCK_HASH:0:12}

parse_options() {
    while [[ $# -gt 0 ]]; do
        case "$1" in
            --user) MODE=user ;;
            --system) MODE=system ;;
            --profile) [[ $# -ge 2 ]] || die "--profile needs a value"; PROFILE=$2; shift ;;
            --jobs) [[ $# -ge 2 ]] || die "--jobs needs a value"; JOBS=$2; shift ;;
            --force) FORCE=1 ;;
            -h|--help) usage; exit 0 ;;
            *) die "unknown option: $1" ;;
        esac
        shift
    done
    [[ "$PROFILE" =~ ^(base|impl|riscv)$ ]] || die "profile must be base, impl, or riscv"
    [[ "$JOBS" =~ ^[1-9][0-9]*$ ]] || die "--jobs must be a positive integer"
}

paths() {
    if [[ "$MODE" == system ]]; then
        PREFIX=${FLEXSOC_TOOLCHAIN_ROOT:-/opt/flexsoc/toolchains}/$TOOLCHAIN_ID
        CACHE=${FLEXSOC_CACHE_HOME:-/var/cache/flexsoc}
    else
        PREFIX=${FLEXSOC_TOOLCHAIN_ROOT:-${XDG_DATA_HOME:-$HOME/.local/share}/flexsoc/toolchains}/$TOOLCHAIN_ID
        CACHE=${FLEXSOC_CACHE_HOME:-${XDG_CACHE_HOME:-$HOME/.cache}/flexsoc}
    fi
    SRC="$CACHE/src"; DOWNLOADS="$CACHE/downloads"; MARKERS="$PREFIX/.flexsoc"
}

as_root() {
    if [[ $(id -u) -eq 0 ]]; then "$@"
    elif command -v sudo >/dev/null 2>&1; then sudo "$@"
    else die "root privileges required: $*"; fi
}

BASE_PACKAGES=(
    autoconf automake bison build-essential ca-certificates cmake curl flex gawk git gperf
    graphviz haskell-stack help2man libbz2-dev libeigen3-dev libffi-dev libfl-dev libgmp-dev
    libgtk-3-dev libjudy-dev liblz4-dev liblzma-dev libmpfr-dev libreadline-dev libtool
    libtool-bin m4 meson ninja-build nodejs npm perl pkg-config python3 swig tcl-dev tk-dev
    unzip xdot zlib1g-dev
)

BASE_COMMANDS=(
    gcc g++ make autoconf automake bison flex gawk git gperf cmake curl help2man libtoolize
    m4 meson ninja node npm perl pkg-config python3 stack swig tclsh unzip dot xdot
)
BASE_LIB_PACKAGES=(
    libbz2-dev libeigen3-dev libffi-dev libfl-dev libgmp-dev libgtk-3-dev libjudy-dev
    liblz4-dev liblzma-dev libmpfr-dev libreadline-dev tcl-dev tk-dev zlib1g-dev
)

profile_ready() {
    case "$PROFILE" in
        base) return 0 ;;
        impl) die "impl profile is reserved until OpenROAD/KLayout revisions are pinned" ;;
        riscv) die "riscv profile is reserved until the RISC-V GNU toolchain revision is pinned" ;;
    esac
}

host_packages() { profile_ready; printf '%s\n' "${BASE_PACKAGES[@]}"; }

check_prereqs() {
    profile_ready
    local missing=() cmd pkg
    for cmd in "${BASE_COMMANDS[@]}"; do command -v "$cmd" >/dev/null 2>&1 || missing+=("command:$cmd"); done
    if command -v dpkg-query >/dev/null 2>&1; then
        for pkg in "${BASE_LIB_PACKAGES[@]}"; do
            dpkg-query -W -f='${Status}' "$pkg" 2>/dev/null | grep -q 'install ok installed' || missing+=("package:$pkg")
        done
    fi
    if [[ ${#missing[@]} -eq 0 ]]; then info "$PROFILE host prerequisites: PASS"; return 0; fi
    echo "Missing host prerequisites for profile '$PROFILE':" >&2
    printf '  %s\n' "${missing[@]}" >&2
    echo >&2
    echo "User mode is rootless and never installs system packages." >&2
    echo "Install them yourself, use 'bootstrap --system', or use the FlexSoC Docker image." >&2
    return 2
}

bootstrap() {
    profile_ready
    if [[ "$MODE" == user ]]; then info "rootless prerequisite check: $PROFILE"; check_prereqs; return; fi
    command -v apt-get >/dev/null 2>&1 || die "system bootstrap currently supports Debian/Ubuntu only"
    mapfile -t packages < <(host_packages)
    info "install Ubuntu prerequisites: $PROFILE"
    as_root apt-get update
    as_root apt-get install -y --no-install-recommends "${packages[@]}"
}

var() { local name="${1}_${2}"; printf '%s' "${!name-}"; }
version_var() { var "$1" VERSION; }
source_id() { local v; v=$(var "$1" REF); [[ -n "$v" ]] || v=$(var "$1" SHA256); printf '%s' "$v"; }

checkout() {
    local key=$1 name=$2 ref repo dir actual
    ref=$(var "$key" REF); repo=$(var "$key" REPO)
    [[ -n "$ref" && -n "$repo" ]] || die "$key needs REPO and REF in toolchain.lock"
    dir="$SRC/$name-$ref"
    if [[ ! -d "$dir/.git" ]]; then
        info "fetch $name @ ${ref:0:12}"
        rm -rf "$dir"; mkdir -p "$dir"
        git -C "$dir" init -q; git -C "$dir" remote add origin "$repo"
        git -C "$dir" fetch -q --depth 1 origin "$ref" || git -C "$dir" fetch -q origin
        git -C "$dir" checkout -q --detach "$ref"
        git -C "$dir" submodule update -q --init --recursive
    fi
    actual=$(git -C "$dir" rev-parse HEAD)
    [[ "$actual" == "$ref" ]] || die "$name source mismatch: expected $ref, got $actual"
    printf '%s\n' "$dir"
}

cached_archive() {
    local key=$1 name=$2 version url expected kind archive actual
    version=$(version_var "$key"); url=$(var "$key" URL); expected=$(var "$key" SHA256)
    kind=$(var "$key" ARCHIVE); [[ -n "$kind" ]] || kind=tar.gz
    [[ -n "$url" && -n "$expected" ]] || die "$key needs URL and SHA256 in toolchain.lock"
    mkdir -p "$DOWNLOADS"; archive="$DOWNLOADS/$name-$version.$kind"
    if [[ ! -f "$archive" || $(sha256_file "$archive") != "$expected" ]]; then
        info "download $name $version"; rm -f "$archive"
        curl --fail --location --retry 3 "$url" -o "$archive"
    fi
    actual=$(sha256_file "$archive")
    [[ "$actual" == "$expected" ]] || die "$name archive mismatch: expected $expected, got $actual"
    printf '%s\n' "$archive"
}

archive_source() {
    local key=$1 name=$2 version expected kind archive dir
    version=$(version_var "$key"); expected=$(var "$key" SHA256)
    kind=$(var "$key" ARCHIVE); [[ -n "$kind" ]] || kind=tar.gz
    archive=$(cached_archive "$key" "$name")
    mkdir -p "$SRC"; dir="$SRC/$name-$version-${expected:0:12}"
    if [[ ! -f "$dir/.flexsoc-source" || "$FORCE" == 1 ]]; then
        rm -rf "$dir"; mkdir -p "$dir"
        case "$kind" in
            tar.gz) tar -xzf "$archive" --strip-components=1 -C "$dir" ;;
            zip) unzip -q "$archive" -d "$dir" ;;
            *) die "unsupported archive type: $kind" ;;
        esac
        printf '%s\n' "$expected" > "$dir/.flexsoc-source"
    fi
    printf '%s\n' "$dir"
}

prepare_git_source() {
    [[ "$FORCE" == 1 ]] || return 0
    git -C "$1" reset -q --hard HEAD; git -C "$1" clean -q -fdx
    git -C "$1" submodule foreach -q --recursive \
        'git reset --hard HEAD >/dev/null; git clean -fdx >/dev/null' || true
}

installed() {
    local key=$1 name=$2 marker
    marker="$MARKERS/$name.source"
    [[ "$FORCE" == 0 && -f "$marker" && $(cat "$marker") == "$(source_id "$key")" ]]
}
mark_installed() { mkdir -p "$MARKERS"; printf '%s\n' "$(source_id "$1")" > "$MARKERS/$2.source"; }

install_verilator() {
    installed VERILATOR verilator && { info "verilator already installed"; return; }
    local d; d=$(checkout VERILATOR verilator); prepare_git_source "$d"
    info "build verilator $(version_var VERILATOR)"
    (cd "$d"; unset VERILATOR_ROOT; autoconf; ./configure --prefix="$PREFIX"; make -j"$JOBS"; make install)
    mark_installed VERILATOR verilator
}

install_slang() {
    installed SLANG slang && { info "slang already installed"; return; }
    local d b; d=$(checkout SLANG slang); prepare_git_source "$d"; b="$d/build-flexsoc"
    info "build slang $(version_var SLANG)"
    cmake -S "$d" -B "$b" -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$PREFIX" \
        -DSLANG_INCLUDE_TESTS=OFF -DSLANG_INCLUDE_PYLIB=OFF -DSLANG_INCLUDE_DOCS=OFF -DSLANG_USE_MIMALLOC=OFF
    cmake --build "$b" --parallel "$JOBS"; cmake --install "$b" --strip
    mark_installed SLANG slang
}

install_iverilog() {
    installed IVERILOG iverilog && { info "iverilog already installed"; return; }
    local d; d=$(archive_source IVERILOG iverilog); info "build iverilog $(version_var IVERILOG)"
    (cd "$d"; ./configure --prefix="$PREFIX" --enable-libvvp --enable-libveriuser; make -j"$JOBS"; make install)
    mark_installed IVERILOG iverilog
}

install_yosys() {
    installed YOSYS yosys && { info "yosys already installed"; return; }
    local d b boost_archive
    d=$(checkout YOSYS yosys); prepare_git_source "$d"; b="$d/build-flexsoc"
    boost_archive=$(cached_archive BOOST boost)
    info "build yosys $(version_var YOSYS) with temporary Boost $(version_var BOOST) headers"
    (
        tmp=$(mktemp -d); printf -v cleanup 'rm -rf -- %q' "$tmp"; trap "$cleanup" EXIT
        boost_src="$tmp/boost"; mkdir -p "$boost_src"
        tar -xzf "$boost_archive" -C "$boost_src" --strip-components=1
        [[ -f "$boost_src/boost/unordered/concurrent_flat_map.hpp" ]] || die "Boost concurrent headers missing"
        cmake -S "$d" -B "$b" -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="$PREFIX" \
            "-DCMAKE_CXX_FLAGS=-I$boost_src"
        cmake --build "$b" --parallel "$JOBS"
        cmake --install "$b" --strip
    )
    mark_installed YOSYS yosys
}

install_sby() {
    installed SBY sby && { info "sby already installed"; return; }
    local d; d=$(checkout SBY sby); prepare_git_source "$d"; info "install sby $(version_var SBY)"
    make -C "$d" install PREFIX="$PREFIX"; mark_installed SBY sby
}

install_eqy() {
    installed EQY eqy && { info "eqy already installed"; return; }
    local d; d=$(checkout EQY eqy); prepare_git_source "$d"; info "build eqy $(version_var EQY)"
    PATH="$PREFIX/bin:$PATH" make -C "$d" -j"$JOBS" YOSYS_CONFIG="$PREFIX/bin/yosys-config"
    PATH="$PREFIX/bin:$PATH" make -C "$d" install PREFIX="$PREFIX" YOSYS_CONFIG="$PREFIX/bin/yosys-config"
    mark_installed EQY eqy
}

install_bitwuzla() {
    installed BITWUZLA bitwuzla && { info "bitwuzla already installed"; return; }
    local d; d=$(checkout BITWUZLA bitwuzla); prepare_git_source "$d"; info "build bitwuzla $(version_var BITWUZLA)"
    (cd "$d"; python3 configure.py release --prefix="$PREFIX" --no-python --no-testing --no-unit-testing \
        --no-docs --no-kissat --no-cryptominisat --no-gimsatul --no-aiger --no-mimalloc; \
        ninja -C build -j "$JOBS" install)
    mark_installed BITWUZLA bitwuzla
}

install_boolector() {
    if installed BOOLECTOR boolector && [[ -x "$PREFIX/bin/btormc" && -x "$PREFIX/bin/btorsim" ]]; then
        info "boolector/btormc already installed"; return
    fi
    local d; d=$(archive_source BOOLECTOR boolector); info "build boolector $(version_var BOOLECTOR) / btormc"
    (
        cd "$d"
        ./contrib/setup-btor2tools.sh
        ./contrib/setup-lingeling.sh
        ./configure.sh
        make -C build -j"$JOBS"
        mkdir -p "$PREFIX/bin"
        install -m 0755 build/bin/boolector build/bin/btormc build/bin/btormbt build/bin/btoruntrace "$PREFIX/bin/"
        install -m 0755 deps/btor2tools/build/bin/btorsim "$PREFIX/bin/"
    )
    mark_installed BOOLECTOR boolector
}

install_cudd() {
    installed CUDD cudd && { info "cudd already installed"; return; }
    local d; d=$(archive_source CUDD cudd); info "build cudd $(version_var CUDD)"
    (cd "$d"; ./configure --prefix="$PREFIX"; make -j"$JOBS"; make install)
    mark_installed CUDD cudd
}

install_opensta() {
    installed OPENSTA opensta && { info "opensta already installed"; return; }
    install_cudd
    local d b; d=$(checkout OPENSTA opensta); prepare_git_source "$d"; b="$d/build-flexsoc"
    info "build opensta $(version_var OPENSTA)"
    cmake -S "$d" -B "$b" -G Ninja -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="$PREFIX" -DCUDD_DIR="$PREFIX" -DUSE_TCL_READLINE=OFF
    cmake --build "$b" --parallel "$JOBS"
    cmake --install "$b" --strip 2>/dev/null || { mkdir -p "$PREFIX/bin"; install -m 755 "$b/sta" "$PREFIX/bin/sta"; }
    mark_installed OPENSTA opensta
}

install_gtkwave() {
    installed GTKWAVE gtkwave && { info "gtkwave already installed"; return; }
    local d; d=$(archive_source GTKWAVE gtkwave); info "build gtkwave $(version_var GTKWAVE)"
    (cd "$d"; ./configure --prefix="$PREFIX"; make -j"$JOBS"; make install)
    mark_installed GTKWAVE gtkwave
}

install_surfer() {
    installed SURFER surfer && { info "surfer already installed"; return; }
    [[ $(uname -s) == Linux && $(uname -m) == x86_64 ]] || die "pinned Surfer binary currently supports linux-x86_64 only"
    local d bin; d=$(archive_source SURFER surfer); bin=$(find "$d" -type f -name surfer | head -1)
    [[ -n "$bin" ]] || die "surfer binary not found in release archive"
    info "install surfer $(version_var SURFER)"; mkdir -p "$PREFIX/bin"; install -m 755 "$bin" "$PREFIX/bin/surfer"
    mark_installed SURFER surfer
}

install_sv2v() {
    installed SV2V sv2v && { info "sv2v already installed"; return; }
    local d; d=$(checkout SV2V sv2v); prepare_git_source "$d"; info "build sv2v $(version_var SV2V)"
    (cd "$d"; STACK_ROOT="$CACHE/stack" stack --local-bin-path "$PREFIX/bin" build --copy-bins)
    mark_installed SV2V sv2v
}

install_netlistsvg() {
    installed NETLISTSVG netlistsvg && { info "netlistsvg already installed"; return; }
    local d; d=$(checkout NETLISTSVG netlistsvg); prepare_git_source "$d"; info "install netlistsvg $(version_var NETLISTSVG)"
    npm install --global --prefix "$PREFIX" "$d"
    mark_installed NETLISTSVG netlistsvg
}

profile_tools() {
    profile_ready
    echo "verilator slang iverilog yosys sby eqy bitwuzla boolector opensta gtkwave surfer sv2v netlistsvg"
}

install_tools() {
    paths; profile_ready; check_prereqs || die "host prerequisites missing; run bootstrap --$MODE --profile $PROFILE"
    [[ "$MODE" != system || $(id -u) -eq 0 ]] || die "--system install must run as root"
    mkdir -p "$PREFIX" "$SRC" "$DOWNLOADS" "$MARKERS"; export PATH="$PREFIX/bin:$PATH"
    export LD_LIBRARY_PATH="$PREFIX/lib:$PREFIX/lib64${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
    local tool; for tool in $(profile_tools); do "install_$tool"; done
    cp "$LOCK" "$PREFIX/toolchain.lock"; write_env
    info "$PROFILE profile installed in $PREFIX"
    info "activate with: source $PREFIX/env.sh"
}

emit_env() {
    cat <<EOF_ENV
export FLEXSOC_TOOLCHAIN="$PREFIX"
export PATH="$PREFIX/bin:\$PATH"
export LD_LIBRARY_PATH="$PREFIX/lib:$PREFIX/lib64\${LD_LIBRARY_PATH:+:\$LD_LIBRARY_PATH}"
export CMAKE_PREFIX_PATH="$PREFIX\${CMAKE_PREFIX_PATH:+:\$CMAKE_PREFIX_PATH}"
export PKG_CONFIG_PATH="$PREFIX/lib/pkgconfig:$PREFIX/lib64/pkgconfig:$PREFIX/share/pkgconfig\${PKG_CONFIG_PATH:+:\$PKG_CONFIG_PATH}"
EOF_ENV
}
write_env() { mkdir -p "$PREFIX"; emit_env > "$PREFIX/env.sh"; }

require_marker() {
    local key=$1 name=$2 marker expected
    marker="$MARKERS/$name.source"
    expected=$(source_id "$key")
    [[ -f "$marker" ]] || die "$name is not installed in $PREFIX"
    [[ $(cat "$marker") == "$expected" ]] || die "$name marker does not match toolchain.lock"
}
contains() { [[ "$1" == *"$2"* ]] || die "$3 version mismatch: $1"; }
first_line() { sed -n '/./{p;q;}' <<<"$1"; }

doctor() {
    paths; profile_ready; export PATH="$PREFIX/bin:$PATH"
    export LD_LIBRARY_PATH="$PREFIX/lib:$PREFIX/lib64${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
    local out tool
    for tool in $(profile_tools); do
        case "$tool" in
            verilator) require_marker VERILATOR verilator; out=$(verilator --version); contains "$out" "0b8c36974" verilator ;;
            slang) require_marker SLANG slang; out=$(slang --version); contains "$out" "11.0.0" slang; command -v slang-hier >/dev/null ;;
            iverilog) require_marker IVERILOG iverilog; out=$(iverilog -V 2>&1); contains "$out" "version 13.0" iverilog ;;
            yosys) require_marker YOSYS yosys; out=$(yosys -V); contains "$out" "Yosys 0.67" yosys; yosys -qp 'help read_slang' ;;
            sby) require_marker SBY sby; out=$(sby --version); contains "$out" "0.67" sby ;;
            eqy) require_marker EQY eqy; out=$(eqy --version); contains "$out" "0.67" eqy ;;
            bitwuzla) require_marker BITWUZLA bitwuzla; out=$(bitwuzla --version); contains "$out" "0.9.1" bitwuzla ;;
            boolector) require_marker BOOLECTOR boolector; out=$(boolector --version 2>&1); contains "$out" "3.2.4" boolector; [[ -x "$PREFIX/bin/btormc" && -x "$PREFIX/bin/btorsim" ]] ;;
            opensta) require_marker CUDD cudd; require_marker OPENSTA opensta; out=$(sta -version 2>&1) ;;
            gtkwave) require_marker GTKWAVE gtkwave; out=$(gtkwave --version 2>&1); contains "$out" "3.3.127" gtkwave ;;
            surfer) require_marker SURFER surfer; out=$(surfer --version 2>&1); contains "$out" "0.7.0" surfer ;;
            sv2v) require_marker SV2V sv2v; out=$(sv2v --version 2>&1); contains "$out" "0.0.13" sv2v ;;
            netlistsvg) require_marker NETLISTSVG netlistsvg; command -v netlistsvg >/dev/null; out="netlistsvg 1.0.2" ;;
        esac
        printf '  %-12s %s\n' "$tool" "$(first_line "$out")"
    done
    command -v dot >/dev/null; command -v xdot >/dev/null
    info "doctor PASS: $PROFILE @ $PREFIX"
}



print_env() { paths; emit_env; }

versions() {
    printf 'FlexSoC toolchain %s  lock=%s\n' "$TOOLCHAIN_ID" "$LOCK_HASH"
    echo '  [base]'
    local key
    for key in VERILATOR SLANG IVERILOG YOSYS SBY EQY BITWUZLA BOOLECTOR CUDD OPENSTA GTKWAVE SURFER SV2V NETLISTSVG; do
        printf '    %-12s %-14s %s\n' "${key,,}" "$(version_var "$key")" "$(source_id "$key")"
    done
    printf '    %-12s %-14s %s\n' boost-build "$(version_var BOOST)" "$(source_id BOOST)"
    echo '  [impl]  not locked yet: OpenROAD, KLayout/physical implementation stack'
    echo '  [riscv] not locked yet: RISC-V GNU toolchain'
}

COMMAND=${1:-}; [[ -n "$COMMAND" ]] || { usage; exit 2; }; shift || true
parse_options "$@"
case "$COMMAND" in
    bootstrap) bootstrap ;;
    install) install_tools ;;
    doctor) doctor ;;
    env) print_env ;;
    versions) versions ;;
    -h|--help|help) usage ;;
    *) die "unknown command: $COMMAND" ;;
esac
