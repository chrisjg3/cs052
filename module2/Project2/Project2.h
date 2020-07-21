/*
* Project2.h
*
* COSC 052 2020
* Project 2
*
* Due on: July 21st
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

#ifndef PROJECT2_H
#define PROJECT2_H

#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <algorithm>

// HeaderFiles to Include
#include "Client.h"
#include "ClientList.h"
#include "SilverClient.h"
#include "GoldClient.h"
#include "PlatinumClient.h"



/*
---------- TO DO LIST: ----------


---------- OH Qs:
8. Data vlidation might be wrong, what if there is a space before next input?
10. Only need to build a destructor in ClientList?  I think so
12. Client viretual destrcutor issue, either write in all of them or do something idk, 14. Do we need constructors and destructors for each class?  It can all inherit Clients and be fine I believe
17. Should it display first then promot for new Client?  PDF seems to imply that


----




4. Clean up that verification for tier, don't need to be that messy


13. Go through code and clean up.  Need cin.clears?  Its the many inputs that were the problem...so clears not needed?






---------- LAST THINGS TO DO:
19. Test on course server
7. Review PDF and Rubrick and Double Check everything works as intended
Delete this list



---------- If You Have Time:
11. Make the bools for console silver and gold to make it clearer



*/

#endif