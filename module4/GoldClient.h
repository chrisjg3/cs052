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

    // Need these here for relational operator to work, should I do somethign else? ----------------------
    float getPoints() { return 0; }
};

#endif