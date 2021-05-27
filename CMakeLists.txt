cmake_minimum_required(VERSION 3.17)
project(Lab02)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab02 main.cpp lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h exceptions/exceptions.cpp exceptions/exceptions.h sequence/sequence.cpp sequence/sequence.h sequence/listSequence.cpp sequence/listSequence.h sequence/arraySequence.cpp sequence/arraySequence.h)
add_executable(test tests.cpp lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h exceptions/exceptions.cpp exceptions/exceptions.h tests/linkedListTest.h tests/linkedListTest.cpp)
add_library(lablib lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h exceptions/exceptions.cpp exceptions/exceptions.h sequence/sequence.cpp sequence/sequence.h)
