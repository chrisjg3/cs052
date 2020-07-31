/*
* Project3.h
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
#include <typeinfo>




#endif

// ***************** TO DO *************
/*

0.5 Override > operators, check how to do that properly and then JUST use > in sort() I believe


3. Make Doxygen graph thing AND include it in your zip submission
4. Make clientlist derived from Svector 
5. Chnage calls so clientlist is editted directly not have a vector inside it changed
6. call sort before console out and saving output.txt
7. Remove pub;ic from class deriving statements, should it be protected instead?
8. Maybe this is for OH or presentation, but is ClientList headder styatement correct w/ SVector class?
9. Rewrite comments so that Relational Operators say "platintum to Platinum" or "Gold to Gold" correctly
10. Delete both parts of testing code later, aka the cout and the actual else if statement that makes things happen
11. Include ncomments explaining getPoints and getTier if stay included in Clinet and SilverClient
12. implement insertion ratgher than current method for sort()
13. Go through and delete the getype()s and (and getTier and getPoints fopr Client/silver) and implemeent the typeid() for the objects
14.  Shoudl the sort be doing the opposite order? descending right so largest should come first?


- Review code and rubric/pdf to change any names to Project3 etc 




********************* Testing ***********************

1. Double check honor code statemnts fdr basic errors



******************* QUESTIONS FOR OH **************

1. So now vector is not an attribute but a base class?

1.5 Chekc if not friend function is alright for Client relational operastor override

2. Had to add get tier and gfet poiunts to base class to get it to work w/ operator> is there a WAY TO FIX THIS?

2. sort should just return nothing and take nothing, yes?

3. Make sure "sorting algorythm in-place" means generate no new variables, should just sort existing vector components 

OH -----

typeid
Capital As when I convert all to lower case

*/
