///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2024
//
/// A generic interface for collections.
///
/// @file Container.h
/// @version 1.1
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
/// @author Jason Castiglione <jcastig@hawaii.edu>
/// @date   28_Mar_2024
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../config.h"
#include <cassert>

#include <random>       // For uniform_int_distribution<>




/// The root of the collection hierarchy.
///
/// Java calls these *Collections*.  The C++ STL calls them *Containers*.  Both
/// hold a group of Objects (that inherit from SLLNode).  Some Containers have keys
/// like Cat.type and some require unique keys.
///
/// Our collection framework takes inspiration from both
/// [Java](https://docs.oracle.com/javase/8/docs/technotes/guides/collections/overview.html)
/// and the
/// [C++ STL](https://en.cppreference.com/w/cpp/container), but
/// implements a reduced set of methods, mostly because Animal Farm meant for teaching.
///
/// The Containers library is a generic collection of class templates and
/// algorithms that allow us to implement common data structures like
/// DoublyLinkedList and BinarySearchTree on the SLLNode class.  Because Animal Farm will demonstrate
/// the utility of Generic/Template programming, we will implement a Cat specific
/// version of these data structures using classes like CatEmpire and CatWrangler.
///
/// We know some things about this Container, like the number of Nodes it has,
/// but this class does not provide any implementation.
///
/// According to the Rule of Three, this class has a:
///   - Copy constructor
///   - Assignment overload
///   - Destructor
///
/// The default constructor is enabled and working.  The copy and assignment
/// overload are disabled and will generate compiler errors.  This ensures
/// that nobody tries to copy a Binary Search Tree.  Essentially, we are saying
/// Animal Farm does not support "deep copies".  We don't need a destructor because
/// we've disabled the copy constructor and assignment overload.
///
/// @see https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
/// @see https://docs.oracle.com/javase/8/docs/api/java/util/Collection.html
///
class Container {
public:  //////////////// Enumerations & Type Definitions //////////////////////

    /// The native datatype of the Container's count/size
    typedef unsigned int t_size;

public:   ///////////////////// Constructors & Destructors /////////////////////
    explicit Container() = default;   ///< Default constructor (allowed)
    constexpr Container(const Container&) = delete;   ///< Copy constructor for a Container is not allowed
    ~Container();
    constexpr Container& operator=( const Container& copyFrom ) = delete;  ///< Assignment constructor for a Container is not allowed

protected:  ////////////////////// Protected Members ///////////////////////////

    int MAXGENINT=100000;
    t_size count = 0 ;   ///< Maintain a count of the number of Nodes in this Container
    std::uniform_int_distribution<> *containerRNG= new std::uniform_int_distribution<>(0,1);
    std::uniform_int_distribution<> *genINTRNG= new std::uniform_int_distribution<>(0,MAXGENINT);
    std::random_device trueRNG;

public:  /////////////////////////// Public Methods ////////////////////////////

    virtual bool   isEmpty()                 const noexcept;   ///< `true` if the Container is empty
    virtual t_size size()                    const noexcept;   ///< Return the number of Nodes in the Container
    virtual void   empty()            = 0;         ///< Remove all of the Nodes from the Container and frees the associated memory
    virtual t_size getRandomNodeNumber()  ;   ///< Generates a number to pick a random SLLNode from the Container
    void setMAXGENINT(int newMAXGENINT);
    int getRandomInt();
    virtual void   dump()          const noexcept;             ///< Output the member variables in this object
    virtual void print() const noexcept=0; ///< Print the data for each element in the container
};

