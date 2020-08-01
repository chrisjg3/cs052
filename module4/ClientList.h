/*
* ClientList.h
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

#ifndef CLIENTLIST_H
#define CLIENTLIST_H

// Preprocessors
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>

// Header file for Client Class
#include "Client.h"
#include "SilverClient.h"
#include "GoldClient.h"
#include "PlatinumClient.h"
#include "SVector.h"

using namespace std;

/// ClientList Class
/// Client inherits from SVector which in turn inherits from the vector class
/// This means it inherits the sort function.

class ClientList : public SVector<Client*>
{
    public:

    // This is used to call the function for inputting from a file
    void inputFile(string);

    // This is used to call the function for inputting from console
    void consoleInput();

    // This is the destrcutor, used to free dynamically allocated memory
    ~ClientList();

    // This is for printing each Client ponter's Client Obj to console and output.txt
    // It sorts the ClientList first.
    friend ostream &operator<<(ostream &out, ClientList &cl);
};


#endif