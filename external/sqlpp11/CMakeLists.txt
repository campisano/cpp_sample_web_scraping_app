cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

set(VAR_NAME sqlpp11)
set(VAR_CMAKE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)

ExternalProject_Add(
        ${VAR_NAME}
        PREFIX                  ${VAR_NAME}
        DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
        URL                     https://github.com/rbock/sqlpp11/archive/0.57.zip
        URL_HASH                MD5=05a88b8fd31acdbda29da0deb9742f79
        CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}/src/${VAR_NAME} ${VAR_CMAKE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install -DHinnantDate_ROOT_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../date/install -DENABLE_TESTS=OFF
        BUILD_COMMAND           make --silent
        INSTALL_COMMAND         make --silent install
)
