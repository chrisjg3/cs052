/*
* Client.h
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

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

class Client
{
    // Protected Variables that are in all Dervied Client Objects
    protected:
    string name;
    short tenure; 
    int rewardsPoints;
    

    public:
    // Main constructor used in the program
    Client(short ten, string nam);

    //Default Contrustor
    Client();

    // Destructor
    // Since delete is called (on Client Pointers), virtual is needed to avoid warning.
    virtual ~Client();

    // Get (Accessor) Functions
    string getName() { return name; }
    short getTenure() { return tenure; }

    // Abstract data function, marks Client as an abstract class
    virtual ostream& htmlToStream (ostream &) = 0;

    // Friend function for stream operator
    friend ostream& operator<<(ostream&out, Client *cl);
};



#endif