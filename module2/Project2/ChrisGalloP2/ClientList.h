/*
* ClientList.h
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

using namespace std;

// ClientList Class
class ClientList
{
    public:

    // This is used to call the function for inputting from a file
    void inputFile(string);

    // This is used to call the function for inputting from console
    void consoleInput();

    // This is the destrcutor, used to free dynamically allocated memory
    ~ClientList();

    // Function to save the HTML Table to a file
    void saveToFile();

    // This is for printing each Client ponter's Client Obj to console
    friend ostream &operator<<(ostream &out, ClientList &cl);

    // This is the vector that is used to store Client pointers to the different clients
    private:
    vector<Client*>vl;
};


#endif