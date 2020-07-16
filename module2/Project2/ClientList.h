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

    void inputFile(string);

    void consoleInput();


    friend ostream &operator<<(ostream &out, ClientList &cl);
};


#endif