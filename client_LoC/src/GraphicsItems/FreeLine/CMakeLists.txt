project(freeline)

add_library(freeline
        FreeLineItem.cpp
        FreeLineItem.h
        FreeLineItemFactory.cpp
        FreeLineItemFactory.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(freeline graphicsItems)