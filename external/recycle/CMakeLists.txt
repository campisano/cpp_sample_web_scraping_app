cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

ExternalProject_Add(
        recycle
        DOWNLOAD_DIR            ${CMAKE_SOURCE_DIR}/download
        URL                     https://github.com/steinwurf/recycle/archive/4.0.0.zip
        URL_HASH                MD5=c94ec0540f459b58666221c60a9df040
        SOURCE_DIR              ${CMAKE_BINARY_DIR}/src
        CONFIGURE_COMMAND       ""
        BUILD_COMMAND           ""
        INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/src/src/recycle ${CMAKE_SOURCE_DIR}/install/recycle
)
