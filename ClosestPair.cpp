// ---------------------------------------------- ClosestPair.cpp -----------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to implement functions for ClosestPair
// Creation Date: 04/20/2022
// Last Modified: 04/26/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Defines all functions for ClosestPair
//Functionality: Each point is stored as a Point object so it stores easier		
//Assumptions: The text file given will always have the same format to it
// -------------------------------------------------------------------------------------------------------------------- 


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "ClosestPair.h"

using namespace std;

//Constructor
//Default constructor for ClosestPair
//Precondition: None
//Postcondition: Initializes points vector to store data
ClosestPair::ClosestPair()
{
	size = 0;
	points.resize(1);
}

//Destructor
//Default destructor for ClosestPair
//Precondition: None
//Postcondition: None, since nothing is dynamically allocated
ClosestPair::~ClosestPair() {}


//setPoints
//Sets Point object values based on text file
//Precondition: File must be formatted correctly for function to work
//Postcondition: Sets each point object correctly to be used for the algorithm
const void ClosestPair::setPoints(ifstream& file)
{
	double xInput, yInput;
	file >> size;

	points.resize(size);
	for (int i = 0; i < size; i++)
	{
		file >> xInput;
		file >> yInput;
		points[i].setX(xInput);
		points[i].setY(yInput);
	}
}

//mergeSortX
//Sorts the Point objects by x coordinate in increasing order
//Precondition: setPoints needs to be called before this
//Postcondition: points will be sorted by x values
const void ClosestPair::mergeSortX(vector<Point>& vector, int l, int r)
{
	if (l < r)
	{
		int m = (l + (r - 1)) / 2;

		mergeSortX(vector, l, m);
		mergeSortX(vector, m + 1, r);
		mergeX(vector, l, m, r);
	}
}

//mergeX
//Used in mergeSortX to merge two vectors together
//Precondition: Should only be called in mergeSortX
//Postcondition: Merges subvector for the iteration
const void ClosestPair::mergeX(vector<Point>& smallVector, int l, int m, int r)
{
	int l2 = m + 1;

	if (smallVector[m].getX() <= smallVector[l2].getX())
		return;

	while (l <= m && l2 <= r)
	{
		if (smallVector[l].getX() <= smallVector[l2].getX())
			l++;

		else
		{
			Point val = smallVector[l2];
			int index = l2;

			while (index != l)
			{
				smallVector[index] = smallVector[index - 1];
				index--;
			}

			smallVector[l] = val;
			l++, m++, l2++;
		}
	}
}

//mergeSortY
//Sorts the Point objects by y coordinate in increasing order
//Precondition: setPoints needs to be called before this
//Postcondition: points will be sorted by y values
const void ClosestPair::mergeSortY(vector<Point>& vector, int l, int r)
{
	if (l < r)
	{
		int m = (l + (r - 1)) / 2;

		mergeSortY(vector, l, m);
		mergeSortY(vector, m + 1, r);
		mergeY(vector, l, m, r);
	}
}

//mergeY
//Used in mergeSortY to merge two vectors together
//Precondition: Should only be ccalled in mergeSortY
//Postcondition: merges subvector for the iteration
const void ClosestPair::mergeY(vector<Point>& smallVector, int l, int m, int r)
{

	int l2 = m + 1;

	if (smallVector[m].getY() <= smallVector[l2].getY())
		return;

	while (l <= m && l2 <= r)
	{
		if (smallVector[l].getY() <= smallVector[l2].getY())
			l++;

		else
		{
			Point val = smallVector[l2];
			int index = l2;

			while (index != l)
			{
				smallVector[index] = smallVector[index - 1];
				index--;
			}

			smallVector[l] = val;
			l++, m++, l2++;
		}
	}
}

//performAlgorithm
//Sets up for the recursive Algorithm that performs the ClosestPair algorithm
//Precondition: setPoints needs to be called before this to work
//Postcondition: Creates two vectors sorted by x and y, and sets them to be used later
const void ClosestPair::performAlgorithm()
{
	mergeSortX(points, 0, size - 1);
	vector<Point> pointsXMerged = points;

	mergeSortY(points, 0, size - 1);
	vector<Point> pointsYMerged = points;

	performAlgorithmRecur(pointsXMerged, pointsYMerged, size, 0, size - 1);
}

