cmake_minimum_required(VERSION 2.8.7)
project(BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}<BinarySearchTree.h> /tests/)
add_library(BinarySearchTree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/BinarySearchTree.cpp tests/main.cpp)

add_executable(BinarySearchTree ${SOURCE_FILES} examples/main.cpp)
add_executable(Tests ${TESTS_SOURCE} tests/size.cpp tests/find.cpp tests/insert.cpp tests/main.cpp)
