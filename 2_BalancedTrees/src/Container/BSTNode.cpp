/// @file    BSTNode.cpp
/// @version 1.1

#include "BSTNode.h"

using namespace std;


BSTNode::BSTNode( int newData ) {
    lesser = nullptr;
    greater = nullptr;
    data = newData;
}


BSTNode::BSTNode( int newData, BSTNode* newLesser, BSTNode* newGreater ) {
    lesser = newLesser;
    greater = newGreater;
    data = newData;
}


BSTNode::~BSTNode() {
    reset();
}


void BSTNode::reset() noexcept {
    lesser = nullptr;
    greater = nullptr;
}


BSTNode* BSTNode::getLesser() {
    return lesser;
}


BSTNode* BSTNode::getGreater() {
    return greater;
}


int BSTNode::getData() const {
    return data;
}


void BSTNode::setData( int newData ) {
    data = newData;
}


void BSTNode::setLesser( BSTNode* newLesser ) {
    lesser = newLesser;
}


void BSTNode::setGreater( BSTNode* newGreater )
{
    greater = newGreater;
}