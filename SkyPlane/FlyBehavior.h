#pragma once
#include "Point.h"
#include <vector>

//ʹ�ò���ģʽ
class FlyBehavior
{
protected:
	Point *a_;
public:
	FlyBehavior(Point& a);
	~FlyBehavior();
	virtual void Fly() = 0;
};