cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(AsyncThreadApp LANGUAGES CXX)

find_package(Threads REQUIRED)

add_subdirectory(src)
