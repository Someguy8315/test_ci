cmake_minimum_required(VERSION 3.20)

project(main)

add_executable(main main.c)

set(ASAN_FLAG "-fsanitize=address")

target_compile_options(main PRIVATE ${ASAN_FLAG} -g)
target_link_options(main PRIVATE ${ASAN_FLAG})
