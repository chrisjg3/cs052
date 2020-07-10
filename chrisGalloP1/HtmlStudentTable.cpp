/*
* HtmlStudentTable.cpp
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

// Header file for this specific .cpp:
#include "HtmlStudentTable.h"

// Building a table constructor (from student class vector)
HtmlStudentTable::HtmlStudentTable(vector<Student> &inputStudentVector)
{
    // Goes through that vector and assigns it to the HtmlStudentTable object's vector attribute
    for(unsigned short i = 0; i<inputStudentVector.size(); i++)
    {
        studentVec.push_back(inputStudentVector[i]);
    }

    // I built the output file within the constructor, rather then in the console input
    // So it is built after data validation when it is passed to build a table.
    ofstream outputFile;
    outputFile.open("HtmlTableOutput.txt");

    // Here begins the output stream to write in the file:
    // First line of html table
    outputFile<<"table border = '1'> \n";
    outputFile<<"\t <tr> <td> Student </th> <th> Score </th> </tr> \n";

    // Enter loop to add Students
    for(unsigned short j = 0; j<inputStudentVector.size(); j++)
    {
        // After table head is printed, this is repeated for each Student object to create
        // the "meat" of the table
        outputFile<<"\t <tr> <td> " << inputStudentVector[j].getName();
        outputFile<< " </th> <th> " << inputStudentVector[j].getScore();
        outputFile<< " </td></tr> \n";
    }

    // Ending table
    outputFile<<"</table>";
    // File Closed
    outputFile.close();
    cout<<"\nNew HTML Table Saved to File.\n";
}




ostream &operator<<(ostream& out, const HtmlStudentTable &table)
{
    // First line of html table
    out<<"table border = '1'> \n";
    out<<"\t <tr> <td> Student </th> <th> Score </th> </tr> \n";

    // Enter loop to add Students
    for(unsigned short j = 0; j<table.studentVec.size(); j++)
    {
        // After table head is printed, this is repeated for each Student object to create
        // the "meat" of the table
        out<<"\t <tr> <td> " << table.studentVec[j].getName();
        out<< " </th> <th> " << table.studentVec[j].getScore();
        out<< " </td></tr> \n";
    }

    // Ending table
    out<<"</table>";
    return out;
}

// Default Constructor
HtmlStudentTable::HtmlStudentTable()
{
 // Will have a empty vector from class definition
}


// Destructor
HtmlStudentTable::~HtmlStudentTable()
{
studentVec.clear();
}