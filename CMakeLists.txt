cmake_minimum_required(VERSION 3.12)
project(fblack)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
INCLUDE(FetchContent)
FETCHCONTENT_DECLARE(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FETCHCONTENT_MAKEAVAILABLE(googletest)
add_subdirectory("${CMAKE_SOURCE_DIR}/test")


