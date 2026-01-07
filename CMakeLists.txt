cmake_minimum_required(VERSION 3.13)

project(shell-starter-cpp)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

add_executable(shell ${SOURCE_FILES})

if (WIN32)
  message(STATUS "Windows detected: building without readline")
else()
  target_link_libraries(shell PRIVATE readline)
endif()
