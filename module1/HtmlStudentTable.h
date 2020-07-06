/*
* HtmlStudentTable.h
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
#ifndef HTMLSTUDENTTABLE_H
#define HTMLSTUDENTTABLE_H



#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

//Class Starts
class HtmlStudentTable 
{
    // Priavte Starts Here:
    private:
    vector<Student>studentVec;

    // Public Starts Here:
    public:
    HtmlStudentTable(vector<Student>);

    // ostream decalred friend so that table can be read from cout.
    friend ostream &operator<<(ostream& out, const HtmlStudentTable &set);
};

#endif