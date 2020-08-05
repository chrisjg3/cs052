/*
* PlatinumClient.h
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

#ifndef PLATINUMCLIENT_H
#define PLATINUMCLIENT_H


#include "Client.h"


/// This is the PlantinumClient Summary.
///
/// This class has a similar strucutre to both SilverClient and GoldClient.
/// The only difference being that both getTier() and getPoints() actually return
/// attributes and the relational operators are adjusted accordingly.


class PlatinumClient:public Client
{
    // private attributes, tier needed as well as points
    private:
    float plantinumPoints;
    char tier;

    // Public Functions Start Here
    public:
    /**
     *  getPoints is added as platinium is the only class that has points
     *  \return is the plantinumPoints attribute
    */ 
    float getPoints() { return plantinumPoints; }
    /**
     * This is the accessor function for tier
     * \return is the tier attribute
    */ 
    char getTier() { return tier; }

    /** 
     * Get accessor used to determine type for relational operator
     * \return is either 0 or 1 or 2, depending on the Client derived class
    */
   char getType() { return '2'; }

    /** Constructor
    * This is the main contrcutor
    * \param tenure is passed to base class
    * \param name is passed to base class
    * \param tier is set to tier by the Platinum Contrcutor
    * \param plantinumPoints is set to plantinumPoints by the Platinum Contrcutor
    */
    PlatinumClient(short tenure, string name, char tier, float plantinumPoints): Client(tenure, name) 
    { 
        this->tier = tier;
        this->plantinumPoints = plantinumPoints;
    }

    /** 
     * HTML ostream function, converts Plantintum Object into an html row
     * \param out& is the cout stream object
    */
   ostream& htmlToStream(ostream &out);

    /** 
     * Overloaded stream operator
     * \param out& is the cout stream object
     * \param cl* is the ClientList
    */
   friend ostream& operator<<(ostream&out, Client *cl);

    /** 
     * Relational Operator
     * \param Client* is passed from the ClientList in the sort function to this operator
    */
   virtual bool operator>(Client*);
};

#endif