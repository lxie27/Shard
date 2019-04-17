/*! \file
Point.cpp: a Point coordinate.
*/
#include "Point.h"
/*!
\brief The constructor.
\param x The x coordinate.
\param y The y coordinate.
\returns The Point instance.
*/
Point::Point(double x, double y) : x(x), y(y) {};

/*!
\brief Sets the X of the Point.
\param x The x to set to.
*/
void Point::setX(int x) {
	x = x;
}

/*!
\brief Sets the Y of the Point.
\param y The y to set to.
*/
void Point::setY(int y) {
	y = y;
}