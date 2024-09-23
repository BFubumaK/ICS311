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
BSTData ( char eng, char ole ); ///< Creates a data class with both english and hawaiian phrases

BSTData::BSTData( char eng, char ole ) {

    engPhrase = eng;
    olePhrase = ole;

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

void BSTData::setData ( char eng, char ole ) {

    engPhrase = eng;
    olePhrase = ole;

};
