#ifndef GOLDCLIENT_H
#define GOLDCLIENT_H


#include "Client.h"


class GoldClient:public Client
{
    private:
    char tier;

    public:
    // Get (Accessor) Function
    char getTier() { return tier; }

    // The main constructor used by the program
    GoldClient(short tenure, string name, char tier): Client(tenure, name) { this->tier = tier; }

    ostream& htmlToStream(ostream &out);

};

#endif