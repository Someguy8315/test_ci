cmake_minimum_required(VERSION 3.20)

project(main)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)

option(ENABLE_TESTS "Enable basic tests" ON)

get_property(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

# set default build type for single config generators
if(NOT IS_MULTI_CONFIG AND CMAKE_BUILD_TYPE STREQUAL "")
    message("Default build type: Release")
    set(CMAKE_BUILD_TYPE Release)
endif()

include(FetchContent)

FetchContent_Declare(
    re2
    GIT_REPOSITORY https://github.com/google/re2.git
    GIT_TAG 2024-07-02
)

FetchContent_MakeAvailable(re2)

add_subdirectory(src)

if(ENABLE_TESTS)
    message("Tests enabled...")
    include(CTest)
    add_subdirectory(tests)
endif()
