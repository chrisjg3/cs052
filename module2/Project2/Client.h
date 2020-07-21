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
    protected:
    string name;
    short tenure;  // NOTE: SAYS SHORT BUT SHOULD HANDLE FLOATS, SO EITHER ROUND OR MAKE FLOAT VARIABLE
    int rewardsPoints;
    

    public:
    // Main constructor used in the program
    Client(short ten, string nam);

    //Default Contrustor
    Client();

    // Destructor
    // Virtual to avoid warnings since this is an abstract class and has no instances
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