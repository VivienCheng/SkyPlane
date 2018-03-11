#pragma once
#include "FlyBehavior.h"
#include "Point.h"

class FlyNoWay: public FlyBehavior
{
public:
	FlyNoWay(Point& p);
	~FlyNoWay();
	void Fly();

};