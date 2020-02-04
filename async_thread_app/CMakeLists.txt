cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)
project(AsyncThreadApp LANGUAGES CXX)

# find_package(MyLibrary CONFIG REQUIRED)
find_package(Threads REQUIRED)

add_subdirectory(src)
