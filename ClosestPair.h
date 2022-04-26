// ------------------------------------------------ ClosestPair.h -----------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to store the list of points from the text file, as well as sorted versions
// Creation Date: 04/20/2022
// Last Modified: 04/26/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: ClosestPair class stores vectors of Point classes for the algorithm
//Functionality: Each point is stored as a Point object so it stores easier		
//Assumptions: The text file given will always have the same format to it
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"


using namespace std;

class ClosestPair
{
public:
	//Constructor
	//Default constructor for ClosestPair
	//Precondition: None
	//Postcondition: Initializes points vector to store data
	ClosestPair();

	//Destructor
	//Default destructor for ClosestPair
	//Precondition: None
	//Postcondition: None, since nothing is dynamically allocated
	~ClosestPair();

	//setPoints
	//Sets Point object values based on text file
	//Precondition: File must be formatted correctly for function to work
	//Postcondition: Sets each point object correctly to be used for the algorithm
	void setPoints(ifstream& file);

	//mergeSortX
	//Sorts the Point objects by x coordinate in increasing order
	//Precondition: setPoints needs to be called before this
	//Postcondition: points will be sorted by x values
	void mergeSortX(vector<Point>&, int, int) const;

	//mergeX
	//Used in mergeSortX to merge two vectors together
	//Precondition: Should only be called in mergeSortX
	//Postcondition: Merges subvector for the iteration
	void mergeX(vector<Point>&, int, int, int) const;

	//mergeSortY
	//Sorts the Point objects by y coordinate in increasing order
	//Precondition: setPoints needs to be called before this
	//Postcondition: points will be sorted by y values
	void mergeSortY(vector<Point>&, int, int) const;

	//mergeY
	//Used in mergeSortY to merge two vectors together
	//Precondition: Should only be ccalled in mergeSortY
	//Postcondition: merges subvector for the iteration
	void mergeY(vector<Point>&, int, int, int) const;

	//performAlgorithm
	//Sets up for the recursive Algorithm that performs the ClosestPair algorithm
	//Precondition: setPoints needs to be called before this to work
	//Postcondition: Creates two vectors sorted by x and y, and sets them to be used later
	void performAlgorithm();

	//performAlgorithmRecur
	//Recursive function that performs the ClosestPair algorithm in O(n log(n) ) time
	//Precondition: Can only be called in performAlgorithm
	//Postcondition: Outputs the closest distance for each iteration of points until it reaches the overall problem
	double performAlgorithmRecur(vector<Point>&, vector<Point>&, int, int, int) const;


private:
	vector<Point> points;				//Unsorted vector of Point objects
	int size;							//Int for number of points == size of vectors
};