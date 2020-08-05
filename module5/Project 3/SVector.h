/*
* SVector.h
*
* COSC 052 2020
* Project 3
*
* Due on: August 2nd
* Author: Christopher Gallo
*
*
* In accordance with the class policies and Georgetown's
* Honor Code, I certify that, with the exception of the
* class resources and those items noted below, I have neither
* given nor received any assistance on this project.
*
* References not otherwise commented within the program source code.
* Note that you should not mention any help from the TAs, the professor,
* or any code taken from the class textbooks.
*/ 

#ifndef SVECTOR_H
#define SVECTOR_H

#include <vector>
#include "Client.h"

using namespace std;

/// Template Class Used to Hold the Sort Function
///
/// The sort function allows an array of T Objects to be sorted using the relational operator
template <class T>
class SVector: public vector<T>
{
    public:
    /**
     * Sort is the only additional function added to vector to creaet SVector (which ClientList inherits from).
     * Sort rearranges the objects (in this case Client Pointers) in descending order.
    */
    void sort();  

};

#endif