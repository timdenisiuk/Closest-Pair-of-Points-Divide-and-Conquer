#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "PointLocation.h"

using namespace std;

class ClosestPair
{
public:
	ClosestPair();
	~ClosestPair();
	void setPoints(ifstream& file);

private:
	vector<PointLocation> points;
	int size;
};