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

// This is the main sort method
template <class T>
void SVector<T>::sort()
{
    // Two loops are used, one goes through each index position represented by the value x
    // The next loop goes through the all positions after x and compares
    for(int x = 0; x<this->size() - 1; x++) 
    {
        // current highest set to current x position
        int currentHighest = x;

        for(int i = x; i<this->size(); i++)
        {
            // goes through each i index after x and compares            
            if ( *(this->at(i)) > (this->at(currentHighest)))
            {
                currentHighest = i;
                // if a new high value is found, i is swapped with the current value at x (using a temporary pointer)
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