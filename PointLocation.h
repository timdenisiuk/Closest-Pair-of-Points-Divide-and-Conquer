#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class PointLocation
{
public:
	PointLocation();
	PointLocation(double, double);
	~PointLocation();
	void setX(double);
	double getX();
	void setY(double);
	double getY();
private:
	double xCoord;
	double yCoord;
};