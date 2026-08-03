#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker

image_ref=$(local_image_ref)
docker image inspect "$image_ref" >/dev/null 2>&1 || {
  echo "local image not found: $image_ref; run docker/scripts/build.sh" >&2
  exit 2
}

USE_LOCAL_IMAGE=1 FULL_E2E=${FULL_E2E:-0} "$DOCKER_DIR/scripts/run-ci.sh" "$image_ref"

image_id=$(docker image inspect "$image_ref" --format '{{.Id}}')
cat > "$STATE_DIR/verified.env" <<EOF_STATE
inputs_sha256=$(inputs_sha256)
image_ref=$image_ref
image_id=$image_id
full_e2e=${FULL_E2E:-0}
EOF_STATE
printf 'Verified image: %s\n' "$image_ref"
printf 'Verification record: %s\n' "$STATE_DIR/verified.env"
