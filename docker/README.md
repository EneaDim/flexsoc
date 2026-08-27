# FlexSoC Docker Image and CI

FlexSoC uses a prebuilt Docker image containing the pinned EDA toolchain and
Python dependencies required by the project.

Image creation and project testing are intentionally separated:

```text
Toolchain gate:
validate frozen image → build/verify/publish only when stale → dispatch CI

Project CI:
checkout commit → validate/pull locked image → mount source code → make lint/test
```

The Docker workflow validates only the EDA/runtime environment. It never runs
the FlexSoC project test suite. Once the frozen image is current, normal pushes
reuse its immutable digest and go directly to `ci.yml`.

---

## Directory structure

```text
docker/
├── ci/
│   ├── Dockerfile
│   ├── Dockerfile.dockerignore
│   └── image.lock
└── scripts/
    ├── build.sh
    ├── common.sh
    ├── publish.sh
    ├── run-ci.sh
    └── verify.sh
```

---

## Script responsibilities

### `build.sh`

Builds the Docker image.

It builds the runtime image from deterministic toolchain stages. In GitHub CI,
completed expensive stages are persisted automatically as GHCR checkpoints and
reused when their own inputs are unchanged.

It produces the final local runtime image but does not run the project tests.

### `verify.sh`

Performs a technical smoke test of the built image.

It verifies:

- every locked base-tool version;
- Icarus 13 `-ginterconnect` support required by routed GLS;
- OpenSTA and the OpenROAD/ORFS locked revisions;
- the exact KLayout version locked by FlexSoC and the KLayout version required by the selected ORFS checkout;
- the Python runtime, `uv`, and virtual environment;
- a small ORFS floorplan smoke flow.

It does not run Ruff or pytest.

### `publish.sh`

Publishes the verified runtime image to GitHub Container Registry.

It:

1. checks that the current image was successfully verified;
2. pushes the image to GHCR;
3. resolves the immutable registry digest;
4. generates `docker/ci/image.lock`.

It does not run the project tests.

### `run-ci.sh`

Runs the project validation inside the locked Docker image.

It:

1. mounts the checked-out repository at `/workspace`;
2. installs the current FlexSoC source tree in editable mode;
3. runs both the locked dependency doctor and `fx doctor`;
4. runs `make lint` and `make test-api`;
5. collects the E2E tests;
6. runs `make test E2E_ORS="$ORFS_ROOT/flow"` for full CI.

This is the only Docker script that runs project tests.

### `common.sh`

Contains shared functions for:

- calculating the image input hash;
- generating image names and tags;
- locating the GHCR repository;
- validating `image.lock`;
- resolving immutable image references.

---


### GitHub-hosted checkpoints and build cache

When an image refresh is required, GitHub persists three independent checkpoints:

```text
base toolchain → OpenROAD/ORFS builder → implementation image → runtime image
```

The base and OpenROAD tags are derived only from the inputs of those stages. A
change in a later runtime-copy step therefore does not invalidate a completed
45+ minute OpenROAD build. `build.sh` checks GHCR before each expensive stage and
uses Docker named build contexts to replace an already completed Dockerfile stage
with the frozen checkpoint image.

BuildKit registry cache remains enabled as a secondary optimization for layers
inside a stage. The explicit checkpoint images are the retry boundary; they are
useful even when a later build command fails before BuildKit can export its cache.

`image.lock` still records only the final verified runtime image digest. Stage
checkpoints are build artifacts, not the project CI runtime contract.

### OpenROAD runtime closure

The pinned OpenROAD dependency installer is invoked with
`-prefix=/opt/openroad-deps`, so its OR-Tools runtime is nested under
`/opt/openroad-deps/or-tools/lib`. The final image copies only shared libraries
required by `openroad` into the private FlexSoC toolchain runtime path and verifies
the result with `ldd`.

### ORFS / KLayout compatibility contract

The implementation image treats the selected ORFS checkout as the authority for
the minimum KLayout version. During the image build FlexSoC reads
`etc/DependencyInstaller.sh` from that exact ORFS revision and requires its
`klayoutVersion` to match `KLAYOUT_VERSION` in `toolchain.lock`. The build aborts
on any mismatch. The required version is stored in the image as
`/opt/flexsoc/toolchain/.flexsoc/orfs-klayout.version` and `verify.sh` checks the
receipt again against both the lock and the installed `klayout` binary.

This keeps local Physical Sign-Off and Docker/CI on the same native ORFS tool
contract; no platform CDL, LVS deck, or standard-cell collateral is rewritten.

## Image workflow

The image workflow is defined in:

```text
.github/workflows/toolchain-image.yml
```

It is the **toolchain gate** for `main` and is also available manually:

```yaml
on:
  push:
    branches: [main]
  workflow_dispatch:
```

Its only responsibility is the Docker/EDA environment. It does **not** run the
FlexSoC project test suite.

For every push to `main` it first checks:

