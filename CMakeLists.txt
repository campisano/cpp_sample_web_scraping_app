cmake_minimum_required(VERSION 3.2.3)

set(var_target scraper)
project(project_${var_target} LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11 -fexceptions -pedantic -Wall -Wextra")

add_subdirectory(${PROJECT_SOURCE_DIR}/external/cpr)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/date)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/json)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/recycle)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/sqlpp11)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql)

include_directories(/usr/include/postgresql
                    ${PROJECT_SOURCE_DIR}/external/cpr/install/include
                    ${PROJECT_SOURCE_DIR}/external/date/install/include
                    ${PROJECT_SOURCE_DIR}/external/json/install
                    ${PROJECT_SOURCE_DIR}/external/recycle/install
                    ${PROJECT_SOURCE_DIR}/external/sqlpp11/install/include
                    ${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql/install/include)

link_directories(${PROJECT_SOURCE_DIR}/external/cpr/install/lib
                 ${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql/install/lib)

find_library(var_cpr NAMES cpr PATHS ${PROJECT_SOURCE_DIR}/external/cpr/install/lib)
find_library(var_sqlpg NAMES sqlpp11-connector-postgresql PATHS ${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql/install/lib)

file(GLOB_RECURSE var_sources ${PROJECT_SOURCE_DIR}/src/bs/*.cpp)
set(var_sources ${var_sources} ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${var_target} ${var_sources})
target_link_libraries(${var_target} ${var_cpr} ${var_sqlpg} curl pq pthread stdc++)
add_dependencies(${var_target} cpr date json recycle sqlpp11 sqlpp11-connector-postgresql)

install(TARGETS ${var_target} DESTINATION ${PROJECT_SOURCE_DIR}/install)
