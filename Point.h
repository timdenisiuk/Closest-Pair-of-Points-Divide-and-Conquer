#pragma once
class Point
{
public:
	Point();
	~Point();
	double getX();
	void setX(double);
	double getY();
	void setY(double);
private:
	double X;
	double Y;
};