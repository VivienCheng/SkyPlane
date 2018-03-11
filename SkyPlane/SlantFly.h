#pragma once
#include "FlyBehavior.h"
#include "Point.h"

class SlantFly :public FlyBehavior
{
protected:
	double xp_;
	double yp_;
public:
	SlantFly(Point& a,double xp,double yp);
	~SlantFly();
	void Fly();

};
