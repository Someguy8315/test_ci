project(main_test)

include(CTest)

set(ASAN_FLAG "-fsanitize=address")

add_executable(main_test main.cpp test1.cpp)

# get GTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:${ASAN_FLAG} -g>
)
target_link_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:${ASAN_FLAG}>
)

target_link_libraries(${PROJECT_NAME} PRIVATE func GTest::gtest_main)

add_test(NAME MainTests COMMAND ${PROJECT_NAME})
