#pragma once
#include "lib.h"
#include <iostream>
using namespace std;
class Point
{
public:
	static int licznik;
	int I, J;
	struct color mycolor;
	Point(int j, int i, unsigned char red, unsigned char green, unsigned char blue);
	Point(const Point& p);
	~Point();
	friend ostream& operator <<(ostream& s, Point& p);
	bool operator ==(const Point& p);
};

