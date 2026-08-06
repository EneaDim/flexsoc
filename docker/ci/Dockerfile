# syntax=docker/dockerfile:1.7

# Build the ORFS-matched OpenROAD revision on the same Ubuntu 24.04 base used
# by the final FlexSoC image. Only the OpenROAD submodule is initialized; the
# ORFS Yosys submodule is never downloaded or built.
FROM ubuntu:24.04 AS implementation-builder

ARG DEBIAN_FRONTEND=noninteractive
ARG FLEXSOC_JOBS=2

COPY src/flexsoc/backend/toolchain.lock /tmp/toolchain.lock

RUN --mount=type=cache,id=flexsoc-impl-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-impl-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    apt-get update \
 && apt-get install -y --no-install-recommends ca-certificates git

WORKDIR /src

RUN FLEXSOC_TOOLCHAIN=/opt/flexsoc/toolchain \
    bash ./toolchain/deps.sh doctor --system --profile base \
 && /opt/flexsoc/toolchain/bin/openroad -version \
 && /opt/flexsoc/toolchain/bin/sta -version \
 && /opt/flexsoc/toolchain/bin/klayout -b -v \
 && test -s /opt/flexsoc/toolchain/.flexsoc/openroad.ref \
 && test -s /opt/flexsoc/toolchain/.flexsoc/orfs.ref \
 && test -f /opt/flexsoc/toolchain/share/orfs/flow/Makefile \
 && test -f /opt/flexsoc/toolchain/share/orfs/flow/designs/nangate45/gcd/config.mk

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
    PYTHON_EXE=/usr/bin/python3 \
    VIRTUAL_ENV=/opt/flexsoc-venv \
    PATH=/opt/flexsoc/toolchain/bin:/opt/flexsoc-venv/bin:/opt/uv/bin:${PATH} \
    LD_LIBRARY_PATH=/opt/flexsoc/toolchain/lib:/opt/flexsoc/toolchain/lib64 \
    CMAKE_PREFIX_PATH=/opt/flexsoc/toolchain \
    PKG_CONFIG_PATH=/opt/flexsoc/toolchain/lib/pkgconfig:/opt/flexsoc/toolchain/lib64/pkgconfig:/opt/flexsoc/toolchain/share/pkgconfig \
    PYTHONUNBUFFERED=1 \
    FLEXSOC_E2E_LIVE=0

WORKDIR /workspace
CMD ["bash"]
