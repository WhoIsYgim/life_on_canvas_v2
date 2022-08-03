project(storage)


add_library(${PROJECT_NAME}
        Storage.cpp
        Storage.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(storage graphicsItems scene)