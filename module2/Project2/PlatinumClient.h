#ifndef PLATINUMCLIENT_H
#define PLATINUMCLIENT_H


#include "Client.h"




class PlatinumClient:public Client
{
    private:
    short plantinumPoints;
    char tier;

    // Public Functions Start Here
    public:
    short getPoints() { return plantinumPoints; }
    char getTier() { return tier; }

    // Constructor
    PlatinumClient(short tenure, string name, char tier, short plantinumPoints): Client(tenure, name) 
    { 
        this->tier = tier;
        this->plantinumPoints = plantinumPoints;
    }

    // HTML ostream function
    ostream& htmlToStream(ostream &out);

    friend ostream& operator<<(ostream&out, Client *cl);



};

#endif