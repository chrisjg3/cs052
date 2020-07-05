/*
* <FileName>.<file extension>
*
* COSC 052 <term year>
* Project <>
*
* Due on: <Due Date>
* Author: <your name>
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

#include "HtmlStudentTable.h"

// Building a table constructor (from student class vector)
HtmlStudentTable::HtmlStudentTable(vector<Student> inputStudentVector)
{
    for(unsigned short i = 0; i<inputStudentVector.size(); i++)
    {
        studentVec.push_back(inputStudentVector[i]);
    }
}




ostream &operator<<(ostream& out, const HtmlStudentTable &table)
{
    // First line of html table
    out<<"table border = '1'> \n";
    out<<"\t <tr> <td> Student </th> <th> Score </th> </tr> \n";

    // Enter loop to add Students
    for(unsigned short j = 0; j<table.studentVec.size(); j++)
    {
        out<<"\t <tr> <td> " << table.studentVec[j].getName();
        out<< " </th> <th> " << table.studentVec[j].getScore();
        out<< " </td></tr> \n";
    }

    // Ending table
    out<<"</table>";
    return out;

}
