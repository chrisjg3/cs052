#include "project1.h"

int main()
{
    //defining variables
    bool menuActive = true; // For Continueing Menu Loop until user exits
    char choice;  // This is for menu option selection.

    // Starting Menu Loop
    while (menuActive)
    {
        // First run the menu options
        choice = displayMenu();

        // Determine what to run based on choice
        if (choice == '1')
        {
            // Run File Input Function
        }
        else if (choice == '2')
        {
            // Run Console Function
        }
        else if (choice == '3')
        {
            cout<<"Exiting..."<<endl;
            menuActive = false;
        }
        else 
        {
            cout<<"Error, Please Select a Valid Option. \n\n";
            cout<<"Returning to Menu..."<<endl;
        }
    }

    return 0;
}


char displayMenu()
{
    // choice is used to store the menu option selected.
    char choice;
    cout<<endl;

    // Reads menu options
    cout<<"Please select an option:\n\n";
    cout<<"1. Input Students From File\n";
    cout<<"2. Use Console to Input Students\n";
    cout<<"3. Exit Program \n \n";
    cin>>choice;
    
    // return the choice so main knows what to run.
    return choice;
}