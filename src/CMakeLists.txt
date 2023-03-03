project(DailyGodot4Cpp CXX)

add_library(DailyGodot4Cpp SHARED GodotLibrary.cpp include)

target_link_libraries(DailyGodot4Cpp PUBLIC godot-cpp)

target_include_directories(
  DailyGodot4Cpp
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
