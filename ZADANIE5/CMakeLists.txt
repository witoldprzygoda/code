cmake_minimum_required(VERSION 3.14)
project(ThreadsExample)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)

add_executable(prog main.cpp)
target_link_libraries(prog Threads::Threads)

