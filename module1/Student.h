/*
* Student.h
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
    float score;

    // Public Starts Here
    public:
    // Get Accessor Functions
    string getName() const { return name; }
    float getScore() const { return score; }

    // Set Mutator Functions
    void setName(string inputname) {name = inputname; }
    void setScore(float inputscore) {score = inputscore; }

    Student(string name, float score);
};

#endif