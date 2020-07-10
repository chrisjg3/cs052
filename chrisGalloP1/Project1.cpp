/*
* Project1.cpp
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

// Header File
#include "Project1.h"

// Global Constant for Score Boundaries
const int MINSCORE = 0;
const int MAXSCORE = 100;

// Stand-Alone Display Menu Function for Menu Options
char displayMenu();

// Stand-Alone Function For Reading File
void inputFile(string, vector<Student>&);

// Stand-Alone Function For Console Input
void consoleInput(vector<Student>&);

// Vector of Student objects defined
vector<Student>StudentVec;

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
            // File Input Option Here:
            cout<<"Please enter the file name: \n";
            string fileName;
            cin>>fileName;
            inputFile(fileName, StudentVec);
        }
        else if (choice == '2')
        {
            // Console Input Option Here:
            consoleInput(StudentVec);
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
    cout<<"1. Input Students From File\n";
    cout<<"2. Use Console to Input Students\n";
    cout<<"3. Exit Program \n\n";
    cin>>choice;
    
    // return the choice so main knows what to run.
    return choice;
}


// Console Input
void consoleInput(vector<Student>& studentVec)
{
    // Variables for interactiving with console:
    bool consoleActive = true;
    char consolechoice;
    // while loop is the actual console menu:
    while (consoleActive) {
        // inputName and inputScore defined to get name before data verification
        string inputName;
        float inputScore;
        cout<<"\n\n";

        // Name Input
        bool isError = false;
        int spaceCount = 0;
        // cin.ignore needed to clear buffer after menu option cin
        cin.ignore();

        // Starts do-while loop for inputting name and the name data verification
        do {
            cout<<"Input Student Name:\n (Can include up to 4 names: First, Middle, Maiden, and Last)\n";
            getline(cin, inputName);

            // Name Data Verification
            // isError and spaceCount reset each time so that after error the input can be revalidated
            isError = false;
            spaceCount = 0;

            // this for loop runs through the entered string by each character
            // for data validation
            for(int i = 0; i<inputName.size(); i++)
            {
                // This counts if each character is a space to check the number of names entered
                if(inputName[i] == ' ')
                {
                    spaceCount++;
                }

                // This checks if the character is a hypthen, which is not allowed
                if(inputName[i] == '-')
                {   
                    // If hyphen detected, error dispalyed and isError set to true
                    // Then break leaves for loop since no need to check the rest of the word
                    cout<<"Error, no hyphens allowed."<<endl;
                    isError = true;
                    break;
                }

                // This is checks after each character if there have been too many spaces
                // (And therefore too many names)
                if(spaceCount > 3)
                {
                    // This is reached if too many names entered
                    // If hyphen detected, error dispalyed and isError set to true
                    // Then break leaves for loop since no need to check the rest of the word
                    cout<<"Error, too many names"<<endl;
                    isError = true;
                    break;
                }
            }
        cout<<endl;
        // This is the end of the do-while loop. This will continue until while those above if statements are triggered
        } while (isError);
        cout<<endl;

        // Score Input
        cout<<"Input Student Score: (Between 0 and 100) \n";
        cin>>inputScore;
        // Data Validation
        while(inputScore < MINSCORE || inputScore > MAXSCORE)
        {
            // This is reached only if score not between 0-100 is reached
            cout<<"Error, please enter a score between 0 and 100.\n";
            cin>>inputScore;
        }
        cout<<endl;

        // When this is reached, all data is validated.
        // It is used to create a Student instance, then pushed into the vector
        Student student1 = Student(inputName, inputScore);
        studentVec.push_back(student1);

        // Ask enter another individual
        // While loop can only be left with a break command (entering y or n)
        while(true)
        {
            // Prompting to enter another or return to menu
            cout<<"Select whether to add another individual or return to menu: \n\n";
            cout<<"1. Enter another person\n";
            cout<<"2. Return to menu\n";
            cin>>consolechoice;
            // I listed 'return to menu' first as it has the more important code
            if (consolechoice == '2')
            { 
            consoleActive = false;
            cout<<"Displaying HTML Table....\n\n";
            // Html Table built (When object created, file is created)
            HtmlStudentTable table = HtmlStudentTable(studentVec);
            // This cout stream prints the table to console
            cout<<table<<endl;
            // this break exists the loop, then (now that console is false) the program will
            // go to outer loop and exit to menu
            break;
            }
            // This is for adding another student
            else if(consolechoice == '1')
            {
                // the console is already active, so just need to break if adding another
                break;
            }
            // Else for if they select something other than 1 or 2
            else { cout<< "\n Enter a valid option \n";}
        }
    }
}

// File Input
void inputFile(string fileName, vector<Student> &stuVec)
{
    // Variables for Reading Data:
    string inputName;
    float inputScore;
    string inputline;
    string linetrash;
    char comma;
    // Variables for input and output streams:
    ifstream studentFile;
    ofstream outputFile;
    // Row counter used to identify rows with errors in while loop
    int rowCounter = 0;

    // Attempt to open file here:
    studentFile.open(fileName.c_str());
    if (!(studentFile)) {
        // Error displayed and returned to menu if no file found
        cout<<"\nError, No File Found."<<"\n\n";
        return;
    }
    
    // This getline removes the first row, which is the column names.
    getline(studentFile,linetrash);
    cout<<endl;

    // Looping through the file to read the contents
    // This will read in the first part before the comma
    // AKA this is the section that deals with the NAME
    while (getline(studentFile,inputline, ',')) {
        // Keeping Track of Row for Error Messages:
        rowCounter++;
        // Keeps track of spaces for Name Data Verification
        int spaceCount = 0;
        bool isError = false;

        // Name Verification Section
        inputName = inputline;
        // Goes throw entire Name string and counts spaces (for number of names)
        // And checks for hypthens
        for(int i = 0; i<inputName.size(); i++)
        {
            // Each character is read in and is checked if space to count spaces:
            if(inputName[i] == ' ')
            {
                spaceCount++;
            }
            // Then character is checked if it is a hyphen (which isn't allowed)
            if(inputName[i] == '-')
            {
                // If hyphen is found, code will display error the mark isError true
                // And exit the for loop, as the name is not valid so will stop being read
                cout<<"Error on line "<<rowCounter<<", no hyphens allowed."<<endl;
                isError = true;
                break;
            }

            // This checks after each character if the number of cumulative spaces 
            // is now greater then 3, which means more than 4 names were entered.
            if(spaceCount > 3)
            {
                // If more than allowed names (signified by too many spaces) is found
                // code displays error, marks isError true, then exits the for loop. 
                cout<<"Error on line "<<rowCounter<<", too many names"<<endl;
                isError = true;
                break;
            }
        }
        // This is to check if an Error was found, aka did it run fully or exit with one
        // of those if statements, signifying an invalid name.
        if(isError)
        {
            // If there was an error, then this trashes the rest of the line (flushes buffer) and 
            // restarts while loop:
            getline(studentFile, inputline);
            continue;
        }

        // This now reads to the next comma
        // AKA this section now reads the SCORE
        studentFile>> inputScore;

        // Score Verfication Section
        if(inputScore < MINSCORE || inputScore > MAXSCORE)
        {   // This is only executed on an error
            cout<<"Error with Score on line "<<rowCounter<<endl;
            cout<<"Moving to next row"<<endl;
            
            // Trash rest of the line and then use continue to restart
            getline(studentFile, inputline);
            continue;
        }

        // This line gets rid of the comma and \n character after score
        getline(studentFile, inputline);


        // This is only reached if everything was verified, so 
        // then the two variables are used to create a Student and add them 
        // to the vecture.
        stuVec.push_back(Student(inputName, inputScore));
    }
    // Reaches the end of input from file
    cout<<endl;
    cout<<"File End. Closing file and printing out HTML table...\n\n";
    // Closes file:
    studentFile.close();
    
    // Html Table built (When object created, file is created)
    HtmlStudentTable table = HtmlStudentTable(stuVec);
    // Prints html table to console:
    cout<<table<<endl;
}