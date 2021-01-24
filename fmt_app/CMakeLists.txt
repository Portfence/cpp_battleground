cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(FmtApp LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(src)
