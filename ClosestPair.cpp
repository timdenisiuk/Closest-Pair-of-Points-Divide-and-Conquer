#include <iostream>
#include <fstream>
#include <vector>
#include "ClosestPair.h"

ClosestPair::ClosestPair()
{
	size = 0;
	points.resize(1);
}

ClosestPair::~ClosestPair()
{

}

void ClosestPair::setPoints(ifstream& file)
{
	double xInput;
	double yInput;
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