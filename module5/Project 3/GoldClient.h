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
    /**
     * This is the only additional get function
     * \return tier is the tier attribute.
    */
    char getTier() { return tier; }

    /** The main constructor used by the program
     * \param tenure and \param name are just passed to the Client constructor
     * \param tier is the new attribute that is saved as an attribute
    */
    GoldClient(short tenure, string name, char tier): Client(tenure, name) { this->tier = tier; }

    /** ostream function for HTML stream, converst the GoldClient to an html row
     * \param &out is the cout object
     */
    ostream& htmlToStream(ostream &out);

    /** 
     * Get accessor used to determine type for relational operator
     * \return is either 0 or 1 or 2, depending on the Client derived class
    */ 
   char getType() { return '1'; }

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
    float getPoints() { return 0; }
};

#endif