#!/usr/bin/env bash
set -euo pipefail

source "$(dirname "$0")/common.sh"

require_docker

image_ref=$(local_image_ref)

docker image inspect "$image_ref" >/dev/null 2>&1 || {
  echo "local image not found: $image_ref" >&2
  echo "run docker/scripts/build.sh first" >&2
  exit 2
}

docker run --rm \
  --entrypoint bash \
  "$image_ref" \
  -lc '
    set -euo pipefail

    echo "===== Toolchain ====="

    bash /opt/flexsoc-build/toolchain/deps.sh \
      doctor \
      --system \
      --profile base

    echo
    echo "===== Runtime ====="

    test -d /opt/flexsoc/toolchain
    test -x "$VIRTUAL_ENV/bin/python"
    test -x /opt/uv/bin/uv

    python --version
    uv --version

    echo
    echo "===== Commands ====="

    command -v yosys
    command -v verilator
    command -v iverilog
    command -v sby
    command -v sv2v

    echo
    echo "IMAGE_VERIFY=PASS"
  '

image_id=$(
  docker image inspect "$image_ref" \
    --format '{{.Id}}'
)

cat > "$STATE_DIR/verified.env" <<EOF_STATE
inputs_sha256=$(inputs_sha256)
image_ref=$image_ref
image_id=$image_id
verification=runtime-smoke
EOF_STATE

printf 'Verified image: %s\n' "$image_ref"
printf 'Verification record: %s\n' "$STATE_DIR/verified.env"
