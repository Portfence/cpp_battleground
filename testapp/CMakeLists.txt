cmake_minimum_required(VERSION 3.16.8 FATAL_ERROR)
project(TestApp LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(tl-expected CONFIG REQUIRED)

add_subdirectory(src)
