#include <iostream>
#include <fstream>
#include "PointLocation.h"

using namespace std;

PointLocation::PointLocation()
{
	xCoord = 0;
	yCoord = 0;
}

PointLocation::~PointLocation()
{

}

PointLocation::PointLocation(double x, double y)
{
	xCoord = x;
	yCoord = y;
}

void PointLocation::setX(double x)
{
	xCoord = x;
}

double PointLocation::getX()
{
	return xCoord;
}

void PointLocation::setY(double y)
{
	yCoord = y;
}

double PointLocation::getY()
{
	return yCoord;
}