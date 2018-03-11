#pragma once
#include "stdafx.h"

class Point
{
public:
	double x_;
	double y_;
public:
	Point();
	Point(double xx, double yy);
	Point(const Point &a);
	~Point();
public:
	//set
	void X(double xx);
	void Y(double yy);
	void SetPoint(double xx, double yy);
	void SetPoint(Point& a);
	void MoveX(double x);
	void MoveY(double y);
public:
	//set
	double X();
	double Y();
	Point& GetPoint();

};