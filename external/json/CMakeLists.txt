cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

ExternalProject_Add(
        json
        DOWNLOAD_DIR            ${CMAKE_SOURCE_DIR}/download
        URL                     https://github.com/nlohmann/json/releases/download/v3.5.0/json.hpp
        URL_HASH                MD5=f31ae7ff09be3b6f0f7d00ef4bb7512e
        DOWNLOAD_NO_EXTRACT     true
        CONFIGURE_COMMAND       ""
        BUILD_COMMAND           ""
        INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/download/json.hpp ${CMAKE_SOURCE_DIR}/install/json.hpp
)
