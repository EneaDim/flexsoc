# FlexSoC container toolchain

All Docker implementation files live under this directory. GitHub workflow entry points must remain under `.github/workflows/`, because GitHub only discovers workflows there; those files delegate to the scripts in `docker/scripts/`.

## Layout

```text
docker/
├── .gitignore
├── README.md
├── ci/
│   ├── Dockerfile
│   ├── Dockerfile.dockerignore
│   └── image.lock
└── scripts/
    ├── build.sh
    ├── check-lock.sh
    ├── common.sh
    ├── cleanup-managed-toolchain.sh
    ├── image-ref.sh
    ├── inspect.sh
    ├── preflight.sh
    ├── publish.sh
    ├── run-ci.sh
    ├── system-inventory.sh
    └── verify.sh
```

`image.lock` is the only registry reference consumed by normal CI. It records the image input hash and the immutable GHCR digest. Normal CI never builds the EDA image.

## Host, build, verification, cleanup, and release sequence

The container is the CI and release authority. Host EDA executables are useful only as a compatibility fallback and are deliberately inspected without searching `~/.local/share/flexsoc`:

```bash
# 1. Inventory host fallback tools without the FlexSoC managed prefix.
docker/scripts/system-inventory.sh

# 2. Check Docker, WSL resources, free disk, and current Docker usage.
docker/scripts/preflight.sh

# 3. Build the content-addressed local image. build.sh repeats preflight.
FLEXSOC_JOBS=2 docker/scripts/build.sh

# 4. Run the pinned tool doctor, Ruff, API tests and E2E collection inside it.
docker/scripts/verify.sh

# Strongly recommended before publishing a release image.
FULL_E2E=1 docker/scripts/verify.sh

# 5. Inspect the local identity and current lock.
docker/scripts/inspect.sh

# 6. After Docker verification, preview removal of the incomplete/user-managed native toolchain.
docker/scripts/cleanup-managed-toolchain.sh

# Apply only after reviewing the paths printed by the dry-run.
APPLY=1 docker/scripts/cleanup-managed-toolchain.sh

# 7. Authenticate and publish only the previously verified image.
export GHCR_USER=<github-user>
read -rsp 'GHCR token: ' GHCR_TOKEN; echo
export GHCR_TOKEN
docker/scripts/publish.sh
unset GHCR_TOKEN

# 8. Verify the generated immutable lock and commit it.
docker/scripts/check-lock.sh
git add docker/ci/image.lock
git commit -m 'ci: lock verified FlexSoC toolchain image'
```

The token needs permission to write the package when publishing from the command line. The publish script refuses an unverified image, a stale verification record, changed image inputs, or an already existing content tag unless explicitly allowed.

## Run the locked image locally

```bash
docker/scripts/run-ci.sh
FULL_E2E=1 docker/scripts/run-ci.sh
```


## Dependency model

The host needs Docker Engine or Docker Desktop with Buildx, Git, Bash, and enough WSL/Docker disk and memory. It does not need a second pinned EDA installation. `docker/scripts/system-inventory.sh` reports which non-FlexSoC-managed host tools are available, but they are not the CI/release authority.

The image builds the `base` profile from `src/flexsoc/backend/toolchain.lock`. `deps.sh bootstrap --system` installs compiler and development prerequisites inside the image, then `deps.sh install --system` builds the exact pinned EDA revisions under `/opt/flexsoc/toolchains/<lock-id>`. The Docker build runs the managed `deps.sh doctor` before accepting the layer.

GTKWave 3.3 is configured explicitly with `--enable-gtk3`; the GTKWave upstream build instructions require GTK3 development packages for this source line. The same install must produce both `gtkwave` and `fst2vcd` under the managed prefix. CI power analysis calls the pinned `fst2vcd` automatically for FST traces; it never relies on `/usr/bin/fst2vcd` from the host.

The host cleanup script removes only FlexSoC user-managed toolchain prefixes and build caches after a local Docker image has been verified against the current input hash. It cannot remove `/usr`, `/usr/local`, the repository virtual environment, or Docker data.

## Resumable build checkpoints

The toolchain build is intentionally split into three Docker stages:

```text
toolchain-prereqs
    Ubuntu compiler and library prerequisites

toolchain-installed
    pinned EDA tools installed and exported as a local checkpoint image

toolchain-verified
    deps doctor executed against the installed checkpoint

runtime
    Python/uv environment added after the EDA doctor passes
```

`docker/scripts/build.sh` first loads `toolchain-installed` under a local
`*-installed` tag and only then builds the verified runtime image. A failure in
the doctor, Python environment, or later test layers therefore leaves a usable
local checkpoint. Re-running the same command resumes from that checkpoint.

The install stage also uses named BuildKit caches for:

- downloaded archives and Git sources;
- build trees;
- the lock-specific installed prefix and completion markers;
- apt archives and metadata;
- the uv package cache.

If compilation itself stops halfway through, completed tools remain marked in
the prefix cache and are skipped on the next run. Do not use `--no-cache`,
`docker builder prune`, or `docker buildx prune` while recovering a failed
toolchain build unless intentionally discarding the checkpoint and caches.

Inspect the retained checkpoint with:

```bash
docker/scripts/inspect.sh
docker image ls | grep -- '-installed'
```

A checkpoint is not publishable and is not accepted by normal CI. Only the
final image that passes `deps.sh doctor`, `docker/scripts/verify.sh`, and the
requested E2E verification can be published and written to `image.lock`.
