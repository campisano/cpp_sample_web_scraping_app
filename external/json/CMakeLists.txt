cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

set(VAR_NAME json)
set(VAR_CMAKE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)

ExternalProject_Add(
        ${VAR_NAME}_ext
        DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
        URL                     https://github.com/nlohmann/json/releases/download/v3.5.0/json.hpp
        URL_HASH                MD5=f31ae7ff09be3b6f0f7d00ef4bb7512e
        DOWNLOAD_NO_EXTRACT     true
        CONFIGURE_COMMAND       ""
        BUILD_COMMAND           ""
        INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/download/json.hpp ${CMAKE_CURRENT_SOURCE_DIR}/install/json.hpp
)
