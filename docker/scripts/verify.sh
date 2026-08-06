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
    command -v openroad
    command -v klayout

    echo
    echo "===== Physical implementation ====="

    openroad -version
    sta -version
    klayout -b -v

    test "$OPENROAD_EXE" = /opt/flexsoc/toolchain/bin/openroad
    test "$YOSYS_EXE" = /opt/flexsoc/toolchain/bin/yosys
    test "$KLAYOUT_CMD" = /opt/flexsoc/toolchain/bin/klayout
    test -f "$ORFS_ROOT/flow/Makefile"
    test -d "$ORFS_ROOT/flow/scripts"
    test -d "$ORFS_ROOT/flow/platforms"

    ldd "$OPENROAD_EXE" | tee /tmp/openroad.ldd
    ! grep -q "not found" /tmp/openroad.ldd

    test -s /opt/flexsoc/toolchain/.flexsoc/openroad.ref
    test -s /opt/flexsoc/toolchain/.flexsoc/orfs.ref

    echo
    echo "===== ORFS smoke flow ====="

    smoke=/tmp/flexsoc-orfs-smoke
    rm -rf "$smoke"

    make --directory "$ORFS_ROOT/flow" \
      WORK_HOME="$smoke" \
      DESIGN_CONFIG="$ORFS_ROOT/flow/designs/nangate45/gcd/config.mk" \
      OPENROAD_EXE="$OPENROAD_EXE" \
      YOSYS_EXE="$YOSYS_EXE" \
      KLAYOUT_CMD="$KLAYOUT_CMD" \
      PYTHON_EXE="$PYTHON_EXE" \
      floorplan

    find "$smoke/results" -name 2_floorplan.odb -type f -print -quit |
      grep -q .

    rm -rf "$smoke"

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
