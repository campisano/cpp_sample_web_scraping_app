cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

ExternalProject_Add(
        sqlpp11
        DOWNLOAD_DIR            ${CMAKE_SOURCE_DIR}/download
        URL                     https://github.com/rbock/sqlpp11/archive/0.57.zip
        URL_HASH                MD5=05a88b8fd31acdbda29da0deb9742f79
        SOURCE_DIR              ${CMAKE_BINARY_DIR}/src
        BINARY_DIR              ${CMAKE_BINARY_DIR}/bin
        CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_BINARY_DIR}/src -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DHinnantDate_ROOT_DIR=${CMAKE_SOURCE_DIR}/../date/install -DENABLE_TESTS=OFF
        BUILD_COMMAND           make --silent
        INSTALL_COMMAND         make --silent install
)
