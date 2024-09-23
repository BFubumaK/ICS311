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
    public:   ///////////////////// Constructors & Destructors /////////////////////
        BSTData() = default;   ///< Default constructor
        BSTData(char eng, char ole); ///< Creates a data class with both english and hawaiian phrases
        ~BSTData(); /// Destructor to free data
        
        ////////////////////////// Getters and Setters
        char getData() const;
        void setData( char eng, char ole);
};