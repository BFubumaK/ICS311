///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// A  node for singly linked lists.
///
/// @file SLLNode.h
/// @version 1.1
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <boost/core/typeinfo.hpp>  // For typeinfo()
#include <iostream>
#include <string>
#include <utility>


#include "../config.h"


class SLLNode {
protected:

    int data;
    SLLNode* next;

public:   ///////////////////// Constructors & Destructors /////////////////////
    SLLNode() = default;   ///< Default constructor
    explicit SLLNode(int data); ///< Creates a node that does not point to another node
    SLLNode(int data, SLLNode *next); ///< Creates a node that has a next node
    ~SLLNode(); /// Destructor to free data

    void reset()noexcept ;
    SLLNode* getNext() ;
    int getData() const;
    bool validate() const noexcept ;
    void setData( int newData);
    void setNext(SLLNode* nextNode);
};