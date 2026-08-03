# syntax=docker/dockerfile:1.7
FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive
ARG FLEXSOC_JOBS=2
ARG UV_VERSION=0.10.0
ARG SOURCE_URL=""

LABEL org.opencontainers.image.title="FlexSoC CI toolchain" \
      org.opencontainers.image.description="Pinned FlexSoC EDA and Python test environment" \
      org.opencontainers.image.source="$SOURCE_URL"

WORKDIR /opt/flexsoc-build
COPY src/flexsoc/backend/deps.sh src/flexsoc/backend/toolchain.lock ./toolchain/

RUN bash ./toolchain/deps.sh bootstrap --system --profile base \
 && bash ./toolchain/deps.sh install --system --profile base --jobs "$FLEXSOC_JOBS" \
 && bash ./toolchain/deps.sh doctor --system --profile base \
 && rm -rf /var/cache/flexsoc /var/lib/apt/lists/*

RUN apt-get update \
 && apt-get install -y --no-install-recommends python3 python3-pip python3-venv \
 && rm -rf /var/lib/apt/lists/* \
 && python3 -m venv /opt/uv \
 && /opt/uv/bin/pip install --no-cache-dir "uv==$UV_VERSION"

COPY pyproject.toml uv.lock README.md /opt/flexsoc-python/
WORKDIR /opt/flexsoc-python
ENV UV_PROJECT_ENVIRONMENT=/opt/flexsoc-venv
RUN /opt/uv/bin/uv sync --frozen --no-install-project

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
