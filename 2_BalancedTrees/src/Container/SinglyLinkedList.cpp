///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2024
//
/// singly linked list implementation for collections.
///
/// @file SinglyLinkedList.cpp
/// @version 1.1
///
/// @author Jason Castiglione <jcastig@hawaii.edu>
/// @date   28_Mar_2024
///////////////////////////////////////////////////////////////////////////////
#include "../config.h"
#include "SLLNode.h"
#include "SinglyLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;
SinglyLinkedList::SinglyLinkedList(){
    head= nullptr;
    count=0;
}


SinglyLinkedList::SinglyLinkedList(SLLNode *head) {
    if(!head->validate() || (head->getNext() != nullptr) ) {
        throw invalid_argument(PROGRAM_NAME ": Can't initialize list with non-valid head node.");
    }
    this->head = head;
    count++;
}

SinglyLinkedList::~SinglyLinkedList() {
    SinglyLinkedList::empty();
}
bool   SinglyLinkedList::isNodeIn(const SLLNode* aNode ) const {
    /// @throws invalid_argument If `aNode` is `nullptr`.
    if (aNode == nullptr) {
        throw invalid_argument(PROGRAM_NAME ": Can't search for a nullptr");
    }
    SLLNode *current;
    current = head;
    while (current) {
        if (current == aNode) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

void SinglyLinkedList::add(SLLNode *aNode) {
    /// @throws invalid_argument If `aNode` is `nullptr`.
    if (aNode == nullptr || !aNode->validate()) {
        throw invalid_argument(PROGRAM_NAME ": Can't add a nullptr or invalid node to the list.");
    }
    aNode->setNext(head);
    head=aNode;
    count++;
}

SLLNode*   SinglyLinkedList::remove(SLLNode* aNode ) {
    /// @throws invalid_argument If `aNode` is `nullptr`.
    if (aNode == nullptr || head == nullptr) {
        throw invalid_argument(PROGRAM_NAME ": The list is empty or attempt to search for nullptr");
    }
    if (head== aNode){
        head=head->getNext();
        count--;
        aNode->setNext(nullptr);
        return aNode;
    }
    SLLNode *current;

    current=head;
    while(current->getNext()){
        if(current->getNext()== aNode){
            current->setNext(aNode->getNext());
            aNode->setNext(nullptr);
            count--;
            return aNode;
        }
        current=current->getNext();
    }
    throw domain_error( PROGRAM_NAME ": Desired node to remove is not present" );
}

void SinglyLinkedList::empty()  {

    SLLNode *current;
    while(head != nullptr){
        current= head;
        head=head->getNext();
        delete current;
    }
    count=0;
}


SLLNode *SinglyLinkedList::getRandomNode()  {
    if(count <= 1 ) {
        return head;
    }
    const SinglyLinkedList::t_size nodeNum= getRandomNodeNumber();
    return getNthNode(nodeNum);
}

void SinglyLinkedList::generateRandomNode() {
    add(new SLLNode(getRandomInt()));
}

SLLNode * SinglyLinkedList::getNthNode(t_size nodeNum) const {
    if(count==0){
        throw domain_error( PROGRAM_NAME ": The SinglyLinkedList is empty" );
    }
    if(nodeNum > (count-1) ){
        throw domain_error( PROGRAM_NAME ": You are attempting to access a node num greater then the current count of nodes." );
    }
    if(nodeNum==0){
        return head;
    }
    t_size nodeCurrent=0;
    SLLNode *current=head;
    while(nodeCurrent < nodeNum){
        current=current->getNext();
        nodeCurrent+=1;
    }
    return current;
}

void SinglyLinkedList::swapNodeData( SLLNode* aNode, SLLNode* bNode )
{
    int temp;

    temp = aNode -> getData();
    aNode -> setData( bNode -> getData() );
    bNode -> setData( temp );
}


void SinglyLinkedList::bubbleSort() {
    bool isSwapped = false;

    SLLNode* current = head;

    while( true ) {
        if( current -> getData() > current -> getNext() -> getData() ) {
            swapNodeData( current, current -> getNext() );
            isSwapped = true;
        }

        current = current -> getNext();

        if( current -> getNext() == nullptr ) {
            if( !isSwapped ) {
                return;
            }

            current = head;
            isSwapped = false;
        }
    }
}

void SinglyLinkedList::print() const noexcept {
    SLLNode *current=head;
    while(current){
        cout<<"SLLNode *"<< current  <<"  "<<current->getData()<<'\n' ;
        current=current->getNext();
    }
}
