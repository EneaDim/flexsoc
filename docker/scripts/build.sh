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
checkpoint_ref=$(toolchain_checkpoint_ref)
registry_ref=$(registry_tag_ref)

source_url=$(
  git -C "$REPO_ROOT" config --get remote.origin.url 2>/dev/null ||
    true
)

metadata="$STATE_DIR/build-metadata.json"
checkpoint_metadata="$STATE_DIR/toolchain-checkpoint-metadata.json"

build_args=(
  --file "$DOCKERFILE"
  --platform "${DOCKER_PLATFORM:-linux/amd64}"
  --build-arg "FLEXSOC_JOBS=${FLEXSOC_JOBS:-2}"
  --build-arg "SOURCE_URL=$source_url"
)

runtime_context=()
external_checkpoint=${TOOLCHAIN_CHECKPOINT_IMAGE:-}

if [[ -n "$external_checkpoint" ]]; then
  printf 'Using existing checkpoint:\n  %s\n' "$external_checkpoint"

  runtime_context+=(
    --build-context
    "toolchain-installed=docker-image://$external_checkpoint"
  )
else
  printf 'Building checkpoint:\n  %s\n' "$checkpoint_ref"

  docker buildx build \
    "${build_args[@]}" \
    --target toolchain-installed \
    --load \
    --tag "$checkpoint_ref" \
    --metadata-file "$checkpoint_metadata" \
    "$REPO_ROOT"

  checkpoint_id=$(
    docker image inspect "$checkpoint_ref" \
      --format '{{.Id}}'
  )

  cat > "$STATE_DIR/toolchain-checkpoint.env" <<EOF_CHECKPOINT
inputs_sha256=$(inputs_sha256)
image_ref=$checkpoint_ref
image_id=$checkpoint_id
EOF_CHECKPOINT

  printf 'Checkpoint retained: %s\n' "$checkpoint_id"
fi

printf 'Building runtime image:\n  %s\n' "$local_ref"

docker buildx build \
  "${build_args[@]}" \
  "${runtime_context[@]}" \
  --target runtime \
  --load \
  --tag "$local_ref" \
  --tag "$registry_ref" \
  --metadata-file "$metadata" \
  "$REPO_ROOT"

docker image inspect "$local_ref" \
  --format 'image={{.Id}} size={{.Size}} created={{.Created}}'

printf 'Build metadata: %s\n' "$metadata"
