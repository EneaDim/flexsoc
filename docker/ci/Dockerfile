# syntax=docker/dockerfile:1.7
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

FROM toolchain-installed AS toolchain-verified

# Always verify an external checkpoint with the current repository's doctor
# and lock file. This matters when toolchain-installed is supplied through a
# named BuildKit context rather than built from this Dockerfile invocation.
COPY src/flexsoc/backend/deps.sh src/flexsoc/backend/toolchain.lock ./toolchain/

# Verification is deliberately separate from installation. A doctor failure does
# not invalidate the installed-toolchain checkpoint built by the previous stage.
RUN bash ./toolchain/deps.sh doctor --system --profile base

FROM toolchain-verified AS runtime

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

ENV FLEXSOC_TOOLCHAIN=/opt/flexsoc/toolchain \
    VIRTUAL_ENV=/opt/flexsoc-venv \
    PATH=/opt/flexsoc/toolchain/bin:/opt/flexsoc-venv/bin:/opt/uv/bin:${PATH} \
    LD_LIBRARY_PATH=/opt/flexsoc/toolchain/lib:/opt/flexsoc/toolchain/lib64 \
    CMAKE_PREFIX_PATH=/opt/flexsoc/toolchain \
    PKG_CONFIG_PATH=/opt/flexsoc/toolchain/lib/pkgconfig:/opt/flexsoc/toolchain/lib64/pkgconfig:/opt/flexsoc/toolchain/share/pkgconfig \
    PYTHONUNBUFFERED=1 \
    FLEXSOC_E2E_LIVE=0

WORKDIR /workspace
CMD ["bash"]
