cmake_minimum_required(VERSION 3.3.2)

project(scraper LANGUAGES CXX)

# global properties
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SKIP_RPATH ON)

# project dependencies
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

add_subdirectory(${PROJECT_SOURCE_DIR}/external/cpputest)
include_directories(${cpputest_INCLUDE_DIRS})
link_directories(${cpputest_LIBRARY_DIRS})

# project sources
file(GLOB_RECURSE VAR_APP_SOURCES ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.cpp)
file(GLOB_RECURSE VAR_TEST_SOURCES ${PROJECT_SOURCE_DIR}/src/test/*.cpp)

# project outputs
add_library(${PROJECT_NAME}_common OBJECT ${VAR_APP_SOURCES})
add_dependencies(${PROJECT_NAME}_common
    asio cpr date json kashmir pq recycle restbed
    sqlpp11 sqlpp11-connector-postgresql yaml)

add_executable(${PROJECT_NAME}_exec $<TARGET_OBJECTS:${PROJECT_NAME}_common> ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME}_exec PUBLIC stdc++ pthread
    cpr restbed yaml sqlpp11-connector-postgresql pq
    curl ssl crypto)

add_executable(${PROJECT_NAME}_test $<TARGET_OBJECTS:${PROJECT_NAME}_common> ${VAR_TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}_test PUBLIC stdc++ pthread
    cpr restbed yaml sqlpp11-connector-postgresql pq
    curl ssl crypto cpputest)

# project outputs specific properties
set_target_properties(${PROJECT_NAME}_common ${PROJECT_NAME}_exec ${PROJECT_NAME}_test PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON)

# GNU compiler specific flags
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # global
    set(BASE_CXX_FLAGS "-pipe -fexceptions -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor")

    # RELEASE: use optimization, remove all symbol table
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "release")
        set_target_properties(${PROJECT_NAME}_common ${PROJECT_NAME}_exec ${PROJECT_NAME}_test PROPERTIES
            COMPILE_FLAGS "${COMPILE_FLAGS} ${BASE_CXX_FLAGS} -O3 -s"
            LINK_FLAGS "${LINK_FLAGS}")
    endif()

    # DEBUG: use debug optimization, increase debug level to 3, mantain frame pointer to use linux 'prof' tool
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "debug")
        set_target_properties(${PROJECT_NAME}_common ${PROJECT_NAME}_exec ${PROJECT_NAME}_test PROPERTIES
            COMPILE_FLAGS "${COMPILE_FLAGS} ${BASE_CXX_FLAGS} -Og -ggdb3 -g3 -fno-omit-frame-pointer --coverage"
            LINK_FLAGS "${LINK_FLAGS} --coverage")
    endif()
endif()
