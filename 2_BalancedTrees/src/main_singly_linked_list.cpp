///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2024
//
/// main for understanding singly linked lists.
///
/// @file main_singly_linked_list.cpp
/// @version 1.1
///
/// @author Jason Castiglione <jcastig@hawaii.edu>
/// @date   28_Mar_2024
///////////////////////////////////////////////////////////////////////////////


#include "Container/SLLNode.h"
#include "Container/SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello, Farm 4! \n";
    /// Create a singly linked list called
    SinglyLinkedList SLL;

    SLL.generateRandomNode();
    SLL.generateRandomNode();
    SLL.generateRandomNode();
    SLL.generateRandomNode();
    /// Write Code Here


    /// Print out the list contents using the print() method.
    SLL.print();
    cout << "break \n" << endl;
    /// Sort it using bubbleSort().
    SLL.bubbleSort();

    /// Print it out and confirm the list is sorted.
    SLL.print();
    return 0;

 }
