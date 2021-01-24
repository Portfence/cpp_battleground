cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(ConstructorsApp LANGUAGES CXX)

find_package(tl-expected CONFIG REQUIRED)

add_subdirectory(src)
