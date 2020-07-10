# 
#  Makefile
# 
#  COSC 052 2020
#  Project 1
# 
#  Due on: July 7th, 2020
#  Author: Christopher Gallo
# 
# 
#  In accordance with the class policies and Georgetown's
#  Honor Code, I certify that, with the exception of the
#  class resources and those items noted below, I have neither
#  given nor received any assistance on this project.
# 
#  References not otherwise commented within the program source code.
#  Note that you should not mention any help from the TAs, the professor,
#  or any code taken from the class textbooks.


# First command to check the dependencies (object code), updates if needed, and then run linker to run code
p1: Student.o HtmlStudentTable.o Project1.o
		g++ -std=c++11 -o p1 Project1.cpp Student.cpp HtmlStudentTable.cpp


# This removes the object codes if need they are no longer up-to-date
clean: Student.o HtmlStudentTable.o Project1.o
		rm Student.o HtmlStudentTable.o Project1.o
