cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME kashmir)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)
set(VAR_CMAKE_BASE_ARGS ${VAR_CMAKE_BASE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://codeload.github.com/Corvusoft/kashmir-dependency/zip/2f3913f49c4ac7f9bff9224db5178f6f8f0ff3ee
    URL_HASH                MD5=a812d12ec3f417269a261eb28cd82e84
    CONFIGURE_COMMAND       ""
    BUILD_COMMAND           ""
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/kashmir_ext/kashmir ${CMAKE_CURRENT_SOURCE_DIR}/install/include/${VAR_NAME}
    )
