/*
* Project3.cpp
*
* COSC 052 2020
* Project 3
*
* Due on: August 2nd
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

#include "Project3.h"
using namespace std;

char displayMenu();


int main()
{
    ClientList cl;

    // defining menu variables
    bool menuActive = true; // For Continueing Menu Loop until user exits.
    char choice;  // This is for menu option selection.

    // Starting Menu Loop
    while (menuActive)
    {
        // First run the menu options
        choice = displayMenu();

        // Determine what to run based on choice
        if (choice == '1') // File Input
        {
            cout<<"Please enter the file name: \n";
            string fileName;
            cin>>fileName;
            cl.inputFile(fileName);
        }
        else if (choice == '2') // Console Input
        {
            cl.consoleInput();
        }
        else if (choice == '3') // Exitting
        {
            cout<<"Exiting..."<<endl;
            menuActive = false;
        }
        else if (choice == '4') // Exitting
        {
            cout<<"This is for testing: "<<endl;
            // DELETE THIS WHOLE SECTION LATER -------------------------------

            SilverClient sil1 = SilverClient(10, "John");
            SilverClient sil2 = SilverClient(2, "Sam");
            GoldClient gold1 = GoldClient(2, "Edge", 'B');
            GoldClient gold2 = GoldClient(30, "Big Ten", 'A');
            PlatinumClient plat1 = PlatinumClient(1, "little guy", 'C', 200);
            PlatinumClient plat2 = PlatinumClient(2, "sligghtly bigger", 'D', 30000);
            cout<<"\n\n";

            Client* Ptr1 = &sil1;
            Client* Ptr2 = &sil2;
            Client* Ptr3 = &gold1;
            Client* Ptr4 = &gold2;


            if( typeid(sil1) == typeid(sil2))   { cout<< "Test 1 passed\n";}
            if( typeid(sil1) != typeid(gold1))   { cout<< "Test 2 passed\n";}
            if( typeid(gold1) == typeid(gold2))   { cout<< "Test 3 passed\n";}
            if( typeid(plat1) != typeid(sil1))   { cout<< "Test 4 passed\n";}



        }
        else 
        {
            // This is reached if invalid option put in for menu
            cout<<"Error, Please Select a Valid Option. \n\n";
            cout<<"Returning to Menu..."<<endl;
        }
    }


    return 0;
}


// Code for display menu
char displayMenu()
{
    // choice is used to store the menu option selected.
    char choice;
    cout<<endl;

    // Reads menu options
    cout<<"Please select an option:\n\n";
    cout<<"1. Input Clients From File\n";
    cout<<"2. Use Console to Input Clients\n";
    cout<<"3. Exit Program \n\n";
    cout<<"4. DELETEW THIS COUT AND ACTUAL CODE LATER \n\n";
    cin>>choice;
    
    // return the choice so main knows what to run.
    return choice;
}
