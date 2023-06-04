project(mainWindow)

add_library(${PROJECT_NAME}
        MainWindow.cpp
        MainWindow.h
        mainwindow.ui)

add_subdirectory(Scene)
add_subdirectory(View)
add_subdirectory(ToolBar)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC scene view toolbar canvasController)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)