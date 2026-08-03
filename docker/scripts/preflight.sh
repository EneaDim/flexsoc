#!/usr/bin/env bash
set -euo pipefail
source "$(dirname "$0")/common.sh"
require_docker

hard_free_gb=${MIN_HOST_FREE_GB:-12}
recommended_free_gb=${RECOMMENDED_HOST_FREE_GB:-25}
recommended_mem_gb=${RECOMMENDED_DOCKER_MEMORY_GB:-8}

free_kb=$(df -Pk "$REPO_ROOT" | awk 'NR==2 {print $4}')
free_gb=$((free_kb / 1024 / 1024))
mem_bytes=$(docker info --format '{{.MemTotal}}' 2>/dev/null || echo 0)
mem_gb=$((mem_bytes / 1024 / 1024 / 1024))
root_dir=$(docker info --format '{{.DockerRootDir}}' 2>/dev/null || echo unknown)

printf 'FlexSoC Docker preflight\n'
printf '  platform:       %s\n' "${DOCKER_PLATFORM:-linux/amd64}"
printf '  repository FS:  %s GiB free\n' "$free_gb"
printf '  Docker memory:  %s GiB\n' "$mem_gb"
printf '  Docker root:    %s\n' "$root_dir"
if grep -qi microsoft /proc/version 2>/dev/null; then
  echo '  environment:    WSL2 detected'
else
  echo '  environment:    native Linux or non-WSL client'
fi

echo
echo 'Docker storage usage:'
docker system df || true

if (( free_gb < hard_free_gb )); then
  echo "ERROR: less than ${hard_free_gb} GiB free on the repository filesystem" >&2
  echo 'Run docker system df and clean only unused Docker objects before building.' >&2
  exit 2
fi
if (( free_gb < recommended_free_gb )); then
  echo "WARNING: ${free_gb} GiB free; FlexSoC recommends at least ${recommended_free_gb} GiB for a clean source build plus BuildKit cache." >&2
fi
if (( mem_gb > 0 && mem_gb < recommended_mem_gb )); then
  echo "WARNING: Docker exposes ${mem_gb} GiB; ${recommended_mem_gb} GiB is recommended. Keep FLEXSOC_JOBS=2 or lower." >&2
fi

echo 'PREFLIGHT=PASS'
