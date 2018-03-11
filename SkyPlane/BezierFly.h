#pragma once
#include "FlyBehavior.h"
#include "Point.h"
#include <vector>

class BezierFly :public FlyBehavior
{
protected:
	Point *b_, *c_;
	//顶点和控制点数组
	std::vector<Point> ctrlPt_;
	//曲线上各点坐标数组
	std::vector<Point> curvePt_;
	int pos;
	BOOL back;
public:
	BezierFly(Point& a, Point& b, Point& c);
	~BezierFly();

	void SetCtrlPoint(Point& p,Point& q,Point& m);
	void CreateCurve();

	//主要算法，计算曲线上各个点坐标
	void CalCurvePoint(double t, Point& p);
	void Fly();
	
};

