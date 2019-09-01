cmake_minimum_required(VERSION 3.3.2)

project(scraper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SKIP_RPATH ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(
        CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -pipe -fexceptions -pedantic -Wall -Wextra")
endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/external/asio)
include_directories(${asio_INCLUDE_DIRS})
add_definitions(-DASIO_STANDALONE)

add_subdirectory(${PROJECT_SOURCE_DIR}/external/cpr)
include_directories(${cpr_INCLUDE_DIRS})
link_directories(${cpr_LIBRARY_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/date)
include_directories(${date_INCLUDE_DIRS})
link_directories(${date_LIBRARY_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/json)
include_directories(${json_INCLUDE_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/kashmir)
include_directories(${kashmir_INCLUDE_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/pq)
include_directories(${pq_INCLUDE_DIRS})
link_directories(${pq_LIBRARY_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/recycle)
include_directories(${recycle_INCLUDE_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/restbed)
include_directories(${restbed_INCLUDE_DIRS})
link_directories(${restbed_LIBRARY_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/sqlpp11)
include_directories(${sqlpp11_INCLUDE_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/sqlpp11-connector-postgresql)
include_directories(${sqlpp11-connector-postgresql_INCLUDE_DIRS})
link_directories(${sqlpp11-connector-postgresql_LIBRARY_DIRS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/yaml)
include_directories(${yaml_INCLUDE_DIRS})
link_directories(${yaml_LIBRARY_DIRS})

file(GLOB_RECURSE VAR_SOURCES ${PROJECT_SOURCE_DIR}/src/scraper/*.cpp)
set(VAR_SOURCES ${VAR_SOURCES} ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${VAR_SOURCES})
add_dependencies(${PROJECT_NAME} json recycle)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC stdc++ pthread
    cpr curl restbed yaml sqlpp11-connector-postgresql pq
    curl ssl crypto)
