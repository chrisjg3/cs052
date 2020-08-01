/*
* SilverClient.cpp
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

#include "SilverClient.h"

// ostream for silver client
ostream& SilverClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    return out;
}

// Relational Operator
bool SilverClient::operator>(Client* otherClPtr)
{
    // Determine which block it falls into:
    switch (otherClPtr->getType())
    {
        // It is comparing a Silver to a Silver
        case '0':
            if(this->getTenure()>otherClPtr->getTenure())
            {
                return true;
            }
            else
            {
                return false;
            }

        // It is comparing a Silver to a Gold
        case '1':
        return false;

        // It is comparing a Silver to a Platinum
        case '2':
        return false;

        // Default case:
        default:
        cout<<"\nError, Client Type Not Valid\n";
        return false;
    }

}