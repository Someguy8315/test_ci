include(FetchContent)

# get abseil C++
FetchContent_Declare(
    abseil
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG 20250127.0
)

FetchContent_MakeAvailable(abseil)

# get RE2
FetchContent_Declare(
    re2
    GIT_REPOSITORY https://github.com/google/re2.git
    GIT_TAG 2024-07-02
)

FetchContent_MakeAvailable(re2)
