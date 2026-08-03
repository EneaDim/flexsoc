#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker
"$DOCKER_DIR/scripts/preflight.sh"

local_ref=$(local_image_ref)
checkpoint_ref=$(toolchain_checkpoint_ref)
registry_ref=$(registry_tag_ref)
source_url=$(git -C "$REPO_ROOT" config --get remote.origin.url 2>/dev/null || true)
metadata="$STATE_DIR/build-metadata.json"
checkpoint_metadata="$STATE_DIR/toolchain-checkpoint-metadata.json"

build_args=(
  --file "$DOCKERFILE"
  --platform "${DOCKER_PLATFORM:-linux/amd64}"
  --build-arg "FLEXSOC_JOBS=${FLEXSOC_JOBS:-2}"
  --build-arg "SOURCE_URL=$source_url"
)

printf 'Building resumable toolchain checkpoint %s\n' "$checkpoint_ref"
printf 'BuildKit caches preserve downloads, sources, build trees, and completed tool markers.\n'

docker buildx build \
  "${build_args[@]}" \
  --target toolchain-installed \
  --load \
  --tag "$checkpoint_ref" \
  --metadata-file "$checkpoint_metadata" \
  "$REPO_ROOT"

checkpoint_id=$(docker image inspect "$checkpoint_ref" --format '{{.Id}}')
cat > "$STATE_DIR/toolchain-checkpoint.env" <<EOF_CHECKPOINT
inputs_sha256=$(inputs_sha256)
image_ref=$checkpoint_ref
image_id=$checkpoint_id
EOF_CHECKPOINT
printf 'Toolchain checkpoint retained: %s (%s)\n' "$checkpoint_ref" "$checkpoint_id"

printf 'Building verified runtime image %s\n' "$local_ref"
printf 'Registry tag %s\n' "$registry_ref"

docker buildx build \
  "${build_args[@]}" \
  --target runtime \
  --load \
  --tag "$local_ref" \
  --tag "$registry_ref" \
  --metadata-file "$metadata" \
  "$REPO_ROOT"

docker image inspect "$local_ref" --format 'image={{.Id}} size={{.Size}} created={{.Created}}'
printf 'Build metadata: %s\n' "$metadata"
printf 'Checkpoint metadata: %s\n' "$checkpoint_metadata"
