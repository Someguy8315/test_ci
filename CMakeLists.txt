cmake_minimum_required(VERSION 3.20)

project(main)

option(ENABLE_TESTS "Enable basic tests" ON)

get_property(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

# set default build type for single config generators
if(NOT IS_MULTI_CONFIG AND CMAKE_BUILD_TYPE STREQUAL "")
    message("Default build type: Release")
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src)

if(ENABLE_TESTS)
    message("Tests enabled...")
    add_subdirectory(tests)
endif()
