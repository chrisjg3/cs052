#include "SilverClient.h"

ostream& SilverClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    return out;
}