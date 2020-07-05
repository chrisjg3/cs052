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

#include "Student.h"

// Defining the "Get" Accessor functions
inline string Student::getName() const { return name; }
inline int Student::getScore() const { return score; }

// Defining the "Set" Mutator Functions
inline void Student::setName(string inputname) {name = inputname; }
inline void Student::setScore(int inputscore) {score = inputscore; }

inline Student::Student(string inputname, int inputscore)
{
    name = inputname;
    score = inputscore;
}