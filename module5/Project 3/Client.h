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
/// It has getPoints() and getTier() added as virtual functions because of the relational operator with polymorphism 
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
    /**
    *  This is the main constructor of Client
    *  \param ten is an inputted tenure
    *  \param nam is an inputted name
    */
    Client(short ten, string nam);
    
    /** 
     * Default Contrustor
    */
    Client();

    /** Destructor
    * Since delete is called (on Client Pointers with polymorphism), virtual is needed to avoid warning
    * from compiler about only having the super class destrcutor called.
    */
    virtual ~Client();

    
    // These are the accessor functions.
    /**
     * \returns name
    */
    string getName() { return name; }
    /**
     *  \returns tenure
    */
    short getTenure() { return tenure; }

    /** Abstract data function, marks Client as an abstract class
    */
    virtual ostream& htmlToStream (ostream &) = 0;

    /** Friend function for stream operator
     * \param out& is the cout stream object
     * \param cl* is a client pointer to be added to stream
    */
    friend ostream& operator<<(ostream&out, Client *cl);

    /** Overloading the > operator.  This is also set as an abstract method.
     * \param Client* is one of the pointers in ClientList
    */
    virtual bool operator>(Client*) = 0;

    /** Get accessor used to determine type for relational operator
    */
    virtual char getType() = 0;

    // These functions are needed otherwise the compiler thorws an error when the relational operator
    // is used on a Client pointer.  Unlike Project2's polymorphism, Project3 has these methods called 
    // from the Client pointer itself, so this base class and all derived classes need a copy to prevent
    // a undefined reference exception from being thrown.
    /**
     * As mentioned in comments, this is here to prevent an error when Client Pointer is asked to run this function.
     * It needs a copy even though it is only a Plantinum Client that will use it. 
    */
    virtual float getPoints() = 0; 
    /**
     * As mentioned in comments, this is here to prevent an error when Client Pointer is asked to run this function.
     * It needs a copy even though it is only a Gold or Plantinum Client that will use it. 
    */
    virtual char getTier() = 0;
};



#endif