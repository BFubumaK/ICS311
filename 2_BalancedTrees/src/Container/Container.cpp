///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2024
//
/// A generic interface for collections.
///
/// @file Container.cpp
/// @version 1.1
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
/// @author Jason Castiglione <jcastig@hawaii.edu>
/// @date   28_Mar_2024
///////////////////////////////////////////////////////////////////////////////
#include "../config.h"
#include "Container.h"
#include <boost/core/typeinfo.hpp>  // For typeinfo()

using namespace std;

Container::~Container(){
    delete containerRNG;
    delete genINTRNG;
}
/// @return `true` if the Container is empty.  `false` if the Container has one or more Nodes in it.
bool Container::isEmpty() const noexcept {
    return (count == 0);
}


/// @return The number of Nodes in the Container
Container::t_size Container::size() const noexcept {
    return count ;
}


void Container::dump() const noexcept {
    FORMAT_LINE_FOR_DUMP( "Object", "class" )  << boost::core::demangled_name( BOOST_CORE_TYPEID( *this )) << '\n';
    FORMAT_LINE_FOR_DUMP( "Object", "this" )  << this  <<'\n' ;
    FORMAT_LINE_FOR_DUMP( "Container", "count" ) << count << '\n' ;
}


Container::t_size Container::getRandomNodeNumber()   {
    if(count == 0){
        return -1;
    }
    if(count == 1 ){
        return 0;
    }
    int icount;
    icount=(int) count;
    if(containerRNG->max()!= (icount -1) || containerRNG->min() != 0) {
        decltype(containerRNG->param()) const new_range(0, icount-1);
        containerRNG->param(new_range);
    }
    return (Container::t_size) (*containerRNG)(trueRNG );
}

void Container::setMAXGENINT(int newMAXGENINT) {
    if(newMAXGENINT==MAXGENINT){
        return;
    }
    if(genINTRNG->max()!= (newMAXGENINT)|| genINTRNG->min() != 0) {
        decltype(genINTRNG->param()) const new_range(0, newMAXGENINT);
        genINTRNG->param(new_range);
    }
}

int Container::getRandomInt() {
    return  (*genINTRNG)(trueRNG );
}
