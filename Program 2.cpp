// ------------------------------------------------ Program2.cpp ------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Driver for the program
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Driver for the program
//Functionality: Creates the ClosestPair class and uses it to perform the algorithm		
//Assumptions:
// -------------------------------------------------------------------------------------------------------------------- 

#include <iostream>
#include <fstream>
#include "ClosestPair.h"
using namespace std;

//main
//Main driver for the program
//precondition: None
//Postcondition: Performs the ClosestPair algorithm
int main()
{
    ifstream infile("program2data.txt");
    ClosestPair CP;
    CP.setPoints(infile);
    CP.performAlgorithm();
}