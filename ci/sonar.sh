#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

# requisites
./ci/install_ci_requisites.sh

# vars
export DOCKER_IMAGE=$(./ci/custom/get_docker_image_build.sh)

# get image
docker pull "${DOCKER_IMAGE}"

# build code and run sonar isolatedly
docker run \
       --env SONAR_ORGANIZATION \
       --env SONAR_TOKEN \
       --env SONAR_PROJECT_KEY \
       --mount type=bind,source="$(pwd)",target=/srv/repository \
       --mount type=bind,source="${HOME}/.custom_cache/srv/cache",target=/srv/cache \
       --mount type=bind,source="${HOME}/.custom_cache/var/cache/apt/archives",target=/var/cache/apt/archives \
       "${DOCKER_IMAGE}" \
       /bin/bash -c \
       'cd /srv/repository; ./ci/custom/internal_sonar.sh "${SONAR_ORGANIZATION}" "${SONAR_TOKEN}" "${SONAR_PROJECT_KEY}"'
