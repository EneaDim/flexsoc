#!/usr/bin/env bash
set -euo pipefail

source "$(dirname "$0")/common.sh"

require_docker

image_ref=${1:-}

if [[ -z "$image_ref" ]]; then
  image_ref=$(validate_lock)
fi

extra=()

if [[ ${FULL_E2E:-0} == 1 ]]; then
  extra+=(--env FLEXSOC_RUN_E2E=1)
fi

printf 'Running project CI with:\n  %s\n' "$image_ref"

docker run --rm \
  --pull=missing \
  --volume "$REPO_ROOT:/workspace" \
  --workdir /workspace \
  --env PYTHONPATH=src \
  --env DEPS_MODE=system \
  --env FLEXSOC_E2E_LIVE=0 \
  "${extra[@]}" \
  "$image_ref" \
  bash -lc '
    set -euo pipefail

    uv pip install \
      --python "$VIRTUAL_ENV/bin/python" \
      --no-deps \
      --editable .

    DEPS_MODE=system fx deps-doctor
    fx doctor

    make lint
    make test-api
    uv run --no-sync pytest --collect-only -q tests/test_e2e_fx.py

    if [[ ${FLEXSOC_RUN_E2E:-0} == 1 ]]; then
      for pdk in sky130 ihp-sg13g2; do
        fx pdk info "$pdk" --json | jq -e .views.usable >/dev/null ||
          fx pdk fetch "$pdk" --force
      done
      make test E2E_ORS="$ORFS_ROOT/flow"
    fi
  '
