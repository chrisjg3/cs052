/*
* ClientList.cpp
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

#include "ClientList.h"


// ClientList Destructor to free dynamically allocated memory
ClientList::~ClientList()
{
    // This function frees the dynamically allocated memory after the vector is done being used
    for(int i = 0; i<this->size(); i++)
    {
        // Creates dynamic pointer that is assigned each client pointer, then freed
        Client* tempPtr = this->at(i);
        delete tempPtr;     
    }
}


ostream &operator<<(ostream &out, ClientList &cl)
{
    // First the stream operator must sort the list
    cl.sort();

    // Opens a file to write to
    ofstream outputFile;
    outputFile.open("output.txt");

    // First line of html table
    outputFile<<"table border = '1'> \n";
    outputFile<<"\t <tr> <th> Client </th> <th> Tenure </th> <th> Tier </th> <th> Platinum Points </th> </tr> \n";

    // Create a loop to add each Client
    for(unsigned short i = 0; i<cl.size(); i++)
    {
        // We use the htmlToStream function, an ofstream and be passed into a ostream function
        // So this is a ofstream passed to htmlToStream expecting an ostream, but the libraries can handle this
        cl.at(i)->htmlToStream(outputFile);
        // Once Client Object done printing, line is closed and new row is ready:
        outputFile<< " </td></tr> \n";
    }

    // Ending table
    outputFile<<"</table>";
    // File Closed
    outputFile.close();

    // Print to Console Starts Here -----------
    // First line of html table
    out<<"table border = '1'> \n";
    out<<"\t <tr> <th> Client </th> <th> Tenure </th> <th> Tier </th> <th> Platinum Points </th> </tr> \n";

    // Enter loop to add Students (cl is the CientList, and vl is the vector inside it)
    for(unsigned short i = 0; i<cl.size(); i++)
    {
        cl[i]->htmlToStream(out);
        // Once Client Object done printing, line is closed and new row is ready:
        out<< " </td></tr> \n";
    }

    // Ending table
    out<<"</table>";
    return out;
}



void ClientList::inputFile(string inputFile)
{
    // Variables for Reading Data:
    string inputName;
    short inputTenure;
    string inputTier;
    char tierVerified;
    float inputPoints;
    string linetrash;

    // Variables for input and output streams:
    ifstream ClientFile;
    ofstream outputFile;
    // Row counter used to identify rows with errors in while loop
    int rowCounter = 0;

    // Attempt to open file here:
    ClientFile.open(inputFile.c_str());
    if (!(ClientFile)) 
    {
        // Error displayed and returned to menu if no file found
        cout<<"\nError, No File Found."<<"\n\n";
        return;
    }
    
    // This getline removes the first row, which is the column names.
    getline(ClientFile,linetrash);
    cout<<endl;

    // Looping through the file to read the contents
    // This will read in the first part before the comma
    // AKA this is the section that deals with the NAME
    while (getline(ClientFile,inputName, ','))
    {
        rowCounter++;
        int spaceCount = 0;
        bool isError = false;

        //Name Verification
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
                cout<<"Error on line "<<rowCounter<<", no hyphens allowed.\n"<<endl;
                isError = true;
                break;
            }

            // This checks after each character if the number of cumulative spaces 
            // is now greater then 3, which means more than 4 names were entered.
            if(spaceCount > 3)
            {
                // If more than allowed names (signified by too many spaces) is found
                // code displays error, marks isError true, then exits the for loop. 
                cout<<"Error on line "<<rowCounter<<", too many names\n"<<endl;
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
            getline(ClientFile, linetrash);
            continue;
        }


        // Tenure Read-in and Verification
        ClientFile>>inputTenure;

        if(inputTenure < 0 || inputTenure > 100)
        {
            // Reaches here if the tenure data entered is not valid.
            cout<<"Error on line "<<rowCounter<<", outside of range. Moving to next line...\n";
            // Trashes the rest of the line:
            getline(ClientFile, linetrash);
            // Returns to the start of the loop
            continue;
        }

        // At this point, next sections are optional, so the program must check next two 
        // attributes exist, then verify, then add.

        // First Trash the comma that is next
        ClientFile.get();

        // Next we have to check if the next character is a space, so we can move over if it is, before
        // checking if there is a comma or another input.
        if(ClientFile.peek() == ' ')
        {
            ClientFile.get();
        }

        // Now peek to see if next column has a value, or if this Client has no more information.
        // So this if/else checks if the next character is a comma, if not then read in the input
        // otherwise, this row has no more info and so the else clears the line 
        if(ClientFile.peek() != ',' &&  ClientFile.peek() != ' ')
        {
            // This gets the next part up to the comma
            getline(ClientFile,inputTier, ',');
            tierVerified = inputTier.at(0);

            // First, cast it to lower case if it isn't
            if (tierVerified >= 'A' || tierVerified <= 'Z' )
            {
                tierVerified = tolower(tierVerified);
            }

            // Verify that it is valid
            if (tierVerified < 'a' || tierVerified > 'z' )
            {
                // If it isn't in the valid range then trash the line and restart again
                getline(ClientFile, linetrash);
                cout<<"\nError, Tier on row "<<rowCounter<<"is not an acceaptable character.  Moving to next row...\n";
                continue;
            }
            // NOTE: Remember, once it is verified we don't add it to the ClientList yet,
            // we only add them once we reach the input it doesn't have or it is add the end of the list
            // So if reached here, the Tier was valid, but we must move to points to see if it is Gold or Platinum
        }
        else 
        {
            // This is reached if tier had no input and so this input was a SilverClient.
            // First, trash the rest of the line (since it is only commas)
            getline(ClientFile, linetrash);

            // Now push the rest of the information and create a Client Pointer, pointing 
            // to a SilverClient Obj.  Then push that pointer into the vector:
            Client* clientptr =  new SilverClient(inputTenure, inputName);
            this->push_back(clientptr); // Adding to Vector

            // Now that it is added and line is trashed, we must restart from the beginning
            continue;
        }

        // Next we have to check if the next character is a space, so we can move over if it is, before
        // checking if there is a comma or another input.
        if(ClientFile.peek() == ' ')
        {
            ClientFile.get();
        }

        // Next we check if there is the last input, PlatinumPoints, or if this row has no more info:
        if(ClientFile.peek() != ',' && ClientFile.peek() != ' ')
        {
            // If the code is here, then the the next column is not blank
            // We read this in rather then use getline, because it is a number and so this makes it simplier.

            ClientFile>>inputPoints;

            if(inputPoints < 0 || inputPoints > 100000)
            {
                // Reach this line if Points in that row is not valid
                cout<<"Error on line "<<rowCounter<<", moving to next row...\n";
                // Trashes the rest of the line
                getline(ClientFile, linetrash);
                // Returns to start of the loop
                continue;
            }

        }
        else
        {
            // This block is reached if the next column was empty, therefore the client was a Gold Client.
            // So now we create a Gold Client and push the pointer to the Client List.

            Client* clientptr = new GoldClient(inputTenure, inputName, tierVerified);
            // Once new pointer to dynamically allocated memory created, add it to the ClientList:
            this->push_back(clientptr);
            getline(ClientFile, linetrash);
            continue;

        }
        // If code reaches here, then it has to be a platinum client as all others would have
        // fallen into one of those else blocks and been added to the ClientList already.

        Client* clientptr = new PlatinumClient(inputTenure, inputName, tierVerified, inputPoints);
        // Once new pointer to dynamically allocated memory created, add it to the ClientList:
        // --- 
        // PlatinumClient tom = PlatinumClient(1, "test", 'a', 800);
        // Client* testptr = &tom;
        this->push_back(clientptr);

        // Once loaded in, need to trash the last comma and restart for the next line
        getline(ClientFile, linetrash);
    }

    // Close File
    ClientFile.close();

    // Print HTML Table to Console and to output.txt
    cout<<"\n\n";
    cout<<*this;
}



void ClientList::consoleInput()
{
    // Controls While loop is at end it can be set to false to exit
    bool consoleActive = true;
    // Holds the console choices for different prompts.
    char consoleChoice;
    // To simplify things, I use bools to determine which client is being entered
    // This allows me to use one single block to input clients that exits early
    // depending on which client type is entered.
    bool goldBool;
    bool plantinumBool;
    string lineTrash;
    getline(cin, lineTrash); // clearing from issues from any previous input

    // Starting the console loop
    while(consoleActive)
    {
        cout<<"\nPlease Select Type of Client To Enter\n";
        cout<<"1. SilverClient\n";
        cout<<"2. GoldClient\n";
        cout<<"3. PlatinumClient\n";

        cin>>consoleChoice;
        // Determines which client type this will
        if(consoleChoice == '1') 
        { 
        // Reset the client bools to default
        goldBool = false;
        plantinumBool = false; 
        }
        else if (consoleChoice == '2') { goldBool = true; plantinumBool = false; } // Makes sure to set plantinum to false
        else if (consoleChoice == '3') { plantinumBool = true; goldBool = false;  } // Makes sure to set gold to false
        else 
        { 
            cout<<"Error, invalid";
            continue;  
        }

        // Here are the local variables used for console verification and creating the different Client objects.
        string inputName;
        int spaceCount;
        bool isError;
        short tenureInput;
        char tierInput;
        float pointsInput;
        getline(cin, lineTrash); // clearing to avoid any issues w/ previous input


        // The do-while loop is used to take the name input and make sure (through a for loop) it is valid
        do 
        {
            isError = false;
            // Name Input
            cout<<"\n\nInput Name of Client:\n";
            getline(cin, inputName);
            spaceCount = 0; // Resetting for each new inputted name

            // Name Verification
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
        } while(isError);
        cout<<"\n";
        // If this is reached, name was verified

        // Next the program asks for and verfifies Tenure
        cout<<"Please enter the tenure of the client: \n (Between 0 and 100) \n";
        cin>>tenureInput;

        while(tenureInput < 0 || tenureInput > 100)
        {
            cout<<"Error, please enter a valid input.\n";
            cin>>tenureInput;
        }
        
        // If code reached here then both name and tenure are valid.
        // Now if the client is silver it needs to exit, so we will have
        // a conditional to push the ClientList if it is silver.

        if(!goldBool && !plantinumBool)
        {
            // Create the client pointer and push it to the ClientList
            Client* newcl =  new SilverClient(tenureInput, inputName);
            this->push_back(newcl);

            // Then we have to ask if the user wants to add another before restarting
            cout<<"\n Would you like to...?";
            cout<<"\n1. Add Another Client?";
            cout<<"\n2. Return to Menu?\n";
            cin>>consoleChoice;
            if (consoleChoice == '1') { continue; } // Sends to top of loop, console still active so runs again
            else if (consoleChoice == '2') { consoleActive = false; continue;} // sends to loop, but is inactive so leaves loop
            else {
                cout<<"Invalid Choice, sending back to menu! \n "; 
                consoleActive = false; 
                continue; // sends to loop, but is inactive so leaves loop
                }
        }

        // So if it reaches here, then the client is either a Gold or PLantinum Client

        // Tier input entry and validation
        cout<<"Please enter the tier of the client: \n (Please Enter Lowercase) \n";
        cin>>tierInput;

        // Re-asks if a valid character was not entered
        while(tierInput < 'a' || tierInput > 'z')
        {
            cout<<"Error, please enter a valid input.\n";
            cout<<"(Please Enter Lowercase)\n";
            cin>>tierInput;
        }

        // This is reached once teir is validated
        // Next, we check if this is a gold client
        // And if it is we push to ClientList and restart the loop again
        if(goldBool)
        {
            // Create the client pointer and push it to the ClientList
            Client* newcl =  new GoldClient(tenureInput, inputName, tierInput);
            this->push_back(newcl);

            // Then we have to ask if the user wants to add another before restarting
            cout<<"\n Would you like to...?";
            cout<<"\n1. Add Another Client?";
            cout<<"\n2. Return to Menu?\n";
            cin>>consoleChoice;
            if (consoleChoice == '1') { continue; } // Sends to top of loop, console still active so runs again
            else if (consoleChoice == '2') { consoleActive = false; continue;} // sends to loop, but is inactive so leaves loop
            else {
                cout<<"Invalid Choice, sending back to menu! \n "; 
                consoleActive = false; 
                continue; // sends to loop, but is inactive so leaves loop
                }
        }
        
        // If the code reaches here, then the client must be platinum, so
        // We just verify the data and then push it to the list

        // Platinum Points entry and validation
        cout<<"\nEnter Platinum Points: (Between 0 and 100,000) \n";
        cin>>pointsInput;

        while(pointsInput < 0 || pointsInput > 100000)
        {
            cout<<"Error, enter valid number (Between 0 and 100,000) \n";
            cin>>pointsInput;
        }
        // Push this new client to the list
        Client* newcl =  new PlatinumClient(tenureInput, inputName, tierInput, pointsInput);
        this->push_back(newcl);


        // Ask if they want to add another client
        cout<<"\n Would you like to...?";
            cout<<"\n1. Add Another Client?";
            cout<<"\n2. Return to Menu?\n";
            cin.clear(); // Clears previous '/n' from choices
            cin>>consoleChoice;
            if (consoleChoice == '1') { continue; } // Sends to top of loop, console still active so runs again
            else if (consoleChoice == '2') { consoleActive = false; continue;} // sends to loop, but is inactive so leaves loop
            else {
                cout<<"Invalid Choice, sending back to menu! \n "; 
                consoleActive = false; 
                continue; // sends to loop, but is inactive so leaves loop
                }

    }
    // Print the HTML Table to console and to output.txt
    cout<<*this;
}