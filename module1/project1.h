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
#include "Student.h"
#include "HtmlStudentTable.h"
// #include "HtmlStudentTable.cpp"
// #include "Student.cpp"

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


3. Check MakeFile Works
1. MAKE SURE TO DELETE THIS TO DO LIST








Last-minute before submit:
1. MAKE SURE TO DELETE THIS TO DO LIST
2. Check for any 'magic numbers'
18. Double check everything on course server
6. Check the Student Honor Code Comments on Each File
10. Look through code and clean up any un-needed lines and code (Need to make sure all the things set for presentation were removed)
7.  Double check cleaning up any lines
4. Make sure Syntax of #endif and #ifndef/#define is all correct / Specifics of mechanics
15. Double check names for files and zip
11. What you gonna do about set functions?
8. Run the whole thing again on console doing errors on file and console input, error to find file, adding to display, check if file created good
*/


// Ask for TA
// Ask about constructor and desctructor for Student adn HtmlStudentTable
// Makefile including the c++11 and -o
// with  --stdc++11 is it in the right place for -o
// Clean cleans the the old object out or all?  Check makefile comment
// Is table output in the right place?
// Maybe run through and see if they have any concepts
// Genuine curious: how to know what order to do .cpp, what does obj file look like?
// Any best practices we might forget? 16. Any other best practices you could be forgetting?




#endif