cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME kashmir)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://codeload.github.com/Corvusoft/kashmir-dependency/zip/2f3913f49c4ac7f9bff9224db5178f6f8f0ff3ee
    URL_HASH                MD5=a812d12ec3f417269a261eb28cd82e84
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ""
    BUILD_COMMAND           ""
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory <SOURCE_DIR>/kashmir <INSTALL_DIR>/include/kashmir
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} INTERFACE)
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_clean_no_custom)
