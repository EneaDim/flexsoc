#!/usr/bin/env bash
# Qualify one packaged IP to L2, publish it, and verify a clean reload.
set -Eeuo pipefail

usage() {
  echo "Usage: $0 [uart|gpio|rv_timer|uart_master|ethernet] [--overwrite]" >&2
  echo 'Omit the IP to select interactively. --overwrite replaces an existing release.' >&2
}

ip=""
overwrite=0
for arg in "$@"; do
  case "$arg" in
    uart|gpio|rv_timer|uart_master|ethernet)
      if [[ -n "$ip" ]]; then usage; exit 2; fi
      ip="$arg" ;;
    --overwrite) overwrite=1 ;;
    -h|--help) usage; exit 0 ;;
    *) usage; exit 2 ;;
  esac
done
if [[ -z "$ip" ]]; then
  [[ -t 0 ]] || { usage; exit 2; }
  PS3='Choose IP (1-5): '
  select ip in uart gpio rv_timer uart_master ethernet; do
    [[ -n "$ip" ]] && break
  done
fi

case "$ip" in
  ethernet) version=0.1.0 ;;
  *) version=1.0.0 ;;
esac

repo="$(git rev-parse --show-toplevel)"
cd "$repo"
command -v fx >/dev/null || { echo 'ERROR: fx not found; activate the FlexSoC environment.' >&2; exit 1; }

run_id="l2_${ip}_$(date +%Y%m%d_%H%M%S)"
verify_id="${run_id}_verify"
step=initialization
trap 'echo "ERROR at step: $step (IP: $ip, run: $run_id)" >&2' ERR
run() { step="$*"; printf '\n==> %s\n' "$step"; "$@"; }

configure() {
  run fx settings "TOP=$ip" "RUN_TOP=$ip" "RUN_ID=$1" "HOST=$ip" \
    "IP_NAME=$ip" "IP_VERSION=$version" 'REG_ITF=tlul' 'QUAL_LEVEL=rtl'
}

assert_level() {
  local result="$1"
  grep -Eq '\[level\] L2 RTL Qualified: PASS' <<< "$result" || {
    echo 'ERROR: L2 is not PASS; refusing to publish.' >&2; exit 1;
  }
  grep -Eq '\[evidence\] model_tests[[:space:]]+PASS' <<< "$result" || {
    echo 'ERROR: model tests evidence is not PASS.' >&2; exit 1;
  }
}

printf 'IP=%s, version=%s, run=%s\n' "$ip" "$version" "$run_id"
if (( overwrite )); then
  echo 'WARNING: existing package release will be replaced after qualification.'
fi

configure "$run_id"
run fx setup
run fx ip_load
run fx trace
run fx mtest
run fx mtest --check
run fx flist
run fx lint
# The package already contains an authored SDC; do not overwrite it.
run fx cdc_rdc --setup
run fx cdc_rdc
run fx tests_gen
run fx tb cocotb --setup
run fx regression
run fx coverage
run fx formal --setup
run fx formal
run fx qualify --set QUAL_LEVEL=rtl
step='fx status: L2 gate'
status="$(fx status)"; printf '%s\n' "$status"
assert_level "$status"
run fx metrics
run fx manifest
run fx check

save_args=(ip_save --set QUAL_LEVEL=rtl)
if (( overwrite )); then
  save_args=(ip_save --force --set QUAL_LEVEL=rtl)
fi
run fx "${save_args[@]}"

configure "$verify_id"
run fx setup
run fx ip_load
run fx mtest --check
step='fx status: clean reload'
status="$(fx status)"; printf '%s\n' "$status"
assert_level "$status"
step='fx check: clean reload'
check_output="$(fx check)"; printf '%s\n' "$check_output"
for evidence in 'Model tests' 'Lint' 'CDC / RDC' 'Formal' 'RTL regression'; do
  if ! grep -E "${evidence}[[:space:]│]+PASS" <<< "$check_output" >/dev/null; then
    echo "ERROR: reload check did not confirm ${evidence} PASS." >&2
    exit 1
  fi
done
printf '\nSUCCESS: %s L2 PASS; saved package loaded in %s\n' "$ip" "$verify_id"
