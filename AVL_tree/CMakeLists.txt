
cmake_minimum_required(VERSION 3.28)
project(AVL_tree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AVL_tree main.cpp AVLTree.h PriorityQueue.h)
