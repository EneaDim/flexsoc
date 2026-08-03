#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
ref=$(validate_lock)
printf 'IMAGE_REF=%s\n' "$ref"
printf 'INPUTS_SHA256=%s\n' "$(inputs_sha256)"
if [[ -n ${GITHUB_OUTPUT:-} ]]; then
  printf 'ref=%s\n' "$ref" >> "$GITHUB_OUTPUT"
fi
