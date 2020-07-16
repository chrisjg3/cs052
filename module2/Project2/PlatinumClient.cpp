#include "PlatinumClient.h"

ostream& PlatinumClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    out<< " </td> <td> " << this->getTier();
    out<< " </td> <td> " << this->getPoints();
    return out;
}