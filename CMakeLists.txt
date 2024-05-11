cmake_minimum_required(VERSION 3.27)
project(untitled C)
project(untitled CXX)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
)

add_executable(1457Image program2/1457Image.c)
add_executable(1530Game program1/1530Game.c)
add_executable(1587XOR_Tree program2/1587XOR_Tree.cpp)
add_executable(1586Product program2/1586Product.cpp)
add_executable(test test.cpp)
add_executable(1448BitsAND program2/1448BitsAND.cpp)