///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// singly linked list implementation for collections.///
/// @file SinglyLinkedList.h
/// @version 1.1
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Container.h"
#include "SLLNode.h"

/// A generic SinglyLinkedList collection class.
///
class SinglyLinkedList : public Container {

protected:
    SLLNode * head;
public:  ///////////////////////// Public Constructors/Destructors /////////////////////////
    SinglyLinkedList();
    ///< Make a new SinglyLinkedList
    explicit SinglyLinkedList(SLLNode * newHead);        ///< Make a new SinglyLinkedList
    ~SinglyLinkedList();                      ///< Destructor, will free all nodes
public:  /////////////////////////// Public Methods ////////////////////////////
    bool   isNodeIn(const SLLNode* aNode  )      const ;    ///< `true` if node is in the Container
    void   add(SLLNode*  aNode)                 ;    ///< Add a SLLNode to the Container
    SLLNode*  remove(SLLNode* aNode  )              ;    ///< Remove a SLLNode from the Container but does not delete the node
    void   empty()                 override;    ///< Remove all of the Nodes from the Container
    SLLNode*  getNthNode(t_size nodeNum)                 const;    ///< gets Nth node
    SLLNode*  getRandomNode() ;    ///< Get a random SLLNode from the Container

    void print() const noexcept override; ///< Print the data for each element in the container
    void generateRandomNode(); ///< Generates a random node by allocating a new head with a randomly generated int.


    void swapNodeData(SLLNode *aNode, SLLNode *bNode) ; ///< Swaps the data from two nodes
    void bubbleSort(); ///< Sorts the list

};


