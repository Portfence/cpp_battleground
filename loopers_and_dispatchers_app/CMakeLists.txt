cmake_minimum_required(VERSION 3.16.8 FATAL_ERROR)
project(Loopers_and_Dispatchers LANGUAGES CXX)

find_package(Threads REQUIRED)

add_subdirectory(src)
