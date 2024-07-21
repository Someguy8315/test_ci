project(func)

add_library(${PROJECT_NAME} SHARED func.c func.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
