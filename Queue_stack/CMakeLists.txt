cmake_minimum_required(VERSION 3.28)
project(Queue_stack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Queue_stack Stack.h Queue.h main.cpp)

