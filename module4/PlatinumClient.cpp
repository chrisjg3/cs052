/*
* PlatinumClient.cpp
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

#include "PlatinumClient.h"

// ostream operator for platinum clients
ostream& PlatinumClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    out<< " </td> <td> " << this->getTier();
    out<< " </td> <td> " << this->getPoints();
    return out;
}

bool PlatinumClient::operator>(Client* otherClPtr)
{
    switch (otherClPtr->getType())
    {
        // It is comparing a Silver to a Silver
        case '0':
            return true;

        // It is comparing a Silver to a Gold
        case '1':
            return true;
            
            

        // It is comparing a Silver to a Platinum
        case '2':
            if(this->getTier() > otherClPtr->getTier())
            {
                return true;
            }
            
            else if (this->getTier() == otherClPtr->getTier())
            {
                if (this->getPoints() > otherClPtr->getPoints())
                {
                    return true;
                }
                else if (this->getPoints() == otherClPtr->getPoints())
                {
                    // Since Tier and Points are equal, it goes by Tenure
                    if(this->getTenure()>otherClPtr->getTenure())
                    {
                        return true;
                    }
                        else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                
            }

            else
            {
                return false;
            }

        // Default case:
        default:
            cout<<"\nError, Client Type Not Valid\n";
            return false;
    }
}