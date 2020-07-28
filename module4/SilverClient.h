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

    // Need these here for relational operator to work, should I do somethign else? ----------------------
    float getPoints() { return 0; }
    char getTier() { return '\0'; }
};

#endif