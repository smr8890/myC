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
add_executable(1566Delete program2/1566Delete.cpp)
add_executable(1390Letter_Count   "program2/1390Letter_Count  .cpp")
add_executable(1544Median program3/1544Median.cpp)
add_executable(1538TypeWriter program1/1538TypeWriter.c)
add_executable(1539Range program1/1539Range.c)
add_executable(1576Section program1/1576Section.c)
add_executable(1551BinaryTreeMerge program3/1551BinaryTreeMerge.cpp)