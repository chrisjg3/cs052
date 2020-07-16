#include "Project2.h"
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
        if (choice == '1')
        {
            cout<<"Please enter the file name: \n";
            string fileName;
            cin>>fileName;
            cl.inputFile(fileName);
        }
        else if (choice == '2')
        {
            // Whatever Option 2 is
        }
        else if (choice == '3')
        {
            // Exit Option Here:
            cout<<"Exiting..."<<endl;
            menuActive = false;
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
    cin>>choice;
    
    // return the choice so main knows what to run.
    return choice;
}
