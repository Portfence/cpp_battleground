cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)
project(LambdaFunctorApp LANGUAGES CXX)

find_package(range-v3 CONFIG REQUIRED)

add_subdirectory(src)
