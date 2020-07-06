/*
* project1.cpp
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
#include "project1.h"

const int MINSCORE = 0;
const int MAXSCORE = 100;

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
            cout<<"Please enter the file name: \n";
            string fileName;
            cin>>fileName;
            inputFile(fileName, StudentVec);
        }
        else if (choice == '2')
        {
           consoleInput(StudentVec);
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
    cout<<"3. Exit Program \n\n";
    cin>>choice;
    
    // return the choice so main knows what to run.
    return choice;
}


// Console Input
void consoleInput(vector<Student>& studentVec)
{
    bool consoleActive = true;
    char consolechoice;
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
        isError = false;
        spaceCount = 0;

        for(int i = 0; i<inputName.size(); i++)
        {
            if(inputName[i] == ' ')
            {
                spaceCount++;
            }

            if(inputName[i] == '-')
            {
                cout<<"Error, no hyphens allowed."<<endl;
                isError = true;
                break;
            }

            if(spaceCount > 3)
            {
                cout<<"Error, too many names"<<endl;
                isError = true;
                break;
            }
        }
        cout<<endl;
        } while (isError);
        cout<<endl;

        // Score Input
        cout<<"Input Student Score: (Between 0 and 100) \n";
        cin>>inputScore;
        // Data Validation
        while(inputScore < MINSCORE || inputScore > MAXSCORE)
        {
            cout<<"Error, please enter a score between 0 and 100.\n";
            cin>>inputScore;
        }
        cout<<endl;

        Student student1 = Student(inputName, inputScore);
        studentVec.push_back(student1);

        //Need to revisit
        cout<<"Would you like to add another? (y or n) \n";
        cin>>consolechoice;
        if (consolechoice == 'n')
        { 
        consoleActive = false;
        cout<<"Displaying HTML Table....\n\n";
        HtmlStudentTable table = HtmlStudentTable(studentVec);
        cout<<table<<endl;
        }
    }
}

// File Input
void inputFile(string fileName, vector<Student> &stuVec)
{
    string inputName;
    float inputScore;
    string inputline;
    string linetrash;
    ifstream studentFile;
    char comma;
    // Row counter used to identify errors in while loop
    int rowCounter = 0;

    studentFile.open(fileName.c_str());
    if (!(studentFile)) {
        cout<<"Error, No File Found."<<"\n\n";
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
            // Then character is checked if it is a hypehn (which isn't allowed)
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
            // If there was an error, then this trashes the rest of the line and 
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
    // prints html file:
    HtmlStudentTable table = HtmlStudentTable(stuVec);
    cout<<table<<endl;
}