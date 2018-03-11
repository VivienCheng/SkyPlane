#pragma once
#include "FlyBehavior.h"
#include "Point.h"

class StrangeFly :public FlyBehavior
{
protected:
	double xp_;
	double yp_;
	int op_; //1��������� 2�����ҷ��� 
	BOOL first;
	BOOL second;
	BOOL third;
	BOOL forth;
	BOOL fifth;
	double height_;
public:
	StrangeFly(Point& a, double xp, double yp, int op,double h);
	~StrangeFly();
	void Fly();

};
