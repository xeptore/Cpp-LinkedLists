cmake_minimum_required(VERSION 3.8)
project(cpp_test_v17)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        SinglyLinkedList.cpp SinglyLinkedList.h)

add_executable(cpp_test_v17 ${SOURCE_FILES} SinglyLinkedList.cpp SinglyLinkedList.h)