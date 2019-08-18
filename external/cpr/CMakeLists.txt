cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME cpr)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://github.com/whoshuu/cpr/archive/1.3.0.zip
    URL_HASH                MD5=b7fd66e8e8f59801e264a3b927cc6e48
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${VAR_CMAKE_BASE_ARGS} -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext/include ${CMAKE_CURRENT_SOURCE_DIR}/install/include && ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext-build/lib ${CMAKE_CURRENT_SOURCE_DIR}/install/lib
    )

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${VAR_NAME}_target)
add_dependencies(${VAR_NAME}_target ${VAR_NAME}_ext)

add_library(${VAR_NAME} STATIC IMPORTED GLOBAL)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libcpr.a)
add_dependencies(${VAR_NAME} ${VAR_NAME}_target)
