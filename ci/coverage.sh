#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

# requisites
./ci/install_ci_requisites.sh

# vars
export DOCKER_IMAGE=$(./ci/custom/get_docker_image_run.sh)

# get image
docker pull "${DOCKER_IMAGE}"

# coverage code isolatedly
docker run \
       --env COVERAGE_TOKEN \
       --mount type=bind,source="$(pwd)",target=/srv/repository \
       --mount type=bind,source="${HOME}/.custom_cache/var/cache/apt/archives",target=/var/cache/apt/archives \
       "${DOCKER_IMAGE}" \
       /bin/bash -c \
       'cd /srv/repository; ./ci/custom/internal_coverage.sh ${COVERAGE_TOKEN}'
