///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// main for understanding binary search trees.
///
/// @file main_binary_search_tree.cpp
/// @version 1.1
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////



#include "Container/SLLNode.h"
#include "Container/BinarySearchTree.h"
#include "Container/SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, Farm 4!" << "\n";

    int len = 100;

    /// Create a Singly Linked List called `bList`
    SinglyLinkedList bList;

    /// Add 100 Nodes
    for( int i = 0 ; i < len ; i++ ) {
        bList.generateRandomNode();
    }

    /// Print the Singly Linked List
    bList.print();

    /// Sort the Singly Linked List
    bList.bubbleSort();

    /// Print the Sorted Singly Linked List
    bList.print();

    /// Create a Binary Search Tree called `bTree`
    BinarySearchTree bTree( bList );
    bTree.insert ( 500 );

    /// Print Whether the Singly Linked List is a Binary Search Tree
    if( bTree.isBinarySearchTree() )
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }

    /// Print the Minimum and Maximum Value
    cout << bTree.minValue( ) << "\n";
    cout << bTree.maxValue() << "\n";

    /// Print the Minimum and Maximum Depth
    cout << bTree.minDepth() << "\n";
    cout << bTree.maxDepth() << "\n";



    /// Print PreOrder Traversal of Binary Search Tree
    bTree.printPreOrder();

    /// Print InOrder Traversal of Binary Search Tree
    bTree.printInOrder();



    return 0;
}