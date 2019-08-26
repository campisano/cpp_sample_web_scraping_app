cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME yaml)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://codeload.github.com/jbeder/yaml-cpp/zip/yaml-cpp-0.6.2
    URL_HASH                MD5=132d42bc018213dda0671ee2ea971523
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_CXX_STANDARD=11 -DYAML_CPP_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=ON
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")
SET(${TARGET_NAME}_LIBRARY_DIRS ${INSTALL_DIR}/lib CACHE STRING "")
SET(${TARGET_NAME}_LIBRARIES ${${TARGET_NAME}_LIBRARY_DIRS}/libyaml-cpp.so CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} SHARED IMPORTED GLOBAL)
set_target_properties(
    ${TARGET_NAME} PROPERTIES
    IMPORTED_LOCATION ${${TARGET_NAME}_LIBRARIES})
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_clean_no_custom)
