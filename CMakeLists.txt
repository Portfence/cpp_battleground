cmake_minimum_required(VERSION 3.16.8 FATAL_ERROR)

project(Battleground CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(async_thread_app)
add_subdirectory(CoffeeMachineApp)
add_subdirectory(constructors)
add_subdirectory(fmt_app)
add_subdirectory(lamba_functor_app)
add_subdirectory(loopers_and_dispatchers_app)
add_subdirectory(optional_expected_app)
add_subdirectory(progress_bar_app)
add_subdirectory(ranges_app)
add_subdirectory(std_variant_app)
add_subdirectory(strong_types_app)
#add_subdirectory(testapp)