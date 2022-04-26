// ------------------------------------------------ Point.h -----------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to store information on point's x and y coordiate
// Creation Date: 04/20/2022
// Last Modified: 04/26/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Point class stores all data for each point and functions to access them
//Functionality: stores double data type as per specifications		
//Assumptions:
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
class Point
{
public:
	//Constructor
	//Default constructor for Point class
	//Precondition: None
	//Postcondition: Empty object created with x and y initialized to 0
	Point();

	//Destructor
	//Default destructor for Point class
	//Precondition: None
	//Postcondition: None, since nothing is dynamically allocated
	~Point();

	//getX
	//Returns value of object's X data
	//Precondition: None
	//Postcondition: Returns a double value for the X coordinate
	const double getX();

	//setX
	//Sets the X value in the object
	//Precondition: None
	//Postcondition: Sets the X value within the object
	const void setX(double);

	//getY
	//Returns value of object's Y data
	//Precondition: None
	//Postcondition: Returns a double value for the Y coordinate
	const double getY();

	//setY
	//Sets the Y value in the object
	//Precondition: None
	//Postcondition: Sets the Y value within the object
	const void setY(double);

private:
	double X;	//double value for X coordinate
	double Y;	//double value for Y coordinate
};