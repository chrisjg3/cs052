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

#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
using namespace std;

// Class Starts
class Student
{
    // Priavte Starts Here
    private:
    string name;
    int score;

    // Public Starts Here
    public:
    // Get Accessor Functions
    string getName() const;
    int getScore() const;
    // Set Mutator Functions
    void setName(string name);
    void setScore(int score);

    Student(string name, int score);
};

#endif