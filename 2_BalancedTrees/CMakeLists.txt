###############################################################################
#  University of Hawaii, College of Engineering
#  2_BalancedTrees - ICS 311 - Fall 2024
#
## CMake manages the building of source code.
##
## @see https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html
##
## @file   CMakeLists.txt
## @author Brian Kim <brianiki@hawaii.edu>
###############################################################################

cmake_minimum_required(VERSION 3.26)

project(2_BalancedTrees
        VERSION 1.0
        DESCRIPTION ""
        LANGUAGES CXX)

message(STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE off)
#Here we add the ability to check for memory problems
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -fsanitize=address")

#Regular CMAKE args
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra ")

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# add clang-tidy, but slows compile
#set(CMAKE_CXX_CLANG_TIDY clang-tidy -extra-arg=-std=c++17;)


set(SOURCE_FILES_GENERAL    src/config.h )
set(SOURCE_FILES_CONTAINERS ${SOURCE_FILES_GENERAL} src/Container/Container.cpp src/Container/Container.h src/Container/SLLNode.cpp src/Container/SLLNode.h src/Container/BSTNode.cpp src/Container/BSTNode.h)
set(SOURCE_FILES_SLL_BST  ${SOURCE_FILES_CONTAINERS}   src/Container/SinglyLinkedList.cpp src/Container/SinglyLinkedList.h src/Container/BinarySearchTree.cpp src/Container/BinarySearchTree.h)

add_executable(main_sllnode src/main_sllnode.cpp ${SOURCE_FILES_CONTAINERS})

add_executable(main_singly_linked_list src/main_singly_linked_list.cpp  ${SOURCE_FILES_SLL_BST})

add_executable(main_binary_search_tree src/main_binary_search_tree.cpp  ${SOURCE_FILES_SLL_BST})
