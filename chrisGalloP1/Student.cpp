/*
* Student.cpp
*
* COSC 052 2020
* Project 1
*
* Due on: July 7th, 2020
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

// Header file:
#include "Student.h"

// This is the defintion of the main student contructor
Student::Student(string inputname, float inputscore)
{
    name = inputname;
    score = inputscore;
}

// Default Consturctor
Student::Student()
{
    name = "\0";
    score = 0.0;
}

// Destructor
Student::~Student()
{

}