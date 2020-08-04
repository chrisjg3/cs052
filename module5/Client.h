/*
* Client.h
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

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

#include "SVector.h"

using namespace std;

/// This is the Abstract Class of Client.  No Instances of it exist.
/// It holds the basic attributes of all Clients and basic get functions.
/// <br>
/// It has getPoints() and getTier() Added as virtual functions because of the relational operator with polymorphism 
/// calls those functions from Client pointers and so it, along with all derived variations, must have a copy even though 
/// they will never use it.

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

    // Overloading the > operator
    virtual bool operator>(Client*) = 0;

    // Get accessor used to determine type for relational operator
    virtual char getType() = 0;

    // These needed so relational operator since calling sort through a template causes the compiler to throw
    // errors if the methods called don't exist.  Even though a Client object itself would never be asked to call
    // these methods.
    virtual float getPoints() = 0; 
    virtual char getTier() = 0;
};



#endif