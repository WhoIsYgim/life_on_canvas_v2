project(toolbar)

add_library(${PROJECT_NAME}
        ToolBar.cpp
        ToolBar.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(toolbar
        Qt5::Widgets)

target_link_libraries(toolbar
        graphicsItems
        )