1. whether `docker/ci/image.lock` matches the current image inputs;
2. whether the immutable `repository@sha256:digest` still exists on GHCR.

If both checks pass, the toolchain is already frozen:

```text
checkout
→ validate image.lock
→ verify frozen digest exists on GHCR
→ no build
→ no image verification rerun
→ dispatch ci.yml
```

This is the normal path for source-only FlexSoC changes.

If the lock is stale, missing, or the frozen digest is unavailable, the workflow
refreshes the toolchain:

```text
checkout
→ build Docker toolchain
→ verify tool versions/capabilities
→ publish runtime image
→ resolve immutable digest
→ update + commit image.lock
→ dispatch ci.yml
```

The image is therefore built only when one of its declared inputs changes. A
normal push does not rebuild Yosys, Verilator, OpenROAD, etc.

`workflow_dispatch` also provides `force_rebuild=true` for an explicit refresh
of the final image. Expensive stage checkpoints are discovered and reused
automatically; no checkpoint reference needs to be supplied manually.

---

## Project CI workflow

The project CI workflow is defined in:

```text
.github/workflows/ci.yml
```

On `main`, `ci.yml` is dispatched **only after the toolchain gate is green**.
It is also available directly for pull requests and manual runs.

The workflow executes:

```text
checkout requested branch/commit
→ validate image.lock
→ pull repository@immutable-digest
→ mount the repository at /workspace
→ install the current FlexSoC source tree
→ run Ruff / API / E2E tests
```

Toolchain creation and project testing stay separate:

```text
main push
   ↓
toolchain-image.yml
   ├─ frozen image current → no-op
   └─ toolchain changed    → build + verify + freeze
   ↓
ci.yml
   ↓
all FlexSoC tests inside the frozen image
```

The source code is not permanently copied into the Docker image. GitHub Actions
checks out the current FlexSoC source and `run-ci.sh` mounts it into the frozen
environment. No `git pull` is performed inside the container.

---

## Immutable image lock

The file:

```text
docker/ci/image.lock
```

records the final verified image by immutable registry digest:

```text
schema=1
inputs_sha256=<complete-input-hash>
repository=ghcr.io/eneadim/flexsoc/flexsoc-ci
tag=toolchain-<short-input-hash>
digest=sha256:<registry-digest>
```

The human-readable tag is not the CI contract. Project CI consumes:

```text
repository@sha256:digest
```

The image inputs are intentionally narrow:

```text
docker/ci/Dockerfile
docker/ci/Dockerfile.dockerignore
src/flexsoc/backend/core/deps.sh
src/flexsoc/backend/core/toolchain.lock
pyproject.toml
uv.lock
```

Changes to normal FlexSoC Python/RTL/test sources therefore do not rebuild the
EDA image. Changes to the Docker environment, locked tool versions, or Python
runtime dependencies invalidate the lock and cause one new frozen image to be
built.

---

## Local commands

### Complete image build

```bash
FLEXSOC_JOBS=2 docker/scripts/build.sh
```

### Build checkpoints

On GitHub, stage checkpoints are automatic. `build.sh` probes GHCR and only
builds a checkpoint whose stage-specific hash is missing. A local build can
still use the ordinary BuildKit layer cache; no checkpoint reference is needed.

### Verify the image runtime

```bash
docker/scripts/verify.sh
```

This command performs only the technical image smoke test.

### Publish the image

Using `GH_TOKEN`:

```bash
export GH_TOKEN="<token-with-write-packages-permission>"

docker/scripts/publish.sh

unset GH_TOKEN
```

Alternatively, use `GHCR_TOKEN` and `GHCR_USER`:

```bash
export GHCR_USER="eneadim"
export GHCR_TOKEN="<token-with-write-packages-permission>"

docker/scripts/publish.sh

unset GHCR_TOKEN
unset GHCR_USER
```

### Run CI using the locked image

```bash
docker/scripts/run-ci.sh
```

### Run the complete E2E suite

```bash
FULL_E2E=1 docker/scripts/run-ci.sh
```

---

## Expected development flow

### Toolchain or dependency update

When the Dockerfile, toolchain lock, dependency installer, `pyproject.toml`, or
`uv.lock` changes:

```text
push the source changes to a branch
→ run the manual toolchain-image workflow on that branch with `force_rebuild=true` only when an explicit refresh is required
→ GitHub builds and verifies the runtime image
→ GitHub publishes it and commits image.lock on the same branch
→ the image workflow dispatches ci.yml on the locked commit
```

After a tool revision changes, only checkpoints whose stage-specific inputs still
match are reused. A changed revision automatically rebuilds the affected stage.

### Normal source-code update

When FlexSoC source code or tests change:

```text
commit and push the source changes
→ project CI pulls the existing locked image
→ project CI mounts the new commit
→ project CI runs Ruff and pytest
```

The Docker image is not rebuilt for ordinary source-code changes.
