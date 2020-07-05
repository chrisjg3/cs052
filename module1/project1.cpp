/*
* <FileName>.<file extension>
*
* COSC 052 <term year>
* Project <>
*
* Due on: <Due Date>
* Author: <your name>
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
            // Input function
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
    cout<<"3. Exit Program \n \n";
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
        int inputScore;
        cout<<"\n\n";

        // Name Input
        cout<<"Input Student Name:\n";
        cin>>inputName;
        cout<<"\n";
        // Name Data Verification
        cout<<endl;

        // Score Input
        cout<<"Input Student Score: \n";
        cin>>inputScore;
        // Score Verification
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
void inputFile(string fileName, vector<Student> &)
{
    string inputName;
    int inputScore;
    string linetrash;
    ifstream riskFile;
    int rowCounter = 1;

    riskFile.open(fileName.c_str());
    if (!(riskFile)) {
        cout<<"Error, No File Found."<<"\n\n";
        return;
    }
    
    // This getline removes the first row, which is the column names.
    getline(riskFile,linetrash);
    cout<<endl;

    // Looping through the file to read the contents
    while (riskFile >> inputName) {
        
    }
}