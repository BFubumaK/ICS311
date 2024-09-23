///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BinarySearch - ICS 311 - Fall 2024
//
/// BST implementation for collections.
///
/// @file BinarySearchTree.cpp
/// @version 1.1
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////
#include "../config.h"
#include "BSTNode.h"
#include "Container.h"
#include "SinglyLinkedList.h"
#include <iostream>
#include <stdexcept>

#include "BinarySearchTree.h"

using namespace std;
BinarySearchTree::BinarySearchTree() {
    count=0;
    root= nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::empty();
}

void BinarySearchTree::empty() {
    emptyFromNode(root);
}
void BinarySearchTree::emptyFromNode(BSTNode *aRoot) {

    if (aRoot == nullptr){
        return;
    }
    emptyFromNode(aRoot->getLesser());
    emptyFromNode(aRoot->getGreater());
    aRoot->setGreater(nullptr);
    aRoot->setLesser(nullptr);
    delete aRoot;
}

BinarySearchTree::BinarySearchTree( SinglyLinkedList &aSLL ) {
    root = sortedSLLtoBST( aSLL, 0, aSLL.size() - 1 );
}


BSTNode *BinarySearchTree::sortedSLLtoBST(const SinglyLinkedList &aSortedSLL, t_size left,t_size right) {
    if (left >right){
        return nullptr;
    }

    t_size midPoint;
    midPoint = ( left + right ) / 2;

    BSTNode* newRoot;
    newRoot = new BSTNode( aSortedSLL.getNthNode( midPoint ) -> getData() );

    if( left + 1 <= midPoint ) {
        newRoot -> setLesser( sortedSLLtoBST( aSortedSLL, left, midPoint - 1 ) );
    }

    if( midPoint + 1 <= right ) {
        newRoot->setGreater(sortedSLLtoBST(aSortedSLL, midPoint + 1, right));
    }

    return newRoot;
}


void BinarySearchTree::print() const noexcept {
    printInOrder();
}

Container::t_size BinarySearchTree::size() const noexcept {
    return count;
}

bool BinarySearchTree::isBinarySearchTree(){
    return isBinarySearchTree(root);
}

bool BinarySearchTree::isBinarySearchTree(BSTNode *aRoot) const {

    if (aRoot == nullptr){
        return true;
    }

    if(!isBinarySearchTree(aRoot->getLesser()) ||  !isBinarySearchTree(aRoot->getGreater())){
        return false;
    }
    if(aRoot->getLesser()) {
        if (maxValue(aRoot->getLesser()) > aRoot->getData()){
            return false;
        }
    }
    if(aRoot->getGreater()) {
        if (minValue(aRoot->getGreater()) < aRoot->getData()){
            return false;
        }
    }
    return true;
}

void BinarySearchTree::printInOrder()const noexcept {
    printInOrder(root);
}

void BinarySearchTree::printInOrder(BSTNode *aRoot) const noexcept{

    if( !aRoot ) {
        return;
    }

    if( aRoot -> getLesser() ) {
        printInOrder( aRoot -> getLesser() );
    }

    cout << aRoot -> getData() << "\n";

    if( aRoot -> getGreater() ) {
        printInOrder( aRoot -> getGreater() );
    }
}

void BinarySearchTree::printPreOrder() const noexcept{
    printPreOrder(root);
}

void BinarySearchTree::printPreOrder(BSTNode *aRoot) const noexcept{

    if( !aRoot ) {
        return;
    }

    cout << aRoot -> getData() << "\n";

    if( aRoot -> getLesser() ) {
        printPreOrder( aRoot -> getLesser() );
    }

    if( aRoot -> getGreater() ) {
        printPreOrder( aRoot -> getGreater() );
    }


}

int BinarySearchTree::maxValue() const {
    return maxValue(root);
}

int BinarySearchTree::maxValue(BSTNode *start) const {
    if (!start) {
        throw domain_error(PROGRAM_NAME ": An empty BST does not have extremal values.");
    }

    BSTNode *current = start;
    while (current->getGreater()) {
        current = current->getGreater();
    }
    return current->getData();
}

int BinarySearchTree::minValue(BSTNode *start) const  {
    if(!start){
        throw domain_error( PROGRAM_NAME ": An empty BST does not have extremal values." );
    }

    BSTNode *current=start;
    while(current->getLesser()){
        current=current->getLesser();
    }
    return current->getData();
}

int BinarySearchTree::minValue() const {
    return minValue(root);
}

void BinarySearchTree::insert(int value) {
    root=insert(root,value);
}
BSTNode* BinarySearchTree::insert(BSTNode *aRoot, int value) {
    if(!aRoot){
        return new BSTNode(value);
    }
    if(value > aRoot->getData()){
        aRoot->setGreater(insert(aRoot->getGreater(),value));
    }else{
       aRoot->setLesser( insert(aRoot->getLesser(),value));
    }
    return aRoot;
}

Container::t_size BinarySearchTree::minDepth() const noexcept {
    return minDepth(root);
}
Container::t_size BinarySearchTree::minDepth(BSTNode *start) const noexcept {
    t_size lesserDepth;
    t_size greaterDepth;

    if( !start ) {
        return 0;
    }

    lesserDepth = minDepth( start -> getLesser() );
    greaterDepth = minDepth( start -> getGreater() );

    if( lesserDepth < greaterDepth ) {
        return lesserDepth + 1;
    }

    return greaterDepth + 1;
}

Container::t_size BinarySearchTree::maxDepth() const noexcept {
    return maxDepth(root);
}

Container::t_size BinarySearchTree::maxDepth(BSTNode *start) const noexcept {
    if(!start){
        return 0;
    }
    t_size lesserDepth;
    t_size greaterDepth;
    lesserDepth= maxDepth(start->getLesser());
    greaterDepth= maxDepth(start->getGreater());
    if(lesserDepth > greaterDepth ){
        return lesserDepth+1;
    }

    return greaterDepth + 1;

}


