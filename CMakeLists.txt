cmake_minimum_required(VERSION 4.2.2)

project(hajimi_vulkan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(hajimi_vulkan
        src/main.cpp
        src/lve_window.cpp
        src/first_app.cpp
        src/first_app.h
        src/lve_pipeline.cpp
        src/lve_pipeline.hpp
        src/lve_device.cpp
        src/lve_device.hpp
)

target_compile_definitions(hajimi_vulkan
    PRIVATE
        GLFW_INCLUDE_VULKAN
)

target_link_libraries(hajimi_vulkan
    PRIVATE
        Vulkan::Vulkan
        glfw
)

if(MSVC)
    target_compile_options(hajimi_vulkan 
    PRIVATE
        /W4 
        /permissive-
)
endif()    