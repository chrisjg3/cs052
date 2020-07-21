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
class ClientList: public vector<Client*>
{
    public:

    // This is used to call the function for inputting from a file
    void inputFile(string);

    // This is used to call the function for inputting from console
    void consoleInput();

    ~ClientList();

    // This is for printing each Client ponter's Client Obj to console
    friend ostream &operator<<(ostream &out, ClientList &cl);
};


#endif