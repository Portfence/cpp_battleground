cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)
project(CoffeeMachineApp LANGUAGES CXX)

find_package(tl-expected CONFIG REQUIRED)

add_subdirectory(src)
