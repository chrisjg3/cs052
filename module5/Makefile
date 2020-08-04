# /*
# * Makefile
# *
# * COSC 052 2020
# * Project 3
# *
# * Due on: August 2nd
# * Author: Christopher Gallo
# *
# *
# * In accordance with the class policies and Georgetown's
# * Honor Code, I certify that, with the exception of the
# * class resources and those items noted below, I have neither
# * given nor received any assistance on this project.
# *
# * References not otherwise commented within the program source code.
# * Note that you should not mention any help from the TAs, the professor,
# * or any code taken from the class textbooks.
# */ 


# First command to check the dependencies (object code), updates if needed, and then run linker to run code
p3: Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o SVector.o Project3.o
		g++ -std=c++11 -o p3 Project3.cpp Client.cpp ClientList.cpp SilverClient.cpp GoldClient.cpp PlatinumClient.cpp SVector.cpp


# This removes the object codes if need they are no longer up-to-date
clean: Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o SVector.o Project3.o
		rm Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o SVector.o Project3.o