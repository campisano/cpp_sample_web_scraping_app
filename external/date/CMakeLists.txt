cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

ExternalProject_Add(
        date
        DOWNLOAD_DIR            ${CMAKE_SOURCE_DIR}/download
        URL                     https://github.com/HowardHinnant/date/archive/v2.4.1.zip
        URL_HASH                MD5=6bb7a7180339566bd36eaeb1785125de
        SOURCE_DIR              ${CMAKE_BINARY_DIR}/src
        BINARY_DIR              ${CMAKE_BINARY_DIR}/bin
        CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_BINARY_DIR}/src -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DBUILD_SHARED_LIBS=ON
        BUILD_COMMAND           make --silent
        INSTALL_COMMAND         make --silent install
)
