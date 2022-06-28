cmake_minimum_required(VERSION 3.10.2)
project(CubiLightStudio)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
#-Wl,-subsystem,windows

file(GLOB_RECURSE sources src/*.*)

add_executable(CubiLightStudio ${sources} src/Nodes/BasePort.cpp)
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