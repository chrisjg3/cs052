#include "ClientList.h"



void ClientList::inputFile(string inputFile)
{
    // Variables for Reading Data:
    string inputName;
    short inputTenure;
    string inputTier;
    char tierVerified;
    short inputPoints;
    string linetrash;

    // Variables for input and output streams:
    ifstream ClientFile;
    ofstream outputFile;
    // Row counter used to identify rows with errors in while loop
    int rowCounter = 0;

    // Attempt to open file here:
    ClientFile.open(inputFile.c_str());
    if (!(ClientFile)) {
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
            getline(ClientFile, linetrash);
            continue;
        }


        // Tenure Verification
        // NOTE: STILL NEED VERIFICATION BUILT --------------------------------------------

        ClientFile>>inputTenure;

        // For now, assuming always valid  --------------------------------------------



        // Begins Optional Section, so must check next two attributes exist, then verify, then add

        // First Trash the comma that is next
        ClientFile.get();

        // Now peek to see if next column has a value, or if this Client has no more information.
        // So this if/else checks if the next character is a space or comma, if not then read in the input
        // otherwise, this row has no more info and so the else clears the line 
        if(ClientFile.peek() != ' ' && ClientFile.peek() != ',')
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
                continue;
            }
            // NOTE: Remember, once it is verified we don't add it to the ClientList yet,
            // we only add them once we reach the input it doesn't have or it is add the end of the list
            // At that point, we then build it because we know there is nothing else to add.
        }
        else
        {
            // This is reached if the line is now over, indicated by no more information.
            // First, trash the rest of the line
            getline(ClientFile, linetrash);

            // Now push the rest of the information and create a Client Pointer, pointing 
            // to a SilverClient Obj.  Then push that pointer into the vector:
            Client* clientptr =  new SilverClient(inputTenure, inputName);
            this->push_back(clientptr); // Adding to Vector

            // Now that it is added and line is trashed, we must restart from the beginning
            continue;
        }

        // Next we check if there is the last input, PlatinumPoints, or if this row has no more info:
        if(ClientFile.peek() != ' ' && ClientFile.peek() != ',')
        {
            // If the code is here, then the the next column is not blank
            // We read this in rather then use getline, because it is a number and so this makes it simplier.

            ClientFile>>inputPoints;

            // NEED TO ADD DATA VALIDATION HERE -----------------------------------------

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
        this->push_back(clientptr);

        // Once loaded in, need to trash the last comma and restart for the next line
        getline(ClientFile, linetrash);
    }

    // Close File
    ClientFile.close();

    // Print HTML Table
    cout<<*this;

    // ostream here ------------------------------------------------
}




ostream &operator<<(ostream &out, ClientList &cl)
{
    // First line of html table
    out<<"table border = '1'> \n";
    out<<"\t <tr> <th> Client </th> <th> Tenure </th> <th> Tier </th> <th> Platinum Points </th> </tr> \n";

    // Enter loop to add Students
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


void ClientList::consoleInput()
{

    // BEGIN HERE --------------------
}