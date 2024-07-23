
cmake_minimum_required(VERSION 3.28)
project(STL_priority_queue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(STL_priority_queue main.cpp MaxHeap.h Kth_smallest_number.h)
