///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2024
//
/// A  node for binary search trees
///
/// @file BSTNode.h
/// @version 1.0
///
/// @author Jason Castiglione <jcastig@hawaii.edu>
/// @date   28_Mar_2024
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <boost/core/typeinfo.hpp>  // For typeinfo()
#include <iostream>
#include <string>
#include <utility>


#include "../config.h"


class BSTNode {
protected:

    int data ;
    BSTNode* lesser;
    BSTNode* greater;

public:   ///////////////////// Constructors & Destructors /////////////////////
    BSTNode() = default;   ///< Default constructor
    explicit BSTNode(int data); ///< Creates a node that does not point to another node
    BSTNode(int data, BSTNode *newLesser,BSTNode *newGreater ); ///< Creates a node that has child nodes
    ~BSTNode(); /// Destructor to free data

    void reset()noexcept ; // sets child ptrs to null
    BSTNode* getLesser() ;
    BSTNode* getGreater();
    int getData() const;
    void setData( int newData);
    void setLesser(BSTNode* newLesser);
    void setGreater(BSTNode* newGreater);

};