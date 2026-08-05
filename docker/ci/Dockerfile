# syntax=docker/dockerfile:1.7

# Stable ORFS bundle used only as a source for the matched OpenROAD binary and
# flow files. The final FlexSoC image remains Ubuntu 24.04 and keeps its own
# pinned Yosys; the ORFS image's Yosys is never copied.
ARG ORFS_IMAGE=docker.io/openroad/orfs@sha256:92df0ca02e0b1174f3a34b9141160a7f95fd6d5c1a9a1e67d0961a08f256f4ff
FROM ${ORFS_IMAGE} AS orfs-upstream

FROM ubuntu:24.04 AS toolchain-prereqs

ARG DEBIAN_FRONTEND=noninteractive
ARG FLEXSOC_JOBS=2
ARG UV_VERSION=0.10.0
ARG SOURCE_URL=""

LABEL org.opencontainers.image.title="FlexSoC CI toolchain" \
      org.opencontainers.image.description="Pinned FlexSoC EDA and Python test environment" \
      org.opencontainers.image.source="$SOURCE_URL"

WORKDIR /opt/flexsoc-build
COPY src/flexsoc/backend/deps.sh src/flexsoc/backend/toolchain.lock ./toolchain/

# Commit host prerequisites as their own reusable layer. Apt metadata and package
# archives stay in BuildKit caches instead of being downloaded on every retry.
RUN --mount=type=cache,id=flexsoc-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    bash ./toolchain/deps.sh bootstrap --system --profile base

FROM toolchain-prereqs AS toolchain-installed

# Both source/build trees and partially completed installations are persistent
# BuildKit caches. If a tool fails, the next invocation resumes from the markers
# already written by deps.sh instead of recompiling completed tools. The current
# lock-specific prefix is exported into the image layer as a checkpoint tarball.
RUN --mount=type=cache,id=flexsoc-toolchain-build,target=/var/cache/flexsoc,sharing=locked \
    --mount=type=cache,id=flexsoc-toolchain-prefix,target=/opt/flexsoc/toolchains,sharing=locked \
    bash ./toolchain/deps.sh install --system --profile base --jobs "$FLEXSOC_JOBS" \
 && prefix="$(readlink -f /opt/flexsoc/toolchain)" \
 && toolchain_id="$(basename "$prefix")" \
 && printf '%s\n' "$toolchain_id" > /opt/flexsoc-toolchain.id \
 && tar --numeric-owner -C /opt/flexsoc/toolchains -cpf /opt/flexsoc-toolchain.tar "$toolchain_id"

# Materialize the checkpoint outside the cache mount so it belongs to the image.
RUN toolchain_id="$(cat /opt/flexsoc-toolchain.id)" \
 && rm -rf /opt/flexsoc/toolchains /opt/flexsoc/toolchain \
 && mkdir -p /opt/flexsoc/toolchains \
 && tar --numeric-owner -C /opt/flexsoc/toolchains -xpf /opt/flexsoc-toolchain.tar \
 && ln -sfn "/opt/flexsoc/toolchains/$toolchain_id" /opt/flexsoc/toolchain \
 && rm -f /opt/flexsoc-toolchain.tar /opt/flexsoc-toolchain.id

FROM toolchain-installed AS implementation-installed

ARG DEBIAN_FRONTEND=noninteractive
ARG ORFS_IMAGE
ARG KLAYOUT_VERSION=0.28.16-0ubuntu0.24.04.1

