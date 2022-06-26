cmake_minimum_required(VERSION 3.10.2)
project(CubiLightStudio)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
#-Wl,-subsystem,windows

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE headers src/*.h)

add_executable(CubiLightStudio ${sources} ${headers} src/main.cpp src/Nodes/Graph.cpp src/Nodes/Port.h src/Nodes/Nodespace.h)