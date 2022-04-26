// ------------------------------------------------ Point.cpp ---------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to define functions in Point class
// Creation Date: 04/20/2022
// Last Modified: 04/26/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Defines all functions for Point class
//Functionality: stores double data type as per specifications		
//Assumptions:
// -------------------------------------------------------------------------------------------------------------------- 
#include "Point.h"

//Constructor
//Default constructor for Point class
//Precondition: None
//Postcondition: Empty object created with x and y initialized to 0
Point::Point()
{
	X = 0;
	Y = 0;
}

//Destructor
//Default destructor for Point class
//Precondition: None
//Postcondition: None, since nothing is dynamically allocated
Point::~Point()
{

}

//getX
//Returns value of object's X data
//Precondition: None
//Postcondition: Returns a double value for the X coordinate
const double Point::getX()
{
	return X;
}

//setX
//Sets the X value in the object
//Precondition: None
//Postcondition: Sets the X value within the object
const void Point::setX(double xValue)
{
	X = xValue;
}

//getY
//Returns value of object's Y data
//Precondition: None
//Postcondition: Returns a double value for the Y coordinate
const double Point::getY()
{
	return Y;
}

//setY
//Sets the Y value in the object
//Precondition: None
//Postcondition: Sets the Y value within the object
const void Point::setY(double yValue)
{
	Y = yValue;
}