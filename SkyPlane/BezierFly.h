#pragma once
#include "FlyBehavior.h"
#include "Point.h"
#include <vector>

class BezierFly :public FlyBehavior
{
protected:
	Point *b_, *c_;
	//����Ϳ��Ƶ�����
	std::vector<Point> ctrlPt_;
	//�����ϸ�����������
	std::vector<Point> curvePt_;
	int pos;
	BOOL back;
public:
	BezierFly(Point& a, Point& b, Point& c);
	~BezierFly();

	void SetCtrlPoint(Point& p,Point& q,Point& m);
	void CreateCurve();

	//��Ҫ�㷨�����������ϸ���������
	void CalCurvePoint(double t, Point& p);
	void Fly();
	
};

