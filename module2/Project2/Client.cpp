/*
* Client.cpp
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

#include "Client.h"

Client::Client(short ten, string nam)
{
    tenure = ten;
    name = nam;
}




ostream& operator<<(ostream&out, Client *cl)
{
    // Totally overridden by each derived class
}




Client::Client()
{
    // Default Constructor
}


Client::~Client()
{
    // Default Destrcutor
}