//performAlgorithmRecur
//Recursive function that performs the ClosestPair algorithm in O(n log(n) ) time
//Precondition: Can only be called in performAlgorithm
//Postcondition: Outputs the closest distance for each iteration of points until it reaches the overall problem
const double ClosestPair::performAlgorithmRecur(vector<Point>& xVector, vector<Point>& yVector, int vectorSize, int left, int right)
{
	int leftSize, rightSize, partition;
	double resultX, resultY, result, delta, newResult, L, delta1, delta2;
	if (vectorSize == 2)																				//First base case for when it hits a small enough problem size
	{
		resultX = pow((xVector[left].getX() - xVector[right].getX()), 2);								//Euclidian distance formula broken down to read easier
		resultY = pow((xVector[left].getY() - xVector[right].getY()), 2);
		result = sqrt(resultX + resultY);

		cout << "D[" << left << "," << right << "]: " << fixed << setprecision(4) << result << endl;
		return result;
	}
	if (vectorSize == 3)																				//Second base case for small enough problem size
	{
		right--;																						//Brute force for three points
		resultX = pow((xVector[left].getX() - xVector[right].getX()), 2);
		resultY = pow((xVector[left].getY() - xVector[right].getY()), 2);
		result = sqrt(resultX + resultY);

		right++;
		resultX = pow((xVector[left].getX() - xVector[right].getX()), 2);
		resultY = pow((xVector[left].getY() - xVector[right].getY()), 2);
		newResult = sqrt(resultX + resultY);
		if (newResult <= result)
			result = newResult;

		left++;
		resultX = pow((xVector[left].getX() - xVector[right].getX()), 2);
		resultY = pow((xVector[left].getY() - xVector[right].getY()), 2);
		newResult = sqrt(resultX + resultY);
		if (newResult <= result)
			result = newResult;

		left--;
		cout << "D[" << left << "," << right << "]: " << fixed << setprecision(4) << result << endl;
		return result;
	}

	if (vectorSize % 2 == 0)																			//Setting up for a smaller problem
	{
		leftSize = vectorSize / 2;
		rightSize = vectorSize / 2;
		partition = (left + (right - 1)) / 2;
	}
	else
	{
		leftSize = (vectorSize / 2) + 1;														//Ensures that left half has one more than right half if odd
		rightSize = vectorSize / 2;
		partition = (left + (right - 1)) / 2 + 1;
	}

	L = xVector[partition].getX();																//Line passes through point, point belongs to left half as most right point

	delta1 = performAlgorithmRecur(xVector, yVector, leftSize, left, partition);				//Performs recursion for left half of line
	delta2 = performAlgorithmRecur(xVector, yVector, rightSize, partition + 1, right);			//Performs recursion for right half of line
	delta = min(delta1, delta2);																//Takes shortest length from each half

	unsigned int k;																				//Unsigned to prevent compiler warnings
	bool end = false;
	for (unsigned int i = 0; i < yVector.size(); i++)
	{
		if (yVector[i].getX() < (L - delta) || yVector[i].getX() > (L + delta))
			continue;

		k = i + 1;
		for (int j = 0; j < 7; j++)
		{
			if (k >= yVector.size())															//Stops if nothing left in vector
				break;

			while (yVector[k].getX() < (L - delta) || yVector[i].getX() > (L + delta))			//Finds the next neighbor within the delta strip without going over
			{
				k++;
				if (k >= yVector.size())														//Stops if nothing left in vector
				{
					end = true;
					break;																	    //Used to break while loop
				}
			}

			if (end == true)																    //Used to break second for loop
			{
				end = false;
				break;
			}

			resultX = pow((yVector[i].getX() - yVector[k].getX()), 2);
			resultY = pow((yVector[i].getY() - yVector[k].getY()), 2);
			result = sqrt(resultX + resultY);
			if (result < delta)																	//Checking if new result is better than current delta
				delta = result;

			k++;
		}
	}

	cout << "D[" << left << "," << right << "]: " << fixed << setprecision(4) << delta << endl;
	return delta;
}