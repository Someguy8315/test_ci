project(main_test)

add_executable(main_test main.cpp test1.cpp)

# get GTest
add_subdirectory(googletest)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # copy the DLLs to the output directory
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:func>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

if(UNIX)
    set(ASAN_FLAG "-fsanitize=address")
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:${ASAN_FLAG} -g>
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:${ASAN_FLAG}>
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE func GTest::gtest_main)

add_test(NAME MainTests COMMAND ${PROJECT_NAME})
