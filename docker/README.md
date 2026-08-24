# FlexSoC Docker Image and CI

FlexSoC uses a prebuilt Docker image containing the pinned EDA toolchain and
Python dependencies required by the project.

Image creation and project testing are intentionally separated:

```text
Manual image workflow:
build → verify locked versions/capabilities → publish → generate/commit image.lock → dispatch CI

Project CI:
checkout commit → validate/pull locked image → mount source code → make lint/test
```

The Docker image workflow does not run the FlexSoC pytest suite.

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

It can either:

- build the complete EDA toolchain from source; or
- reuse an existing `toolchain-installed` checkpoint image.

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

It is manual-only:

```yaml
on:
  workflow_dispatch:
```

It is not triggered by normal source-code pushes or pull requests.

The workflow executes:

```text
checkout
→ build.sh
→ verify.sh
→ publish.sh
→ upload image.lock
→ commit image.lock on the selected branch
→ dispatch ci.yml on that branch
```

### Building from an existing checkpoint

The workflow accepts an optional `checkpoint_ref`.

Example:

```text
ghcr.io/eneadim/flexsoc/flexsoc-ci:toolchain-e6a29bb60fbb64ce-installed
```

When this value is supplied, the workflow reuses the installed EDA toolchain
instead of rebuilding it from source.

The checkpoint image ends with:

```text
-installed
```

The final runtime image does not:

```text
ghcr.io/eneadim/flexsoc/flexsoc-ci:toolchain-<inputs-hash>
```

---

## Project CI workflow

The project CI workflow is defined in:

```text
.github/workflows/ci.yml
```

It is triggered by:

- a push to `main`;
- a pull request;
- a manual workflow dispatch.

The workflow executes:

```text
checkout the requested commit
→ read and validate image.lock
→ pull the image by immutable digest
→ mount the repository at /workspace
→ install the current source tree
→ run Ruff and pytest
```

The source code is not permanently copied into the Docker image.

GitHub Actions checks out the exact commit being tested, and `run-ci.sh` mounts
that checkout into the container.

No `git pull` is performed inside the container.

---

## Immutable image lock

The file:

```text
docker/ci/image.lock
```

records the final image using its immutable registry digest.

Example:

```text
schema=1
inputs_sha256=<complete-input-hash>
repository=ghcr.io/eneadim/flexsoc/flexsoc-ci
tag=toolchain-<short-input-hash>
digest=sha256:<registry-digest>
```

The tag is useful for humans, but CI uses:

```text
repository@sha256:digest
```

This ensures that CI always uses the exact image that was verified and
published.

Whenever one of the image inputs changes, CI rejects the stale lock. Run the
manual toolchain-image workflow with `publish=true`; it publishes the runtime
image, commits the new `image.lock`, and dispatches CI on the same branch.

The image inputs are:

```text
docker/ci/Dockerfile
docker/ci/Dockerfile.dockerignore
src/flexsoc/backend/core/deps.sh
src/flexsoc/backend/core/toolchain.lock
pyproject.toml
uv.lock
```

Ordinary changes to FlexSoC source files or tests do not require rebuilding the
Docker image.

---

## Local commands

### Complete image build

```bash
FLEXSOC_JOBS=2 docker/scripts/build.sh
```

### Build from an existing checkpoint

```bash
TOOLCHAIN_CHECKPOINT_IMAGE=\
ghcr.io/eneadim/flexsoc/flexsoc-ci:toolchain-e6a29bb60fbb64ce-installed \
docker/scripts/build.sh
```

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
→ run the manual toolchain-image workflow on that branch with publish=true
→ GitHub builds and verifies the runtime image
→ GitHub publishes it and commits image.lock on the same branch
→ the image workflow dispatches ci.yml on the locked commit
```

Leave `checkpoint_ref` empty after a tool revision changes so the first image is
rebuilt from the pinned sources. Reuse a checkpoint only when its installed
toolchain is known to match the current lock.

### Normal source-code update

When FlexSoC source code or tests change:

```text
commit and push the source changes
→ project CI pulls the existing locked image
→ project CI mounts the new commit
→ project CI runs Ruff and pytest
```

The Docker image is not rebuilt for ordinary source-code changes.
