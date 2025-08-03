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
        baekjoon/binary_search/no_1166_선물.cpp
        baekjoon/math/no_29753_최소성적.cpp
        baekjoon/dp/no_17130_토끼가정보섬에올라온이유.cpp
)
