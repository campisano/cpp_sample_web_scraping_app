cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

ExternalProject_Add(
        cpr
        DOWNLOAD_DIR            ${CMAKE_SOURCE_DIR}/download
        URL                     https://github.com/whoshuu/cpr/archive/1.3.0.zip
        URL_HASH                MD5=b7fd66e8e8f59801e264a3b927cc6e48
        SOURCE_DIR              ${CMAKE_BINARY_DIR}/src
        BINARY_DIR              ${CMAKE_BINARY_DIR}/bin
        CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_BINARY_DIR}/src -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
        BUILD_COMMAND           make --silent
        INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/src/include ${CMAKE_SOURCE_DIR}/install/include && ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_BINARY_DIR}/bin/lib ${CMAKE_SOURCE_DIR}/install/lib
)
