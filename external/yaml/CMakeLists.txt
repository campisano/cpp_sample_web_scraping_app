cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME yaml)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://codeload.github.com/jbeder/yaml-cpp/zip/yaml-cpp-0.6.2
    URL_HASH                MD5=132d42bc018213dda0671ee2ea971523
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${VAR_CMAKE_BASE_ARGS} -DYAML_CPP_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${VAR_NAME}_target)
add_dependencies(${VAR_NAME}_target ${VAR_NAME}_ext)

add_library(${VAR_NAME} STATIC IMPORTED GLOBAL)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libyaml-cpp.a)
add_dependencies(${VAR_NAME} ${VAR_NAME}_target)
