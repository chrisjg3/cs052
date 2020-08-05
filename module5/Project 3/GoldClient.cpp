/*
* GoldClient.cpp
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

#include "GoldClient.h"


// ostream for GoldClients
ostream& GoldClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    out<< " </td> <td> " << this->getTier();
    return out;
}

// Relational Operator
bool GoldClient::operator>(Client* otherClPtr)
{
    switch (otherClPtr->getType())
    {
        // It is comparing a Gold to a Silver
        case '0':
            return true;

        // It is comparing a Gold to a Gold
        case '1':
        // First compares Tier to break the tie
            if(!(this->getTier() >= otherClPtr->getTier()))
            {
                return true;
            }
            // If the tier is equal, it will drop into this code block:
            else if (this->getTier() == otherClPtr->getTier())
            {
                // compares by Tenure next to try and break the tie
                    if(this->getTenure() > otherClPtr->getTenure())
                    {
                        return true;
                    }
                    else 
                    {
                        return false;
                    }
            }

            else // This is for if Tier is <
            {
                return false;
            }

        // It is comparing a Gold to a Platinum
        case '2':
            return false;
            

        // Default case:
        default:
            cout<<"\nError, Client Type Not Valid\n";
            return false;
    }
}