/// @file    BSTNode.cpp
/// @version 1.1

#include "BSTNode.h"

using namespace std;

///////////////// Constructors and Destructor //////////////////////
explicit BSTNode( int newData ) {

    data = newData;
    olelo = "";
    english = "";
    explanation = "";
    color = "";
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}; ///< Creates a node that does not point to another node
    
BSTNode::BSTNode( int newData, 
              std::string newOlelo, 
              std::string newEnglish, 
              std::string newExplanation, 
              std::string newColor,
              BSTNode *newLeft,
              BSTNode *newRight, 
              BSTNode *newParent ) {
    
    data = newData;
    olelo = newOlelo;
    english = newEnglish;
    explanation = newExplanation;
    color = newColor;
    right = newRight;
    left = newLeft;
    parent = newParent;
}; 
    
    
~BSTNode(); /// Destructor to free data



BSTNode::BSTNode( int newData, 
                  BSTNode* newLeft, 
                  BSTNode* newRight, 
                  BSTNode* newParent ) {

    data = newData;
    olelo = "";
    english = "";
    explanation = "";
    color = "";
    lesser = newLesser;
    greater = newGreater;
    data = newData;
}


BSTNode::~BSTNode() {
    reset();
}


void BSTNode::reset() noexcept {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}


int getData () const {
    return data;
};

std::string getOlelo () {
    return olelo;
};

std::string getEnglish () {
    return english;
};

std::string getExplanation () {
    return explanation;
};

std::string getColor () {
    return color;
};

BSTNode* getLeft () {
    return left;
};

BSTNode* getRight () {
    return right;
};

BSTNode* getParent () {
    return parent;
};

void setData ( int newData );
void setOlelo ( std::string newOlelo ); 
void setEnglish ( std::string newEngilsh );
void setExplanation ( std::string newExplanation );
void setColor ( std::string newColor );
void setLeft  ( BSTNode* newLeft );
void setRight ( BSTNode* newRight  );
void setParent ( BSTNode* newParet );