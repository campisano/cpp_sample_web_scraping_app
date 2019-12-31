#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

# requisites
./ci/custom/ci_requisites.sh

# vars
export DOCKER_FROM_IMAGE=$(./ci/custom/get_docker_from_image.sh)

# get image
docker pull "${DOCKER_FROM_IMAGE}"

# test code isolatedly
docker run \
       --mount type=bind,source="$(pwd)",target=/repository \
       "${DOCKER_FROM_IMAGE}" \
       /bin/bash -c \
       'cd /repository; ./ci/custom/internal_test.sh'
