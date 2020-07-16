# First command to check the dependencies (object code), updates if needed, and then run linker to run code
p2: Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o Project2.o
		g++ -std=c++11 -o p2 Project2.cpp Client.cpp ClientList.cpp SilverClient.cpp GoldClient.cpp PlatinumClient.cpp


# This removes the object codes if need they are no longer up-to-date
clean: Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o Project2.o
		rm Client.o ClientList.o SilverClient.o GoldClient.o PlatinumClient.o Project2.o