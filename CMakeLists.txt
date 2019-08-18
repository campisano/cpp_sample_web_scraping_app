cmake_minimum_required(VERSION 3.2.3)

project(scraper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11 -fexceptions -pedantic -Wall -Wextra")

add_subdirectory(${PROJECT_SOURCE_DIR}/external/asio)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/cpr)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/date)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/json)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/kashmir)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/recycle)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/restbed)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/sqlpp11)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/yaml)

add_definitions(-DASIO_STANDALONE)

include_directories(
    /usr/include/postgresql
    ${PROJECT_SOURCE_DIR}/external/asio/install/include
    ${PROJECT_SOURCE_DIR}/external/cpr/install/include
    ${PROJECT_SOURCE_DIR}/external/date/install/include
    ${PROJECT_SOURCE_DIR}/external/json/install
    ${PROJECT_SOURCE_DIR}/external/kashmir/install/include
    ${PROJECT_SOURCE_DIR}/external/recycle/install
    ${PROJECT_SOURCE_DIR}/external/restbed/install/include
    ${PROJECT_SOURCE_DIR}/external/sqlpp11/install/include
    ${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql/install/include
    ${PROJECT_SOURCE_DIR}/external/yaml/install/include
    )

link_directories(
    ${PROJECT_SOURCE_DIR}/external/cpr/install/lib
    ${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql/install/lib
    ${PROJECT_SOURCE_DIR}/external/restbed/install/library
    ${PROJECT_SOURCE_DIR}/external/yaml/install/lib
    )

file(GLOB_RECURSE VAR_SOURCES ${PROJECT_SOURCE_DIR}/src/scraper/*.cpp)
set(VAR_SOURCES ${VAR_SOURCES} ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${VAR_SOURCES})
add_dependencies(${PROJECT_NAME} cpr json recycle restbed sqlpp11-connector-postgresql yaml)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC pthread stdc++
    cpr sqlpp11-connector-postgresql curl pq restbed ssl crypto yaml-cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/install)
