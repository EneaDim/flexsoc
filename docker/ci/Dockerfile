# syntax=docker/dockerfile:1.7

ARG UV_VERSION=0.9.29

# Build the ORFS-matched OpenROAD revision on the same Ubuntu 24.04 base used
# by the final FlexSoC image. Only the OpenROAD submodule is initialized; the
# ORFS Yosys submodule is never downloaded or built.
FROM ubuntu:24.04 AS implementation-builder

ARG DEBIAN_FRONTEND=noninteractive
ARG FLEXSOC_JOBS=2

COPY src/flexsoc/backend/core/toolchain.lock /tmp/toolchain.lock

RUN --mount=type=cache,id=flexsoc-impl-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-impl-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    apt-get update \
 && apt-get install -y --no-install-recommends ca-certificates git

WORKDIR /src

RUN set -eux; \
    . /tmp/toolchain.lock; \
    git clone --filter=blob:none --no-checkout "$ORFS_REPO" /src/orfs; \
    matches="$(git -C /src/orfs rev-list --all | grep "^${ORFS_REF_PREFIX}")"; \
    test "$(printf '%s\n' "$matches" | grep -c .)" -eq 1; \
    orfs_ref="$matches"; \
    git -C /src/orfs checkout --detach "$orfs_ref"; \
    required_klayout="$(sed -n 's/^[^=]*klayoutVersion[^=]*=[^0-9]*\([0-9][0-9.]*\).*$/\1/p' /src/orfs/etc/DependencyInstaller.sh | head -n 1)"; \
    test -n "$required_klayout"; \
    test "$required_klayout" = "$KLAYOUT_VERSION" || { \
      echo "KLayout lock mismatch: ORFS requires $required_klayout, FlexSoC locks $KLAYOUT_VERSION" >&2; \
      exit 2; \
    }; \
    printf '%s\n' "$required_klayout" > /src/orfs-klayout.version; \
    openroad_ref="$(git -C /src/orfs ls-tree HEAD tools/OpenROAD | awk '{print $3}')"; \
    test -n "$openroad_ref"; \
    case "$openroad_ref" in "$OPENROAD_REF_PREFIX"*) ;; *) exit 2 ;; esac; \
    git -C /src/orfs submodule update --init --recursive --depth=1 tools/OpenROAD \
      || git -C /src/orfs submodule update --init --recursive tools/OpenROAD; \
    test "$(git -C /src/orfs/tools/OpenROAD rev-parse HEAD)" = "$openroad_ref"; \
    printf '%s\n' "$orfs_ref" > /src/orfs.ref; \
    printf '%s\n' "$openroad_ref" > /src/openroad.ref; \
    test -f /src/orfs/flow/Makefile

RUN --mount=type=cache,id=flexsoc-impl-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-impl-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    cd /src/orfs/tools/OpenROAD \
 && ./etc/DependencyInstaller.sh -base -threads="$FLEXSOC_JOBS"

RUN cd /src/orfs/tools/OpenROAD \
 && ./etc/DependencyInstaller.sh \
      -common \
      -prefix=/opt/openroad-deps \
      -threads="$FLEXSOC_JOBS" \
      -save-deps-prefixes=/tmp/openroad_deps_prefixes.txt

RUN set -eux; \
    export PATH="/opt/openroad-deps/bin:$PATH"; \
    export LD_LIBRARY_PATH="/opt/openroad-deps/lib:/opt/openroad-deps/lib64${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"; \
    cd /src/orfs/tools/OpenROAD; \
    for command_name in cmake bison flex swig gcc g++; do \
      command -v "$command_name"; \
    done; \
    if ! ./etc/Build.sh \
      -cmake-build \
      -no-gui \
      -no-tests \
      -threads="$FLEXSOC_JOBS" \
      -dir=/tmp/openroad-build \
      -prefix=/opt/openroad-install \
      -deps-prefixes-file=/tmp/openroad_deps_prefixes.txt \
      -cmake='-DLINK_TIME_OPTIMIZATION=OFF'; then \
      echo "===== OpenROAD build log ====="; \
      cat /tmp/openroad-build/openroad_build.log 2>/dev/null || true; \
      exit 1; \
    fi; \
    cmake --install /tmp/openroad-build --strip; \
    /opt/openroad-install/bin/openroad -version

FROM ubuntu:24.04 AS toolchain-prereqs

ARG DEBIAN_FRONTEND=noninteractive
ARG FLEXSOC_JOBS=2
ARG SOURCE_URL=""

LABEL org.opencontainers.image.title="FlexSoC CI toolchain" \
      org.opencontainers.image.description="Pinned FlexSoC EDA and Python test environment" \
      org.opencontainers.image.source="$SOURCE_URL"

WORKDIR /opt/flexsoc-build
COPY src/flexsoc/backend/core/deps.sh src/flexsoc/backend/core/toolchain.lock ./toolchain/

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

COPY src/flexsoc/backend/core/toolchain.lock /tmp/implementation-toolchain.lock

