///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// A  node for binary search trees
///
/// @file BSTNode.h
/// @version 1.0
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


class BSTNode {
protected:

    int data ;
    std::string olelo, 
    std::string english, 
    std::string explanation, 
    std::string color
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;

public:   ///////////////////// Constructors & Destructors /////////////////////
    BSTNode() = default;   ///< Default constructor

    explicit BSTNode(int newData); ///< Creates a node that does not point to another node
    
    BSTNode( int newdata, 
              std::string newOlelo, 
              std::string newEnglish, 
              std::string newExplanation, 
              std::string newColor,
              BSTNode *newLeft,
              BSTNode *newRight, 
              BSTNode *newParent ); 
    
    BSTNode( int newData, 
             BSTNode* newLeft, 
             BSTNode* newRight, 
             BSTNode* newParent );

    ~BSTNode(); /// Destructor to free data

 public:   ////////////////////// Getters and Setters /////////////////
    void reset () noexcept ; // sets child ptrs to null

    int getData () const;
    std::string getOlelo ();
    std::string getEnglish ();
    std::string getExplanation ();
    std::string getColor ();
    BSTNode* getLeft ();
    BSTNode* getRight ();
    BSTNode* getParent ();

    void setData ( int newData );
    void setOlelo ( std::string newOlelo ); 
    void setEnglish ( std::string newEngilsh );
    void setExplanation ( std::string newExplanation );
    void setColor ( std::string newColor );
    void setLeft  ( BSTNode* newLeft );
    void setRight ( BSTNode* newRight  );
    void setParent ( BSTNode* newParet );

};