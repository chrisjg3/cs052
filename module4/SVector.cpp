/*
* SVector.cpp
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

#include "SVector.h"

template <class T>
void SVector<T>::sort()
{
    // First for lopp goes through every position in vector (using x to signifiy each position)
    // The minus one is included because last position will end up being the largest.
    for(int x = 0; x<this->size() - 1; x++) 
    {
        int currentLowest = x;
        // Inner for loop goes through the remaining part of the vector after x, looking for the lowest value
        // then selects the lowest value, previous values don't need to be tested because they have previously been
        // established as lower then all remaining values
        for(int i = x; i<this->size(); i++)
        {            
            if ( *(this->at(currentLowest)) > (this->at(i)) )
            {
                currentLowest = i;
            }
        }
        // When exits the above loop, it has the lowest value for positions past x
        // Must create a temporary pointer (T in template) so previous value is not lost or memory leak made
        T tempPtr;
        
        tempPtr = this->at(x);
        this->at(x) = this->at(currentLowest);
        this->at(currentLowest) = tempPtr;
    }
    
}



// Needed because compiler issue?? ------------------------------- 
template class SVector<Client*>;