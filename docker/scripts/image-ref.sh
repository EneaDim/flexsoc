#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"

case "${1:-local}" in
  local) local_image_ref ;;
  tag) registry_tag_ref ;;
  locked) validate_lock ;;
  inputs) inputs_sha256 ;;
  *) echo "usage: $0 {local|tag|locked|inputs}" >&2; exit 2 ;;
esac
