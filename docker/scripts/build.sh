#!/usr/bin/env bash
set -euo pipefail

source "$(dirname "$0")/common.sh"

require_buildx

rm -f "$STATE_DIR/verified.env"

check_path="$REPO_ROOT"
if grep -qi microsoft /proc/version 2>/dev/null && [[ -d /mnt/c ]]; then
  check_path=/mnt/c
fi

free_kb=$(df -Pk "$check_path" | awk 'NR == 2 {print $4}')
free_gb=$((free_kb / 1024 / 1024))
minimum_free_gb=${MIN_HOST_FREE_GB:-12}

printf 'FlexSoC image build\n'
printf '  free space: %s GiB on %s\n' "$free_gb" "$check_path"
printf '  platform:   %s\n' "${DOCKER_PLATFORM:-linux/amd64}"

echo
docker system df || true
echo

if (( free_gb < minimum_free_gb )); then
  echo "ERROR: less than ${minimum_free_gb} GiB available on $check_path" >&2
  exit 2
fi

local_ref=$(local_image_ref)
local_checkpoint=$(toolchain_checkpoint_ref)
registry_ref=$(registry_tag_ref)
registry_checkpoint=$(registry_checkpoint_ref)
base_checkpoint=$(registry_base_checkpoint_ref)
openroad_checkpoint=$(registry_openroad_checkpoint_ref)
persist_checkpoints=${PERSIST_BUILD_CHECKPOINTS:-0}

source_url=$(git -C "$REPO_ROOT" config --get remote.origin.url 2>/dev/null || true)
metadata="$STATE_DIR/build-metadata.json"

build_args=(
  --file "$DOCKERFILE"
  --platform "${DOCKER_PLATFORM:-linux/amd64}"
  --build-arg "FLEXSOC_JOBS=${FLEXSOC_JOBS:-2}"
  --build-arg "SOURCE_URL=$source_url"
)

cache_args=()
cache_ref=${BUILDX_CACHE_REF:-}
if [[ -n "$cache_ref" ]]; then
  printf 'Build cache:\n  %s\n' "$cache_ref"
  cache_args+=(
    --cache-from "type=registry,ref=$cache_ref"
    --cache-to "type=registry,ref=$cache_ref,mode=max"
  )
fi

runtime_context=()

if [[ "$persist_checkpoints" == 1 ]]; then
  echo "Persistent build checkpoints: enabled"

  if registry_image_exists "$base_checkpoint"; then
    printf 'Reusing base checkpoint:\n  %s\n' "$base_checkpoint"
  else
    printf 'Building base checkpoint:\n  %s\n' "$base_checkpoint"
    docker buildx build \
      "${build_args[@]}" \
      "${cache_args[@]}" \
      --target toolchain-installed \
      --push \
      --tag "$base_checkpoint" \
      "$REPO_ROOT"
  fi

  if registry_image_exists "$openroad_checkpoint"; then
    printf 'Reusing OpenROAD checkpoint:\n  %s\n' "$openroad_checkpoint"
  else
    printf 'Building OpenROAD checkpoint:\n  %s\n' "$openroad_checkpoint"
    docker buildx build \
      "${build_args[@]}" \
      "${cache_args[@]}" \
      --target openroad-checkpoint \
      --push \
      --tag "$openroad_checkpoint" \
      "$REPO_ROOT"
  fi

  runtime_context+=(
    --build-context "toolchain-installed=docker-image://$base_checkpoint"
    --build-context "openroad-checkpoint=docker-image://$openroad_checkpoint"
  )

  if registry_image_exists "$registry_checkpoint"; then
    printf 'Reusing implementation checkpoint:\n  %s\n' "$registry_checkpoint"
  else
    printf 'Building implementation checkpoint:\n  %s\n' "$registry_checkpoint"
    docker buildx build \
      "${build_args[@]}" \
      "${cache_args[@]}" \
      "${runtime_context[@]}" \
      --target implementation-installed \
      --push \
      --tag "$registry_checkpoint" \
      "$REPO_ROOT"
  fi

  runtime_context+=(
    --build-context "implementation-installed=docker-image://$registry_checkpoint"
  )
else
  echo "Persistent build checkpoints: disabled"
  printf 'Building local implementation checkpoint:\n  %s\n' "$local_checkpoint"
  docker buildx build \
    "${build_args[@]}" \
    "${cache_args[@]}" \
    --target implementation-installed \
    --load \
    --tag "$local_checkpoint" \
    "$REPO_ROOT"
fi

printf 'Building runtime image:\n  %s\n' "$local_ref"

docker buildx build \
  "${build_args[@]}" \
  "${cache_args[@]}" \
  "${runtime_context[@]}" \
  --target runtime \
  --load \
  --tag "$local_ref" \
  --tag "$registry_ref" \
  --metadata-file "$metadata" \
  "$REPO_ROOT"

docker image inspect "$local_ref" \
  --format 'image={{.Id}} size={{.Size}} created={{.Created}}'

cat > "$STATE_DIR/toolchain-checkpoint.env" <<EOF_CHECKPOINT
inputs_sha256=$(inputs_sha256)
base_checkpoint=$base_checkpoint
openroad_checkpoint=$openroad_checkpoint
implementation_checkpoint=$registry_checkpoint
EOF_CHECKPOINT

printf 'Base checkpoint:           %s\n' "$base_checkpoint"
printf 'OpenROAD checkpoint:       %s\n' "$openroad_checkpoint"
printf 'Implementation checkpoint: %s\n' "$registry_checkpoint"
printf 'Build metadata: %s\n' "$metadata"
