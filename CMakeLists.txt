cmake_minimum_required(VERSION 3.31)
project(algorithm)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm main.cpp
        note/bfs.cpp
        note/dfs.cpp
        note/two_pointers.cpp
        note/binary_search.cpp
        note/dp.cpp
)
