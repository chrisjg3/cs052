/*
* project1.h
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

#ifndef PROJECT1_H
#define PROJECT1_H



#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include "HtmlStudentTable.cpp"
#include "Student.cpp"

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
1. Check Web and fix this duplicate file error problem
2. Check for any 'magic numbers'
3. Move single line defintions into header files
4. Make sure Syntax of #endif and #ifndef/#define is all correct / Specifics of mechanics
5. Print at end on Console and At end of File?
6. Check the Student Honor Code Comments on Each File

8. Add Comments Everywhere
9. Review PDF and make sure everything required and on rubric matches
10. Look through code and clean up any un-needed lines and code (Need to make sure all the things set for presentation were removed)

12. Add Default contructors and such

14. Make HTML table pass by refernece
15. Test compile on course server
16. Double check all best practices (like default constructor and destructor and such)
17. Should be using set functions, but I don't think they are anywhere
*/

#endif