cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(my_project)


add_library(my_static_library STATIC
  src/static.cpp
)
target_include_directories(my_static_library
  PUBLIC
  inc
)

add_library(my_dynamic_library MODULE
  src/dynamic.cpp
)
target_include_directories(my_dynamic_library
  PUBLIC
  inc
)
target_link_libraries(my_dynamic_library
  PUBLIC
  my_static_library
)

add_executable(my_program
  src/main.cpp
)
target_include_directories(my_program
  PUBLIC
  inc
)
target_link_libraries(my_program
  PUBLIC
  my_static_library
)

