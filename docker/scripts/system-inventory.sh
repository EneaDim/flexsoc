#!/usr/bin/env bash
set -euo pipefail

DOCKER_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
REPO_ROOT=$(cd "$DOCKER_DIR/.." && pwd)
LOCK="$REPO_ROOT/src/flexsoc/backend/toolchain.lock"
# shellcheck disable=SC1090
source "$LOCK"

managed_root="${XDG_DATA_HOME:-$HOME/.local/share}/flexsoc"
repo_venv="$REPO_ROOT/.venv"
if [[ -n ${SYSTEM_PATH:-} ]]; then
  host_path=$SYSTEM_PATH
else
  host_path=""
  IFS=: read -r -a path_items <<<"${PATH:-}"
  for item in "${path_items[@]}"; do
    [[ -n "$item" ]] || continue
    case "$item" in
      "$managed_root"|"$managed_root"/*|"$repo_venv"|"$repo_venv"/*) continue ;;
    esac
    case ":$host_path:" in *":$item:"*) ;; *) host_path="${host_path:+$host_path:}$item" ;; esac
  done
  for item in /usr/local/sbin /usr/local/bin /usr/sbin /usr/bin /sbin /bin; do
    case ":$host_path:" in *":$item:"*) ;; *) host_path="${host_path:+$host_path:}$item" ;; esac
  done
fi
export PATH="$host_path"
unset FLEXSOC_TOOLCHAIN LD_LIBRARY_PATH CMAKE_PREFIX_PATH PKG_CONFIG_PATH || true

version_line() {
  local tool=$1
  case "$tool" in
    verilator) verilator --version 2>&1 | sed -n '/./{p;q;}' ;;
    slang) slang --version 2>&1 | sed -n '/./{p;q;}' ;;
    iverilog) iverilog -V 2>&1 | sed -n '/version/{p;q;}' ;;
    yosys) yosys -V 2>&1 | sed -n '/./{p;q;}' ;;
    sby|eqy|bitwuzla|boolector|surfer|sv2v|uv|docker) "$tool" --version 2>&1 | sed -n '/./{p;q;}' ;;
    sta) sta -version 2>&1 | sed -n '/./{p;q;}' ;;
    gtkwave) gtkwave --version 2>&1 | sed -n '/./{p;q;}' ;;
    fst2vcd) fst2vcd --help 2>&1 | sed -n '/./{p;q;}' ;;
    openroad) openroad -version 2>&1 | sed -n '/./{p;q;}' ;;
    klayout) klayout -v 2>&1 | sed -n '/./{p;q;}' ;;
    netlistsvg) netlistsvg --help 2>&1 | sed -n '/./{p;q;}' ;;
    *) "$tool" --version 2>&1 | sed -n '/./{p;q;}' ;;
  esac
}

owner_of() {
  local path=$1 owner
  owner=$(dpkg-query -S "$path" 2>/dev/null | sed -n '1p' || true)
  [[ -n "$owner" ]] && printf '%s' "$owner" || printf 'unmanaged/system-local'
}

lock_match() {
  local tool=$1 text=$2
  case "$tool" in
    verilator) [[ "$text" == *"$VERILATOR_VERSION"* ]] ;;
    slang) [[ "$text" == *"$SLANG_VERSION"* ]] ;;
    iverilog) [[ "$text" == *"version $IVERILOG_VERSION"* ]] ;;
    yosys) [[ "$text" == *"Yosys $YOSYS_VERSION"* ]] ;;
    sby) [[ "$text" == *"$SBY_VERSION"* ]] ;;
    eqy) [[ "$text" == *"$EQY_VERSION"* ]] ;;
    bitwuzla) [[ "$text" == *"$BITWUZLA_VERSION"* ]] ;;
    boolector) [[ "$text" == *"$BOOLECTOR_VERSION"* ]] ;;
    gtkwave) [[ "$text" == *"$GTKWAVE_VERSION"* ]] ;;
    surfer) [[ "$text" == *"$SURFER_VERSION"* ]] ;;
    sv2v) [[ "$text" == *"$SV2V_VERSION"* ]] ;;
    *) return 1 ;;
  esac
}

current_required=(verilator slang iverilog yosys sby eqy bitwuzla boolector sta fst2vcd)
current_optional=(uv gtkwave surfer sv2v netlistsvg)
production_target=(openroad klayout)
missing=0
pinned=0
present=0

print_group() {
  local title=$1 role=$2; shift 2
  echo
  echo "$title"
  printf '%-11s %-8s %-34s %s\n' Tool Status Path Version
  local tool path text status
  for tool in "$@"; do
    path=$(command -v "$tool" 2>/dev/null || true)
    if [[ -z "$path" ]]; then
      status=MISSING
      [[ "$role" == required ]] && missing=$((missing + 1))
      printf '%-11s %-8s %-34s %s\n' "$tool" "$status" - -
      continue
    fi
    text=$(version_line "$tool" || true)
    present=$((present + 1))
    if lock_match "$tool" "$text"; then status=PINNED; pinned=$((pinned + 1)); else status=PRESENT; fi
    printf '%-11s %-8s %-34s %s\n' "$tool" "$status" "$path" "$text"
    printf '  owner: %s\n' "$(owner_of "$path")"
  done
}

echo "FlexSoC host system inventory"
echo "  PATH: $PATH"
echo "  note: FlexSoC managed prefixes and the repository .venv are deliberately excluded"
print_group "Current source-flow tools" required "${current_required[@]}"
print_group "Debug and convenience tools" optional "${current_optional[@]}"
print_group "Production physical-flow targets" optional "${production_target[@]}"

echo
echo "Summary"
echo "  present: $present"
echo "  exact lock matches detectable from CLI version: $pinned"
echo "  required missing: $missing"
if [[ $missing -ne 0 ]]; then
  echo "SYSTEM_FLOW=INCOMPLETE"
  exit 2
fi
echo "SYSTEM_FLOW=AVAILABLE"
echo "SYSTEM_FLOW_AUTHORITY=compatibility-only"
echo "CONTAINER_LOCK_AUTHORITY=required-for-CI-and-release"
