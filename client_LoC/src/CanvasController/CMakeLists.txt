project(canvasController)

add_library( ${PROJECT_NAME}
        CanvasController.cpp
        CanvasController.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}
        storage
        view
        scene
        graphicsItems
        toolbar)