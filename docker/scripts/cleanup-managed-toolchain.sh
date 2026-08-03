#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker

apply=${APPLY:-0}
verified="$STATE_DIR/verified.env"
[[ -f "$verified" ]] || {
  echo "Refusing cleanup: missing $verified" >&2
  echo 'Build and verify the Docker image first with docker/scripts/build.sh and verify.sh.' >&2
  exit 2
}
# shellcheck disable=SC1090
source "$verified"
current_inputs=$(inputs_sha256)
[[ "${inputs_sha256:-}" == "$current_inputs" ]] || {
  echo 'Refusing cleanup: Docker verification record is stale.' >&2
  exit 3
}
actual_image_id=$(docker image inspect "${image_ref:?}" --format '{{.Id}}' 2>/dev/null || true)
[[ -n "$actual_image_id" && "$actual_image_id" == "${image_id:-}" ]] || {
  echo 'Refusing cleanup: verified Docker image is absent or changed.' >&2
  exit 4
}

managed_root="${XDG_DATA_HOME:-$HOME/.local/share}/flexsoc"
toolchains="$managed_root/toolchains"
stable="$managed_root/toolchain"
cache="${XDG_CACHE_HOME:-$HOME/.cache}/flexsoc"

[[ ! -e "$stable" || -L "$stable" ]] || {
  echo "Refusing cleanup: $stable exists but is not a symlink." >&2
  exit 5
}

show_target() {
  local label=$1 path=$2 size=absent
  [[ -e "$path" || -L "$path" ]] && size=$(du -shL "$path" 2>/dev/null | awk '{print $1}' || echo unknown)
  printf '  %-18s %-9s %s\n' "$label" "$size" "$path"
}

echo 'FlexSoC host managed-toolchain cleanup'
echo "  verified image: $image_ref"
echo "  image id:       $actual_image_id"
show_target toolchains "$toolchains"
show_target stable-link "$stable"
show_target build-cache "$cache"
echo '  preserved:         repository .venv, /usr, /usr/local, Docker images and Docker cache'

if [[ "$apply" != 1 ]]; then
  echo 'DRY_RUN=1'
  echo 'Run APPLY=1 docker/scripts/cleanup-managed-toolchain.sh after reviewing the paths.'
  exit 0
fi

rm -rf -- "$toolchains" "$cache"
rm -f -- "$stable"
rmdir "$managed_root" 2>/dev/null || true

echo 'CLEANUP=OK'
echo 'Open a new shell, or run:'
echo '  unset FLEXSOC_TOOLCHAIN LD_LIBRARY_PATH CMAKE_PREFIX_PATH PKG_CONFIG_PATH'
echo '  hash -r'
