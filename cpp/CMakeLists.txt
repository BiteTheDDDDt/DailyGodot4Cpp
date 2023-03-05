cmake_minimum_required(VERSION 3.19)

set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE "Debug")
set(CXX_FLAGS_DEBUG "${CXX_FLAGS_DEBUG} -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  GDExtension
  GIT_REPOSITORY https://github.com/godotengine/godot-cpp.git
  GIT_TAG godot-4.0-stable)
FetchContent_MakeAvailable(GDExtension)

project(DailyGodot4Cpp)

add_subdirectory(src)
