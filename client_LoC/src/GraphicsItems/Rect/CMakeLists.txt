project(rect)

add_library(rect
        RectangleItem.cpp
        RectangleItem.h
        RectangleItemFactory.cpp
        RectangleItemFactory.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(rect graphicsItems)