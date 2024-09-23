///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2024
//
/// binary search tree implementation for collections.///
/// @file BinarySearchTree.h
/// @version 1.1
///
/// @author Jason Castiglione <jcastig@hawaii.edu>
/// @date   28_Mar_2024
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "BSTNode.h"
#include "Container.h"
#include "SLLNode.h"
#include "SinglyLinkedList.h"

#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)


/// A generic SinglyLinkedList collection class.
///
class BinarySearchTree : public Container {

protected:
    BSTNode * root;
public:  ///////////////////////// Public Constructors/Destructors /////////////////////////
    BinarySearchTree(); ///< Make a new BinarySearchTree
    explicit BinarySearchTree(SinglyLinkedList &aSLL); ///< Make a new BinarySearchTree
    ~BinarySearchTree(); ///< Destructor, will free all nodes

protected: /////////////////////////// Protected Methods ////////////////////////////
    void emptyFromNode(BSTNode *aRoot); ///< Deletes all nodes below
    BSTNode *sortedSLLtoBST(const SinglyLinkedList &aSortedSLL,t_size left,t_size right); ///<
    BSTNode* insert(BSTNode *root, int value);
    int minValue(BSTNode *start) const ; ///< Return the minimum value in the sub/tree starting at start
    int maxValue(BSTNode *start) const  ; ///< Return the maximum value in the sub/tree starting at start
    t_size minDepth(BSTNode *start) const noexcept;
    t_size maxDepth(BSTNode *start) const  noexcept; ///< Return the maximum depth of the sub/tree starting at start
    bool isBinarySearchTree(BSTNode *aRoot) const;
    void printPreOrder(BSTNode *root)const noexcept;
    void printInOrder(BSTNode *aRoot)const noexcept;

public:  /////////////////////////// Public Methods ////////////////////////////
    void   empty() override;    ///< Remove all of the Nodes from the Container
    t_size size() const  noexcept override; ///< Returns the number of nodes in the tree
    void insert(int value); ///< inserts a node in the BST with value. WARNING: May result in unbalanced tree
    int minValue() const; ///< Return the minimum value in the whole BST
    int maxValue() const; ///< Return the maximum value in the whole BST
    t_size minDepth() const noexcept; ///< Return the minimum depth of the tree
    t_size maxDepth() const  noexcept; ///< Return the maximum depth of the tree
    bool isBinarySearchTree(); ///< Traverses tree and checks whether satisfies BST criteria
    void print() const noexcept override; ///< Print the data for each element in the container in sorted order
    void printPreOrder()const noexcept; ///<
    void printInOrder()const noexcept; ///<
};


