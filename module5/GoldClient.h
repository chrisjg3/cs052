/*
* GoldClient.h
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

#ifndef GOLDCLIENT_H
#define GOLDCLIENT_H


#include "Client.h"

/// This is the Gold Client.
///
/// It is similar to Silver, but with an updated relational operator
/// and getTier() returns an attrribute.
/// Once again, however, getPoint() is included to keep the compiler from throwing an error.
/// This happens because the sort method calls this on client pointers, so all derived classes
/// Must have a copy, even though no GoldClient can ever be asked for this method in the sort function.

class GoldClient:public Client
{
    private:
    // new attribute for Gold class
    char tier;

    public:
    // Get (Accessor) Function
    char getTier() { return tier; }

    // The main constructor used by the program
    GoldClient(short tenure, string name, char tier): Client(tenure, name) { this->tier = tier; }

    // ostream function for HTML stream
    ostream& htmlToStream(ostream &out);

    // Get accessor used to determine type for relational operator
    char getType() { return '1'; }

    // Relational Operator
    virtual bool operator>(Client*);

    // As mentioned above, this is here so that the compiler does not throw an error.
    // Because a Client pointer is asked to used getPoints(), all derived classes must have a copy.
    float getPoints() { return 0; }
};

#endif