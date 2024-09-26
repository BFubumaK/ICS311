///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// data class for binary search trees
///
/// @file BSTData.cpp
/// @version 1.0
///
/// @author Brian Kim <brianiki@hawaii.edu>
/// @date   23_Sep_2024
///////////////////////////////////////////////////////////////////////////////
#include "BSTData.h"

using namespace std;

BSTData () = default;   ///< Default constructor

BSTData::BSTData( std::string olelo, 
                  std::string english, 
                  std::string explanation, 
                  std::string color ) {

    oleloPhrase       = olelo;
    englishPhrase     = enlish;
    phraseExplanation = explanation;
    nodeColor         = color;
};

BSTData::~BSTData () {

    reset();

};
        
char getDataEng () {

    return engPhrase;

};

char getDataOle () {

    return olePhrase;

};

void BSTData::setData ( list < engPhrasePointer* > &engPhrase, 
                        list < olePhrasePointer* > &olePhras0, 
                        list < explainPointer*   > &explainPhrase ) {

};
