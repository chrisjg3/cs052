#ifndef SILVERCLIENT_H
#define SILVERCLIENT_H


#include "Client.h"


class SilverClient:public Client
{
    public:
    // Main Constructor
    SilverClient(short tenure, string name): Client(tenure, name)
    {
        // Does Nothing Else??? ---------------------------------------------------
    }


    virtual ostream& htmlToStream(ostream &out);


};

#endif