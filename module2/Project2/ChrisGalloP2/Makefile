# /*
# * Makefile
# *
# * COSC 052 2020
# * Project 2
# *
# * Due on: July 21st
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
p2: Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o Project2.o
		g++ -std=c++11 -o p2 Project2.cpp Client.cpp ClientList.cpp SilverClient.cpp GoldClient.cpp PlatinumClient.cpp


# This removes the object codes if need they are no longer up-to-date
clean: Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o Project2.o
		rm Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o Project2.o