cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME sqlpp11)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)
set(VAR_CMAKE_BASE_ARGS ${VAR_CMAKE_BASE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://github.com/rbock/sqlpp11/archive/0.58.zip
    URL_HASH                MD5=495bac43836f4c7ffcfd941319d6c58f
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${VAR_CMAKE_BASE_ARGS} -DHinnantDate_ROOT_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../date/install -DENABLE_TESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )
