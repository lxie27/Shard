#pragma once
#ifndef POINT_H
#define POINT_H

class Point
{
public:
	double x, y;

	~Point() {};
	Point(double x, double y);

	void setX(int x);
	void setY(int y);

};


#endif 