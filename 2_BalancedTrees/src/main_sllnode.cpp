///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// main for understanding Nodes.
///
/// @file main_node.cpp
/// @version 1.1
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////

#include "Container/SLLNode.h"
#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, Farm!\n";

    /// This pointer is special, it keeps track of the head
    SLLNode *head =new SLLNode(0);

    SLLNode *current;
    current=head;

    /// Here we create a singly linked list
    for(int i=1;i<10;i++){
        current->setNext(new SLLNode(i ));
        current=current->getNext();
    }

    /// Here we output the data in the list
    current=head;
    while(current){
        if(current->validate()) {
            std::cout << current->getData() << '\n';
        }
        current = current->getNext();
    }

  /// here we deallocate the memory of the "list"
  current=head;
    while (current) {
        head=current;
        current=current->getNext();
        delete head;
    }

    return 0;
}
