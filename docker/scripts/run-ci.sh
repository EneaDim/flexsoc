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

    ruff check .

    pytest -q tests/test_api.py
    pytest --collect-only -q tests/test_e2e_fx.py

    if [[ ${FLEXSOC_RUN_E2E:-0} == 1 ]]; then
      pytest -s tests/test_e2e_fx.py
    fi
  '