# KLayout is supplied by Ubuntu 24.04. OpenROAD and ORFS are copied from one
# pinned official ORFS image so their revisions stay paired. OpenROAD's runtime
# libraries are isolated under the FlexSoC prefix and embedded through RPATH;
# no global LD_LIBRARY_PATH changes are needed for the rest of the toolchain.
RUN --mount=type=cache,id=flexsoc-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    apt-get update \
 && apt-get install -y --no-install-recommends \
      bc file jq "klayout=$KLAYOUT_VERSION" patchelf rsync time \
 && rm -rf /var/lib/apt/lists/*

RUN --mount=from=orfs-upstream,source=/,target=/mnt/orfs,ro \
    set -eux; \
    prefix="$(readlink -f /opt/flexsoc/toolchain)"; \
    upstream_root=/mnt/orfs/OpenROAD-flow-scripts/tools/install/OpenROAD; \
    upstream_bin="$upstream_root/bin/openroad"; \
    private_lib="$prefix/lib/openroad"; \
    orfs_root="$prefix/share/orfs"; \
    test -x "$upstream_bin"; \
    test -f /mnt/orfs/OpenROAD-flow-scripts/flow/Makefile; \
    install -d "$prefix/bin" "$private_lib" "$orfs_root" "$prefix/.flexsoc"; \
    install -m 0755 "$upstream_bin" "$prefix/bin/openroad"; \
    if test -d "$upstream_root/share/openroad"; then \
      rm -rf "$prefix/share/openroad"; \
      cp -a "$upstream_root/share/openroad" "$prefix/share/"; \
    fi; \
    cp -a /mnt/orfs/OpenROAD-flow-scripts/flow "$orfs_root/"; \
    rm -rf "$orfs_root/flow/designs" "$orfs_root/flow/test" "$orfs_root/flow/tutorials"; \
    pass=1; \
    while :; do \
      LD_LIBRARY_PATH="$private_lib" ldd "$prefix/bin/openroad" > /tmp/openroad.ldd; \
      missing="$(awk '$2 == "=>" && $3 == "not" { print $1 }' /tmp/openroad.ldd)"; \
      test -n "$missing" || break; \
      test "$pass" -le 8; \
      for soname in $missing; do \
        source=; \
        for directory in \
          "$upstream_root/lib" \
          "$upstream_root/lib64" \
          /mnt/orfs/usr/local/lib \
          /mnt/orfs/usr/lib/x86_64-linux-gnu \
          /mnt/orfs/lib/x86_64-linux-gnu \
          /mnt/orfs/opt/or-tools/lib; do \
          test -d "$directory" || continue; \
          source="$(find "$directory" -name "$soname" -print -quit)"; \
          test -z "$source" || break; \
        done; \
        test -n "$source"; \
        cp -L "$source" "$private_lib/$soname"; \
      done; \
      pass=$((pass + 1)); \
    done; \
    patchelf --force-rpath --set-rpath '$ORIGIN/../lib/openroad' "$prefix/bin/openroad"; \
    ldd "$prefix/bin/openroad" | tee /tmp/openroad.ldd; \
    ! grep -q 'not found' /tmp/openroad.ldd; \
    ln -sfn /usr/bin/klayout "$prefix/bin/klayout"; \
    "$prefix/bin/openroad" -version | tee "$prefix/.flexsoc/openroad.version"; \
    "$prefix/bin/klayout" -v | tee "$prefix/.flexsoc/klayout.version"; \
    printf '%s\n' "${ORFS_IMAGE#docker.io/}" > "$prefix/.flexsoc/orfs.image"; \
    rm -f /tmp/openroad.ldd

FROM implementation-installed AS toolchain-verified

# Always verify an external checkpoint with the current repository's doctor
# and lock file. This matters when toolchain-installed is supplied through a
# named BuildKit context rather than built from this Dockerfile invocation.
COPY src/flexsoc/backend/deps.sh src/flexsoc/backend/toolchain.lock ./toolchain/

# Verification is deliberately separate from installation. A doctor failure does
# not invalidate the installed-toolchain checkpoint built by the previous stage.
RUN bash ./toolchain/deps.sh doctor --system --profile base \
 && /opt/flexsoc/toolchain/bin/openroad -version \
 && /opt/flexsoc/toolchain/bin/klayout -v \
 && test -f /opt/flexsoc/toolchain/share/orfs/flow/Makefile

FROM toolchain-verified AS runtime

# The external toolchain-installed named context breaks ARG inheritance from
# toolchain-prereqs, so declare the runtime build argument in this stage too.
ARG UV_VERSION=0.10.0

RUN --mount=type=cache,id=flexsoc-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    apt-get update \
 && apt-get install -y --no-install-recommends python3 python3-pip python3-venv \
 && python3 -m venv /opt/uv \
 && /opt/uv/bin/pip install --no-cache-dir "uv==$UV_VERSION"

COPY pyproject.toml uv.lock README.md /opt/flexsoc-python/
WORKDIR /opt/flexsoc-python
ENV UV_PROJECT_ENVIRONMENT=/opt/flexsoc-venv
RUN --mount=type=cache,id=flexsoc-uv-cache,target=/root/.cache/uv,sharing=locked \
    /opt/uv/bin/uv sync --frozen --no-install-project

ENV DEPS_MODE=system \
    FLEXSOC_TOOLCHAIN=/opt/flexsoc/toolchain \
    ORFS_ROOT=/opt/flexsoc/toolchain/share/orfs \
    OPENROAD_EXE=/opt/flexsoc/toolchain/bin/openroad \
    YOSYS_EXE=/opt/flexsoc/toolchain/bin/yosys \
    KLAYOUT_CMD=/opt/flexsoc/toolchain/bin/klayout \
    VIRTUAL_ENV=/opt/flexsoc-venv \
    PATH=/opt/flexsoc/toolchain/bin:/opt/flexsoc-venv/bin:/opt/uv/bin:${PATH} \
    LD_LIBRARY_PATH=/opt/flexsoc/toolchain/lib:/opt/flexsoc/toolchain/lib64 \
    CMAKE_PREFIX_PATH=/opt/flexsoc/toolchain \
    PKG_CONFIG_PATH=/opt/flexsoc/toolchain/lib/pkgconfig:/opt/flexsoc/toolchain/lib64/pkgconfig:/opt/flexsoc/toolchain/share/pkgconfig \
    PYTHONUNBUFFERED=1 \
    FLEXSOC_E2E_LIVE=0

WORKDIR /workspace
CMD ["bash"]
