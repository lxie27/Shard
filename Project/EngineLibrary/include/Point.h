#ifndef Point_h
#define Point_h

class Point
{
public:
	double x, y;

	Point();
	Point(double x, double y);

	void setX(int x);
	void setY(int y);

	void print() const;

};


#endif 