file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/objects/quit_button.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/registration.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(${PROJECT_NAME} PUBLIC godot::cpp)

source_group(
  TREE "${CMAKE_CURRENT_SOURCE_DIR}"
  PREFIX src
  FILES ${SOURCES})
