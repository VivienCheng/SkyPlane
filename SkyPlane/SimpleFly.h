#pragma once
#include "FlyBehavior.h"
#include "Point.h"

class SimpleFly :public FlyBehavior
{
protected:
	double sp_;
public:
	SimpleFly(Point& a,double sp);
	~SimpleFly();
	void Fly();
};


//该类是在Y轴上直上或者直下
//适用于某些初级的敌机、炸弹和玩家的主炮攻击