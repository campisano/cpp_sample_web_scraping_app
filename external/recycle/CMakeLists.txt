cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME recycle)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://github.com/steinwurf/recycle/archive/4.0.0.zip
    URL_HASH                MD5=c94ec0540f459b58666221c60a9df040
    CONFIGURE_COMMAND       ""
    BUILD_COMMAND           ""
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext/src/recycle ${CMAKE_CURRENT_SOURCE_DIR}/install/recycle
    )

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${VAR_NAME}_target)
add_dependencies(${VAR_NAME}_target ${VAR_NAME}_ext)

add_library(${VAR_NAME} STATIC IMPORTED GLOBAL)
add_dependencies(${VAR_NAME} ${VAR_NAME}_target)
