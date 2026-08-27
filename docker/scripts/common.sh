#!/usr/bin/env bash
set -euo pipefail

DOCKER_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
REPO_ROOT=$(cd "$DOCKER_DIR/.." && pwd)

STATE_DIR="$DOCKER_DIR/.state"
LOCK_FILE="$DOCKER_DIR/ci/image.lock"
DOCKERFILE="$DOCKER_DIR/ci/Dockerfile"
TOOLCHAIN_LOCK="$REPO_ROOT/src/flexsoc/backend/core/toolchain.lock"
DEPS_SCRIPT="$REPO_ROOT/src/flexsoc/backend/core/deps.sh"

mkdir -p "$STATE_DIR"

image_input_files() {
  cat <<'FILES'
docker/ci/Dockerfile
docker/ci/Dockerfile.dockerignore
src/flexsoc/backend/core/deps.sh
src/flexsoc/backend/core/toolchain.lock
pyproject.toml
uv.lock
FILES
}

inputs_sha256() {
  (
    cd "$REPO_ROOT"

    while IFS= read -r path; do
      test -f "$path" || {
        echo "missing image input: $path" >&2
        exit 2
      }

      sha256sum "$path"
    done < <(image_input_files)
  ) |
    sha256sum |
    awk '{print $1}'
}

docker_stage_text() {
  local stage=$1
  awk -v stage="$stage" '
    /^FROM[[:space:]]/ {
      if (capture) exit
      capture = ($(NF - 1) == "AS" && $NF == stage)
    }
    capture { print }
  ' "$DOCKERFILE"
}

base_lock_text() {
  awk '/^# impl / {exit} {print}' "$TOOLCHAIN_LOCK"
}

implementation_lock_text() {
  grep -E '^(ORFS_REPO|ORFS_REF_PREFIX|OPENROAD_REPO|OPENROAD_REF_PREFIX|OPENROAD_INSTALL_MODE)=' \
    "$TOOLCHAIN_LOCK"
}

checkpoint_sha256() {
  local checkpoint=$1
  case "$checkpoint" in
    base)
      {
        docker_stage_text toolchain-prereqs
        docker_stage_text toolchain-installed
        base_lock_text
        cat "$DEPS_SCRIPT"
      } | sha256sum | awk '{print $1}'
      ;;
    openroad)
      {
        docker_stage_text implementation-builder
        docker_stage_text openroad-checkpoint
        implementation_lock_text
      } | sha256sum | awk '{print $1}'
      ;;
    *)
      echo "unknown checkpoint: $checkpoint" >&2
      return 2
      ;;
  esac
}

image_tag() {
  printf 'toolchain-%s\n' "$(inputs_sha256 | cut -c1-16)"
}

local_image_ref() {
  printf '%s:%s\n' \
    "${LOCAL_IMAGE_REPOSITORY:-flexsoc-ci}" \
    "$(image_tag)"
}

toolchain_checkpoint_ref() {
  printf '%s:%s-installed\n' \
    "${LOCAL_IMAGE_REPOSITORY:-flexsoc-ci}" \
    "$(image_tag)"
}

github_slug() {
  local url slug

  url=$(git -C "$REPO_ROOT" config --get remote.origin.url 2>/dev/null || true)

  case "$url" in
    git@github.com:*)
      slug=${url#git@github.com:}
      ;;
    ssh://git@github.com/*)
      slug=${url#ssh://git@github.com/}
      ;;
    https://github.com/*)
      slug=${url#https://github.com/}
      ;;
    http://github.com/*)
      slug=${url#http://github.com/}
      ;;
    *)
      return 1
      ;;
  esac

  slug=${slug%.git}
  printf '%s\n' "${slug,,}"
}

registry_repository() {
  if [[ -n ${IMAGE_REPOSITORY:-} ]]; then
    printf '%s\n' "$IMAGE_REPOSITORY"
    return
  fi

  local slug

  slug=$(github_slug) || {
    echo "cannot derive GHCR repository; set IMAGE_REPOSITORY explicitly" >&2
    return 2
  }

  printf 'ghcr.io/%s/flexsoc-ci\n' "$slug"
}

registry_tag_ref() {
  printf '%s:%s\n' \
    "$(registry_repository)" \
    "$(image_tag)"
}

registry_checkpoint_ref() {
  printf '%s:%s-installed\n' \
    "$(registry_repository)" \
    "$(image_tag)"
}

registry_base_checkpoint_ref() {
  printf '%s:checkpoint-base-%s\n' \
    "$(registry_repository)" \
    "$(checkpoint_sha256 base | cut -c1-16)"
}

registry_openroad_checkpoint_ref() {
  printf '%s:checkpoint-openroad-%s\n' \
    "$(registry_repository)" \
    "$(checkpoint_sha256 openroad | cut -c1-16)"
}

registry_image_exists() {
  docker buildx imagetools inspect "$1" >/dev/null 2>&1
}

require_docker() {
  command -v docker >/dev/null 2>&1 || {
    echo "docker is required" >&2
    exit 2
  }

  docker version >/dev/null 2>&1 || {
    echo "Docker daemon is not reachable" >&2
    exit 2
  }
}

require_buildx() {
  require_docker

  docker buildx version >/dev/null 2>&1 || {
    echo "docker buildx is required" >&2
    exit 2
  }
}

read_lock_value() {
  local key=$1

  test -f "$LOCK_FILE" || return 1

  sed -n "s/^${key}=//p" "$LOCK_FILE" |
    tail -n 1
}

validate_lock() {
  local expected actual repository tag digest

  test -f "$LOCK_FILE" || {
    echo "missing $LOCK_FILE" >&2
    return 2
  }

  expected=$(inputs_sha256)
  actual=$(read_lock_value inputs_sha256 || true)
  repository=$(read_lock_value repository || true)
  tag=$(read_lock_value tag || true)
  digest=$(read_lock_value digest || true)

  [[ "$actual" == "$expected" ]] || {
    echo "stale image lock: lock=$actual current=$expected" >&2
    return 3
  }

  [[ -n "$repository" && "$repository" != UNPUBLISHED ]] || {
    echo "image lock is unpublished" >&2
    return 4
  }

  [[ "$tag" == "$(image_tag)" ]] || {
    echo "image lock tag mismatch: lock=$tag current=$(image_tag)" >&2
    return 5
  }

  [[ "$digest" == sha256:* ]] || {
    echo "image lock has no registry digest" >&2
    return 6
  }

  printf '%s@%s\n' "$repository" "$digest"
}
