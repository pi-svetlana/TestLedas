cmake_minimum_required(VERSION 3.5)

enable_testing()

project(Ledas VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)
add_subdirectory(core)
add_subdirectory(external)
