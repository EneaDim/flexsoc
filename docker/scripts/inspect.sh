#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker

printf 'inputs_sha256=%s\n' "$(inputs_sha256)"
printf 'local=%s\n' "$(local_image_ref)"
printf 'registry_tag=%s\n' "$(registry_tag_ref)"
checkpoint=$(toolchain_checkpoint_ref)
if docker image inspect "$checkpoint" >/dev/null 2>&1; then
  docker image inspect "$checkpoint" --format 'checkpoint={{.RepoTags}} id={{.Id}} size={{.Size}} created={{.Created}}'
else
  printf 'checkpoint=MISSING\n'
fi
if ref=$(validate_lock 2>/dev/null); then
  printf 'locked=%s\n' "$ref"
  docker buildx imagetools inspect "$ref"
else
  printf 'locked=UNPUBLISHED_OR_STALE\n'
  test -f "$LOCK_FILE" && cat "$LOCK_FILE"
fi
