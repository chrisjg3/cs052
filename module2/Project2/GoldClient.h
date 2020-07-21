/*
* GoldClient.h
*
* COSC 052 2020
* Project 2
*
* Due on: July 21st
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
    char tier;

    public:
    // Get (Accessor) Function
    char getTier() { return tier; }

    // The main constructor used by the program
    GoldClient(short tenure, string name, char tier): Client(tenure, name) { this->tier = tier; }

    ostream& htmlToStream(ostream &out);

};

#endif