#pragma once
#include "FlyBehavior.h"
#include "Point.h"

class AimFly :public FlyBehavior
{
protected:
	double xp_;
	double yp_;
	Point *aim_;
public:
	AimFly(Point& a,Point* b, double xp,double yp_);
	~AimFly();
	void Fly();
};

