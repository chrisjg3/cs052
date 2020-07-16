#include "GoldClient.h"

ostream& GoldClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    out<< " </td> <td> " << this->getTier();
    return out;
}