cmake_minimum_required(VERSION 3.21)
project(CubiLightStudio)

set(CMAKE_CXX_STANDARD 17)

file(GLOB sources src/*.*)

add_executable(CubiLightStudio ${sources})
target_include_directories(CubiLightStudio PRIVATE src)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
target_link_libraries(CubiLightStudio glfw)

add_subdirectory(vendor/glad)
target_link_libraries(CubiLightStudio glad)

add_subdirectory(vendor/imgui)
target_link_libraries(CubiLightStudio imgui)

add_subdirectory(vendor/spdlog)
target_link_libraries(CubiLightStudio spdlog)

#target_link_libraries(CubiLightStudio imgui_node_editor)