///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// A generic interface for collections.
///
/// @file SLLNode.h
/// @version 1.1
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////

#include "SLLNode.h"
#include "../config.h"
#include <iostream>


using namespace std;
SLLNode::SLLNode(int newData){
    next= nullptr;
    data= newData;
}

SLLNode::SLLNode(int newData, SLLNode *newNext){
    next=newNext;
    data=newData;
}

SLLNode::~SLLNode() {
    reset();
}

void SLLNode::reset() noexcept {
    next = nullptr;
}

SLLNode* SLLNode::getNext()  {
    return next;
}
int SLLNode::getData() const {
    return data;
}

void SLLNode::setData(int newData) {
    data=newData;
}
void SLLNode::setNext(SLLNode* next)  {
    this->next=next;
}

/// Check the SLLNode.
///
/// This method checks the SLLNode.  If something is not right,
/// print out a message and stop the validation.  It will not throw an
/// exception.
///
/// @return True if the SLLNode is healthy
bool SLLNode::validate() const noexcept {
    /// #### Internal
    /// Iterate along the next pointers and verify that they do not
    /// refer back to themselves.  This also has the benefit of dereferencing
    /// all of the downstream next/prev pointers and ensuring they point to
    /// valid addresses.

    if( next != nullptr ) {
        SLLNode* currentPointer = next->next;
        while( currentPointer != nullptr ) {
            if( next == currentPointer ) {
                cout << PROGRAM_NAME << ": Recursive loop detected along next!";
                return false;
            }
            currentPointer = currentPointer->next;
        }
    }

    return true;
}














