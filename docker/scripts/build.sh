#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker
"$DOCKER_DIR/scripts/preflight.sh"

local_ref=$(local_image_ref)
registry_ref=$(registry_tag_ref)
source_url=$(git -C "$REPO_ROOT" config --get remote.origin.url 2>/dev/null || true)
metadata="$STATE_DIR/build-metadata.json"

printf 'Building %s\n' "$local_ref"
printf 'Registry tag %s\n' "$registry_ref"

docker buildx build \
  --file "$DOCKERFILE" \
  --platform "${DOCKER_PLATFORM:-linux/amd64}" \
  --build-arg "FLEXSOC_JOBS=${FLEXSOC_JOBS:-2}" \
  --build-arg "SOURCE_URL=$source_url" \
  --load \
  --tag "$local_ref" \
  --tag "$registry_ref" \
  --metadata-file "$metadata" \
  "$REPO_ROOT"

docker image inspect "$local_ref" --format 'image={{.Id}} size={{.Size}} created={{.Created}}'
printf 'Build metadata: %s\n' "$metadata"
