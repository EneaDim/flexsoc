# FlexSoC Docker Image and CI

FlexSoC uses a prebuilt Docker image containing the pinned EDA toolchain and
Python dependencies required by the project.

Image creation and project testing are intentionally separated:

```text
Manual image workflow:
build → verify runtime → publish → generate image.lock

Project CI:
checkout commit → pull locked image → mount source code → lint and test
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

- the system EDA toolchain;
- the Python runtime;
- the `uv` installation;
- the virtual environment;
- the main EDA commands.

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
3. verifies the system toolchain;
4. runs Ruff;
5. runs the API tests;
6. collects the E2E tests;
7. optionally runs the complete E2E suite.

This is the only Docker script that runs project tests.

### `common.sh`

Contains shared functions for:

- calculating the image input hash;
- generating image names and tags;
- locating the GHCR repository;
- validating `image.lock`;
- resolving immutable image references.

---

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

Whenever one of the image inputs changes, a new runtime image must be published
and `image.lock` must be updated.

The image inputs are:

```text
docker/ci/Dockerfile
docker/ci/Dockerfile.dockerignore
src/flexsoc/backend/deps.sh
src/flexsoc/backend/toolchain.lock
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
run the manual image workflow
→ verify the runtime image
→ publish the image
→ download image.lock
→ commit image.lock
```

### Normal source-code update

When FlexSoC source code or tests change:

```text
commit and push the source changes
→ project CI pulls the existing locked image
→ project CI mounts the new commit
→ project CI runs Ruff and pytest
```

The Docker image is not rebuilt for ordinary source-code changes.
