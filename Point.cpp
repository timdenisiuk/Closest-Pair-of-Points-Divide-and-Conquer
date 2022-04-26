#include "Point.h"

Point::Point()
{
	X = 0;
	Y = 0;
}

Point::~Point()
{

}


double Point::getX()
{
	return X;
}

void Point::setX(double xValue)
{
	X = xValue;
}

double Point::getY()
{
	return Y;
}

void Point::setY(double yValue)
{
	Y = yValue;
}