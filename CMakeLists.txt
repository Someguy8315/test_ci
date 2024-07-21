cmake_minimum_required(VERSION 3.20)

project(main)

add_subdirectory(src)

if(UNIX)
    message("Unix: Setting RPATH...")
    list(APPEND CMAKE_INSTALL_RPATH $ORIGIN/../lib)
endif()

add_executable(main main.c)

set(ASAN_FLAG "-fsanitize=address")

target_compile_options(main PRIVATE ${ASAN_FLAG} -g)
target_link_options(main PRIVATE ${ASAN_FLAG})

target_link_libraries(main PRIVATE func)

install(TARGETS main
    DESTINATION bin
)
