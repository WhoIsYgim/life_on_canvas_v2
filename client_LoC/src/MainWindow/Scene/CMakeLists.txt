project(scene)

add_library(${PROJECT_NAME}
        GraphicsScene.cpp
        GraphicsScene.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(scene Qt5::Widgets)