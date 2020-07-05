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

#ifndef PROJECT1_H
#define PROJECT1_H

#include <iostream>
#include <vector>
#include "Student.cpp"
#include "HtmlStudentTable.cpp"

using namespace std;

// Stand-Alone Display Menu Function for Menu Options
char displayMenu();

// Stand-Alone Function For Reading File
void inputFile(string, vector<Student>&);

// Stand-Alone Function For Console Input
void consoleInput(vector<Student>&);


// Vector of Student objects defined
vector<Student>StudentVec;


/* TO DO:
1. Input File and Input Console Should be stand alone functions?
2. Check for any 'magic numbers'
3. Move single line defintions into header files
4. Make sure Syntax of #endif and #ifndef/#define is all correct / Specifics of mechanics
5. Print at end on Console and At end of File?
6. Correct the Student Honor Code Comments on Each File
7. Why did inline work?
8. Add Comments Everywhere
9. Review PDF and make sure everything required and on rubric matches
10. Look through code and clean up cin.ignores and extra things that are not needed like inline
11. Need to make sure all the things set for presentation (espcially in input console) and removed or corrected
12. Add Default contructors and such
*/

#endif