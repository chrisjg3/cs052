/*
* Client.cpp
*
* COSC 052 2020
* Project 3
*
* Due on: August 2nd
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

// This is the main contructor used in the other derived contructors:
Client::Client(short ten, string nam)
{
    tenure = ten;
    name = nam;
}



Client::Client()
{
    // Default Constructor
}


Client::~Client()
{
    // Default Destrcutor
}
