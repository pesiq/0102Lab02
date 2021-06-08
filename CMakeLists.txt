cmake_minimum_required(VERSION 3.16)
project(Lab02)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab02 main.cpp lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h exceptions/exceptions.h sequence/sequence.h sequence/listSequence.h sequence/arraySequence.h higher/Vector.h higher/Set.h)
add_executable(test tests.cpp lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h exceptions/exceptions.h tests/linkedListTest.h tests/linkedListTest.cpp tests/dynamicArrayTest.cpp tests/dynamicArrayTest.h)
add_library(lablib lower/dynamicArray.h lower/dynamicArray.cpp lower/linkedList.cpp lower/linkedList.h exceptions/exceptions.h sequence/sequence.h)
