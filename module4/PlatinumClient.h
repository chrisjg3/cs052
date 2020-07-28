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





class PlatinumClient:public Client
{
    // private attributes, tier needed as well as points
    private:
    float plantinumPoints;
    char tier;

    // Public Functions Start Here
    public:
    float getPoints() { return plantinumPoints; }
    char getTier() { return tier; }
    // Get accessor used to determine type for relational operator
    char getType() { return '2'; }

    // Constructor
    PlatinumClient(short tenure, string name, char tier, float plantinumPoints): Client(tenure, name) 
    { 
        this->tier = tier;
        this->plantinumPoints = plantinumPoints;
    }

    // HTML ostream function
    ostream& htmlToStream(ostream &out);

    // Overloaded stream operator
    friend ostream& operator<<(ostream&out, Client *cl);

    // Relational Operator
    virtual bool operator>(Client*);
};

#endif