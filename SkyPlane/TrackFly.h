#pragma once
#include "FlyBehavior.h"
#include "Point.h"
#include "Resource.h"


class TrackFly :public FlyBehavior
{
protected:
	Point *tar_;
	double xp_, yp_;
	int num;
public:
	TrackFly(Point& p, Point& t,double a,double b);
	~TrackFly();
	void Fly();
};