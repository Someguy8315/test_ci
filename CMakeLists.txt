cmake_minimum_required(VERSION 3.20)

project(main)

get_property(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

# set default build type for single config generators
if(NOT IS_MULTI_CONFIG AND CMAKE_BUILD_TYPE STREQUAL "")
    message("Default build type: Release")
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src)

if(UNIX)
    message("Unix: Setting RPATH...")
    list(APPEND CMAKE_INSTALL_RPATH $ORIGIN/../lib)
endif()

add_executable(main main.c)

set(ASAN_FLAG "-fsanitize=address")

target_compile_options(main PRIVATE
    $<$<CONFIG:Debug>:${ASAN_FLAG} -g>
)
target_link_options(main PRIVATE
    $<$<CONFIG:Debug>:${ASAN_FLAG}>
)

target_link_libraries(main PRIVATE func)

install(TARGETS main
    DESTINATION bin
)
