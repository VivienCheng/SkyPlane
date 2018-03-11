#pragma once
#include "Point.h"
#include <vector>

//使用策略模式
class FlyBehavior
{
protected:
	Point *a_;
public:
	FlyBehavior(Point& a);
	~FlyBehavior();
	virtual void Fly() = 0;
};