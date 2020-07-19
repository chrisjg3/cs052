#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>

using namespace std;

class Client
{
    protected:
    string name;
    short tenure;  // NOTE: SAYS SHORT BUT SHOULD HANDLE FLOATS, SO EITHER ROUND OR MAKE FLOAT VARIABLE
    int rewardsPoints;
    

    public:
    // Main constructor used in the program
    Client(short ten, string nam);

    //Default Contrustor
    Client();

    //Destructor
    ~Client();

    // Get (Accessor) Functions
    string getName() { return name; }
    short getTenure() { return tenure; }

    // Abstract data function
    virtual ostream& htmlToStream (ostream &) = 0;

    friend ostream& operator<<(ostream&out, Client *cl);
};



#endif