# KLayout and the ORFS Python/runtime utilities are installed on Ubuntu 24.04.
# OpenROAD and its non-system shared libraries are copied from the Ubuntu 24.04
# builder stage into the existing versioned FlexSoC toolchain prefix.
RUN --mount=type=cache,id=flexsoc-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    set -eux; \
    . /tmp/implementation-toolchain.lock; \
    apt-get update; \
    apt-get install -y --no-install-recommends \
      bc ca-certificates curl file jq patchelf rsync ruby time \
      tcl-tclreadline \
      python3-click python3-numpy python3-pandas python3-yaml python3-yamlfix; \
    curl --fail --location --retry 3 "$KLAYOUT_URL" -o /tmp/klayout.deb; \
    printf '%s  %s\n' "$KLAYOUT_MD5" /tmp/klayout.deb | md5sum --check --strict; \
    apt-get install -y --no-install-recommends /tmp/klayout.deb; \
    installed_klayout="$(klayout -b -v | grep -oE '[0-9]+(\.[0-9]+)+')"; \
    test "$installed_klayout" = "$KLAYOUT_VERSION" || { \
      echo "KLayout install mismatch: installed $installed_klayout, locked $KLAYOUT_VERSION" >&2; \
      exit 2; \
    }; \
    rm -f /tmp/klayout.deb; \
    rm -rf /var/lib/apt/lists/*

RUN --mount=from=implementation-builder,source=/,target=/mnt/implementation,ro \
    set -eux; \
    prefix="$(readlink -f /opt/flexsoc/toolchain)"; \
    private_lib="$prefix/lib/openroad"; \
    orfs_root="$prefix/share/orfs"; \
    install -d "$prefix/bin" "$private_lib" "$orfs_root" "$prefix/.flexsoc"; \
    cp -a /mnt/implementation/opt/openroad-install/. "$prefix/"; \
    cp -a /mnt/implementation/src/orfs/flow "$orfs_root/"; \
    install -m 0644 /mnt/implementation/src/orfs.ref "$prefix/.flexsoc/orfs.ref"; \
    install -m 0644 /mnt/implementation/src/orfs-klayout.version "$prefix/.flexsoc/orfs-klayout.version"; \
    install -m 0644 /mnt/implementation/src/openroad.ref "$prefix/.flexsoc/openroad.ref"; \
    pass=1; \
    while :; do \
      LD_LIBRARY_PATH="$private_lib:$prefix/lib:$prefix/lib64" \
        ldd "$prefix/bin/openroad" > /tmp/openroad.ldd; \
      missing="$(awk '$2 == "=>" && $3 == "not" { print $1 }' /tmp/openroad.ldd)"; \
      test -n "$missing" || break; \
      test "$pass" -le 12; \
      for soname in $missing; do \
        source=; \
        for directory in \
          /mnt/implementation/opt/openroad-deps/lib \
          /mnt/implementation/opt/openroad-deps/lib64 \
          /mnt/implementation/usr/local/lib \
          /mnt/implementation/usr/lib/x86_64-linux-gnu \
          /mnt/implementation/lib/x86_64-linux-gnu; do \
          test -d "$directory" || continue; \
          source="$(find "$directory" -name "$soname" -print -quit)"; \
          test -z "$source" || break; \
        done; \
        test -n "$source"; \
        cp -L "$source" "$private_lib/$soname"; \
      done; \
      pass=$((pass + 1)); \
    done; \
    patchelf --force-rpath \
      --set-rpath '$ORIGIN/../lib/openroad:$ORIGIN/../lib:$ORIGIN/../lib64' \
      "$prefix/bin/openroad"; \
    ldd "$prefix/bin/openroad" | tee /tmp/openroad.ldd; \
    ! grep -q 'not found' /tmp/openroad.ldd; \
    ln -sfn /usr/bin/klayout "$prefix/bin/klayout"; \
    "$prefix/bin/openroad" -version | tee "$prefix/.flexsoc/openroad.version"; \
    "$prefix/bin/klayout" -b -v | tee "$prefix/.flexsoc/klayout.version"; \
    rm -f /tmp/openroad.ldd /tmp/implementation-toolchain.lock

FROM implementation-installed AS toolchain-verified

# Always verify an external checkpoint with the current repository's doctor
# and lock file.
COPY src/flexsoc/backend/core/deps.sh src/flexsoc/backend/core/toolchain.lock ./toolchain/

RUN FLEXSOC_TOOLCHAIN=/opt/flexsoc/toolchain \
    bash ./toolchain/deps.sh doctor --system --profile base \
 && /opt/flexsoc/toolchain/bin/sta -version \
 && /opt/flexsoc/toolchain/bin/openroad -version \
 && /opt/flexsoc/toolchain/bin/klayout -b -v \
 && test -s /opt/flexsoc/toolchain/.flexsoc/openroad.ref \
 && test -s /opt/flexsoc/toolchain/.flexsoc/orfs.ref \
 && test -s /opt/flexsoc/toolchain/.flexsoc/orfs-klayout.version \
 && bash -c '. ./toolchain/toolchain.lock; test "$(cat /opt/flexsoc/toolchain/.flexsoc/orfs-klayout.version)" = "$KLAYOUT_VERSION"' \
 && test -f /opt/flexsoc/toolchain/share/orfs/flow/Makefile \
 && test -f /opt/flexsoc/toolchain/share/orfs/flow/designs/nangate45/gcd/config.mk

FROM toolchain-verified AS runtime

# The external toolchain-installed named context breaks ARG inheritance from
# toolchain-prereqs, so declare the runtime build argument in this stage too.
ARG UV_VERSION

RUN --mount=type=cache,id=flexsoc-apt-cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,id=flexsoc-apt-lists,target=/var/lib/apt/lists,sharing=locked \
    apt-get update \
 && apt-get install -y --no-install-recommends python3 python3-pip python3-venv \
 && python3 -m venv /opt/uv \
 && /opt/uv/bin/pip install --no-cache-dir "uv==$UV_VERSION" \
 && /opt/uv/bin/uv --version | grep -F "uv $UV_VERSION"

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
