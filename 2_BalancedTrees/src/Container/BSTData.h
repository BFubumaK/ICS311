///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          2_BalancedTrees - ICS 311 - Fall 2024
//
/// data for binary search trees
///
/// @file BSTData.h
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

class BSTData {
    protected:  /////////////////// Member Variables /////////////////////////////
        std::list < engPhrasePointer* > &engPhrase;
        std::list < olePhrasePointer* > &olePhrase;
        std::list < explainPointer* >   &explainPhrase;


    public:   ///////////////////// Constructors & Destructors /////////////////////
        BSTData() = default;   ///< Default constructor
        BSTData( list < engPhrasePointer* > &engPhrase, 
                 list < olePhrasePointer* > &olePhras0, 
                 list < explainPointer*   > &explainPhrase ); ///< Creates a data class with both english and hawaiian phrases
                 
        ~BSTData(); /// Destructor to free data

        ////////////////////////// Getters and Setters /////////////////////////////
        char getDataEng();
        char getDataOle();
        void setData( list < engPhrasePointer* > &engPhrase, 
                      list < olePhrasePointer* > &olePhras0, 
                      list < explainPointer*   > &explainPhrase );
};