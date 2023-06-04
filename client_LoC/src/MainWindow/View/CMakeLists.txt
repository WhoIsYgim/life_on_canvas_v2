project(view)

add_library(${PROJECT_NAME}
        View.cpp
        View.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(view Qt5::Widgets)