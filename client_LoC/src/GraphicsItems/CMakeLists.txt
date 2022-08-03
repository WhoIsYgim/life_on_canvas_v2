project(graphicsItems)

add_library(${PROJECT_NAME} IGraphicsItem.cpp IGraphicsItem.h IGraphicsItemFactory.cpp IGraphicsItemFactory.h)

add_subdirectory(Ellipse)
add_subdirectory(FreeLine)
add_subdirectory(Line)
add_subdirectory(Rect)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} ellipse freeline line rect)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)