#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

# vars
export DOCKER_FROM_IMAGE=$(./ci/custom/get_docker_from_image.sh)

# build and test
docker pull "${DOCKER_FROM_IMAGE}"
docker run --mount type=bind,source="$(pwd)",target=/repository "${DOCKER_FROM_IMAGE}" /bin/bash -c 'cd /repository; ./ci/custom/internal_build.sh'
docker run --mount type=bind,source="$(pwd)",target=/repository "${DOCKER_FROM_IMAGE}" /bin/bash -c 'cd /repository; ./ci/custom/internal_test.sh'
