#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "ClosestPair.h"

using namespace std;

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

void ClosestPair::mergeX(vector<Point>& smallVector, int l, int m, int r)
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

void ClosestPair::mergeSortX(vector<Point>& vector, int l, int r)
{
	if (l < r)
	{
		int m = (l + (r - 1)) / 2;

		mergeSortX(vector, l, m);
		mergeSortX(vector, m + 1, r);
		mergeX(vector, l, m, r);
	}
}

void ClosestPair::mergeY(vector<Point>& smallVector, int l, int m, int r)
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

void ClosestPair::mergeSortY(vector<Point>& vector, int l, int r)
{
	if (l < r)
	{
		int m = (l + (r - 1)) / 2;

		mergeSortY(vector, l, m);
		mergeSortY(vector, m + 1, r);
		mergeY(vector, l, m, r);
	}
}

void ClosestPair::performAlgorithm()
{
	mergeSortX(points, 0, size - 1);
	pointsXMerged = points;
	mergeSortY(points, 0, size - 1);
	pointsYMerged = points;
	performAlgorithmRecur(pointsXMerged, pointsYMerged, size, 0, size - 1);
}

double ClosestPair::performAlgorithmRecur(vector<Point>& xVector, vector<Point>& yVector, int vectorSize, int left, int right)
{
	int leftSize, rightSize, partition;
	double resultX, resultY, result, delta, newResult, L, delta1, delta2;
	if (vectorSize == 2)
	{
		resultX = pow((xVector[left].getX() - xVector[right].getX()), 2);
		resultY = pow((xVector[left].getY() - xVector[right].getY()), 2);
		result = sqrt(resultX + resultY);
		cout << "D[" << left << "," << right << "]: " << fixed << setprecision(4) << result << endl;
		return result;
	}
	if (vectorSize == 3)
	{
		right--;
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
		cout << "D[" << left << "," << right << "]: " << fixed << setprecision(4) << result << endl;
		return result;
	}

	if (vectorSize % 2 == 0)
	{
		leftSize = vectorSize / 2;
		rightSize = vectorSize / 2;
		partition = (left + (right - 1)) / 2;
	}
	else
	{
		leftSize = (vectorSize / 2) + 1;
		rightSize = vectorSize / 2;
		partition = (left + (right - 1)) / 2 + 1;
	}

	L = xVector[partition].getX();
	delta1 = performAlgorithmRecur(xVector, yVector, leftSize, left, partition);
	delta2 = performAlgorithmRecur(xVector, yVector, rightSize, partition + 1, right);
	delta = min(delta1, delta2);

	unsigned int k;
	bool end = false;
	for (unsigned int i = 0; i < yVector.size(); i++)
	{
		if (yVector[i].getX() < (L - delta) || yVector[i].getX() > (L + delta))
		{
			continue;
		}

		k = i + 1;
		for (int j = 0; j < 7; j++)
		{
			if (k >= yVector.size())
				break;

			while (yVector[k].getX() < (L - delta) || yVector[i].getX() > (L + delta))			//Finds the next neighbor within the delta strip without going over
			{
				k++;
				if (k >= yVector.size())
				{
					end = true;
					break;																	   //Used to break while loop
				}
			}
			if (end == true)																   //Used to break second for loop
			{
				end = false;
				break;
			}


			resultX = pow((yVector[i].getX() - yVector[k].getX()), 2);
			resultY = pow((yVector[i].getY() - yVector[k].getY()), 2);
			result = sqrt(resultX + resultY);
			if (result < delta)
				delta = result;

			k++;
		}
	}

	cout << "D[" << left << "," << right << "]: " << fixed << setprecision(4) << delta << endl;
	return delta;
}