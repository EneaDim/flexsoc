#!/usr/bin/env bash
set -euo pipefail

source "$(dirname "$0")/common.sh"

require_buildx

local_ref=$(local_image_ref)
checkpoint_ref=$(toolchain_checkpoint_ref)
registry_ref=$(registry_tag_ref)
registry_checkpoint=$(registry_checkpoint_ref)
verification="$STATE_DIR/verified.env"

test -f "$verification" || {
  echo "image has not been verified" >&2
  echo "run docker/scripts/verify.sh first" >&2
  exit 2
}

# shellcheck disable=SC1090
source "$verification"

current_inputs=$(inputs_sha256)

current_id=$(
  docker image inspect "$local_ref" \
    --format '{{.Id}}' \
    2>/dev/null ||
    true
)

[[ "${inputs_sha256:-}" == "$current_inputs" ]] || {
  echo "verification is stale: image inputs changed" >&2
  exit 3
}

[[ "${image_ref:-}" == "$local_ref" ]] || {
  echo "verification references a different image" >&2
  exit 4
}

[[ "${image_id:-}" == "$current_id" ]] || {
  echo "verified image was replaced or removed" >&2
  exit 5
}

token=${GHCR_TOKEN:-${GH_TOKEN:-}}

if [[ -n "$token" ]]; then
  user=${GHCR_USER:-$(github_slug | cut -d/ -f1)}

  printf '%s' "$token" |
    docker login ghcr.io \
      --username "$user" \
      --password-stdin
fi

docker image inspect "$checkpoint_ref" >/dev/null 2>&1 || {
  echo "implementation checkpoint is missing: $checkpoint_ref" >&2
  exit 6
}

docker push "$registry_checkpoint"
docker push "$registry_ref"

digest=$(
  docker buildx imagetools inspect "$registry_ref" |
    awk '/^Digest:/ {print $2; exit}'
)

[[ "$digest" == sha256:* ]] || {
  echo "unable to resolve registry digest" >&2
  exit 7
}

repository=$(registry_repository)
tag=$(image_tag)

tmp="$LOCK_FILE.tmp"

cat > "$tmp" <<EOF_LOCK
schema=1
inputs_sha256=$current_inputs
repository=$repository
tag=$tag
digest=$digest
EOF_LOCK

mv "$tmp" "$LOCK_FILE"

printf 'Checkpoint: %s\n' "$registry_checkpoint"
printf 'Published:  %s\n' "$registry_ref"
printf 'Locked:     %s@%s\n' "$repository" "$digest"
printf 'Lock file: %s\n' "$LOCK_FILE"
