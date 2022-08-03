project(ellipse)
add_library( ellipse
        EllipseItem.cpp
        EllipseItem.h
        EllipseItemFactory.cpp
        EllipseItemFactory.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ellipse PRIVATE graphicsItems)