#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker

local_ref=$(local_image_ref)
registry_ref=$(registry_tag_ref)
verification="$STATE_DIR/verified.env"

test -f "$verification" || {
  echo "image has not been verified; run docker/scripts/verify.sh" >&2
  exit 2
}
# shellcheck disable=SC1090
source "$verification"
current_inputs=$(inputs_sha256)
current_id=$(docker image inspect "$local_ref" --format '{{.Id}}' 2>/dev/null || true)
[[ "$inputs_sha256" == "$current_inputs" ]] || {
  echo "verification is stale; image inputs changed" >&2
  exit 3
}
[[ "$image_ref" == "$local_ref" && "$image_id" == "$current_id" ]] || {
  echo "verified image no longer matches the local image" >&2
  exit 4
}

if docker buildx imagetools inspect "$registry_ref" >/dev/null 2>&1; then
  if [[ ${ALLOW_EXISTING_IMAGE:-0} != 1 ]]; then
    echo "registry tag already exists: $registry_ref" >&2
    echo "set ALLOW_EXISTING_IMAGE=1 only to re-read the existing immutable tag" >&2
    exit 5
  fi
else
  if [[ -n ${GHCR_TOKEN:-} ]]; then
    user=${GHCR_USER:-$(github_slug | cut -d/ -f1)}
    printf '%s' "$GHCR_TOKEN" | docker login ghcr.io --username "$user" --password-stdin
  fi
  docker push "$registry_ref"
fi

digest=$(docker buildx imagetools inspect "$registry_ref" | awk '/^Digest:/ {print $2; exit}')
[[ "$digest" == sha256:* ]] || { echo "unable to resolve registry digest" >&2; exit 6; }
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

locked_ref="$repository@$digest"
docker pull "$locked_ref"
FULL_E2E=0 "$DOCKER_DIR/scripts/run-ci.sh" "$locked_ref"
printf 'Published and locked: %s\n' "$locked_ref"
printf 'Commit %s before pushing source changes.\n' "$LOCK_FILE"
