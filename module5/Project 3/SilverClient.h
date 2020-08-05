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
    /**
     * Main Constructor
     * \param tenure is passed to the Client constructor
     * \param name is passed to the Client constrcutor
    */
    SilverClient(short tenure, string name): Client(tenure, name)
    {
    }

    /** 
     * Get accessor used to determine type for relational operator
     * \return is either 0 or 1 or 2, depending on the Client derived class
    */
   char getType() { return '0'; }

    /** 
     * Stream to HTML, allows SilverClient to be formattedf into an html row
     * \param out& is the cout stream object
    */  
    ostream& htmlToStream(ostream &out);

    /** 
     * Relational Operator
     * \param Client* is passed from the ClientList in the sort function to this operator
    */
    virtual bool operator>(Client*);

    /**
     * As mentioned in the Client base class comments, the compiler with throw an error in Project 3 because
     * we call these methods from Client pointers (unlike Project2) so to prevent the error, all derived versions
     * of the class must have a copy of all methods, even though Gold will never get asked to getPoints()
     * \return is just 0, as it has no point attribute
    */
    float getPoints() {return 0;}
    /**
     * Similarly to getPoints(), SilverClient needs a getTier() despite never having it be used. The compiler with throw an error in Project 3 because
     * we call these methods from Client pointers (unlike Project2) so to prevent the error, all derived versions
     * of the class must have a copy of all methods.
     * \return is the null character as SilverClient has no Tier attribute
    */
    char getTier() {return '\0'; }
};

#endif