cmake_minimum_required(VERSION 3.10)
project(GeometryProject VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enforce requested strict compilation flags
add_compile_options(-Wall -Werror)

# 1. Build geometry as a static library
add_library(geometry STATIC src/geometry.cpp)

# 2. Build the test executable pointing to your actual test filename
add_executable(test_geometry tests/tests_geometry.cpp)

# 3. Link the test executable to the geometry static library
target_link_libraries(test_geometry PRIVATE geometry)
