cmake_minimum_required(VERSION 3.23)
project(prog)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_executable(prog main.cpp LibraryItem.cpp LibraryItem.hpp Book.cpp Book.hpp Magazine.cpp Magazine.hpp Library.cpp Library.hpp)
