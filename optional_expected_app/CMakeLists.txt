cmake_minimum_required(VERSION 3.16.8 FATAL_ERROR)
project(Optional_expected_app LANGUAGES CXX)

find_package(tl-expected CONFIG REQUIRED)

add_subdirectory(src)
