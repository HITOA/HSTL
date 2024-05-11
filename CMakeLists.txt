cmake_minimum_required(VERSION 3.26)
project(HSTL)

set(CMAKE_CXX_STANDARD 17)

add_library(HSTL
        include/HSTL/allocator.hpp
)

target_include_directories(HSTL PUBLIC include)