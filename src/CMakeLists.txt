project(func)

add_library(${PROJECT_NAME} SHARED func.cpp func.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_options(${PROJECT_NAME} PRIVATE "-fPIC")

target_link_libraries(${PROJECT_NAME} PRIVATE re2)

install(TARGETS ${PROJECT_NAME}
    DESTINATION lib
)

install(FILES func.h
    DESTINATION include
)
