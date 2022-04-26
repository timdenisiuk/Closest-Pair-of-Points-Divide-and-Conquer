#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"


using namespace std;

class ClosestPair
{
public:
	ClosestPair();
	~ClosestPair();
	void setPoints(ifstream& file);
	void mergeSortX(vector<Point>&, int, int);
	void mergeX(vector<Point>&, int, int, int);
	void mergeSortY(vector<Point>&, int, int);
	void mergeY(vector<Point>&, int, int, int);
	void performAlgorithm();
	double performAlgorithmRecur(vector<Point>&, vector<Point>&, int, int, int);


private:
	vector<Point> points;
	vector<Point> pointsXMerged;
	vector<Point> pointsYMerged;
	int size;
};