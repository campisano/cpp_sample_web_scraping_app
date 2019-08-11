cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME restbed)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)
set(VAR_CMAKE_BASE_ARGS ${VAR_CMAKE_BASE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://github.com/Corvusoft/restbed/archive/4.6.zip
    URL_HASH                MD5=2424a7f89792d61f783a6581273a0410
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${VAR_CMAKE_BASE_ARGS} -Dasio_INCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/../asio/install/include -Dkashmir_INCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/../kashmir/install/include -DBUILD_TESTS=NO -DBUILD_EXAMPLES=NO -DBUILD_SSL=YES -DBUILD_SHARED=NO
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

add_library(${VAR_NAME} STATIC IMPORTED)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/library/librestbed.a)
