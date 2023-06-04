project(line)

add_library(line
        LineItem.cpp
        LineItem.h
        LineItemFactory.cpp
        LineItemFactory.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(line graphicsItems)