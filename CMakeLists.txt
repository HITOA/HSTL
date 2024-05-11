cmake_minimum_required(VERSION 3.26)
project(HSTL)

set(CMAKE_CXX_STANDARD 17)

add_library(HSTL
        include/HSTL/allocator.hpp
        include/HSTL/array.hpp
        include/HSTL/vector.hpp
        include/HSTL/iterator.hpp
        include/HSTL/typetraits.hpp
        src/hstl.cpp
)

target_include_directories(HSTL PUBLIC include)

add_executable(HSTL_TEST
        test/main.cpp)

target_link_libraries(HSTL_TEST HSTL)