/*
* GoldClient.cpp
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

#include "GoldClient.h"


// ostream for GoldClients
ostream& GoldClient::htmlToStream(ostream &out)
{
    out<<"\t <tr> <td> " << this->getName();
    out<< " </td> <td> " << this->getTenure();
    out<< " </td> <td> " << this->getTier();
    return out;
}