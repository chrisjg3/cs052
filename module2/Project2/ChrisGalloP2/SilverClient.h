/*
* SilverClient.h
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

    // stream to HTML 
    ostream& htmlToStream(ostream &out);
};

#endif