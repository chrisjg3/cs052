/*
* SilverClient.h
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

#ifndef SILVERCLIENT_H
#define SILVERCLIENT_H


#include "Client.h"

/// The SilverClient is the first version of Client
///
/// It has only two attributes: Name and Tenure
/// getPoints() and getTier() made so that compiler does not through error with sort method
/// Although the sort method would never call those functions, as the type is determined before
/// that code meaning no SilverClient will be asked for Tier or Points. 
///
/// Relational Operator is built as a method, rather then a friend

class SilverClient:public Client
{
    public:
    // Main Constructor
    SilverClient(short tenure, string name): Client(tenure, name)
    {
    }

    // Get accessor used to determine type for relational operator
    char getType() { return '0'; }

    // stream to HTML 
    ostream& htmlToStream(ostream &out);

    // Relational Operator
    virtual bool operator>(Client*);

    // These two methods are created so that compiler does not throw an unreferenced reference exception.
    // This is because the polymorphism of the ClientList vector means Client pointers are asked
    // to call all 4 types of attribute get functions, so every derived class must have a copy.
    float getPoints() {return 0;}
    char getTier() {return '\0'; }
};

#endif