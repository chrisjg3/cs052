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
        int currentHighest = x;

        for(int i = x; i<this->size(); i++)
        {            
            if ( *(this->at(i)) > (this->at(currentHighest)))
            {
                currentHighest = i;

                T tempPtr;
                tempPtr = this->at(x);
                this->at(x) = this->at(currentHighest);
                this->at(currentHighest) = tempPtr;
                tempPtr = nullptr;
            }
        }
    }
    
}



// This is needed to force a SVector template to be made with Client* 
// Otherwise, the compiler throws an error when trying to reference sort() from ClientList
template class SVector<Client*>;