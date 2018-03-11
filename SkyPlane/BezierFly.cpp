#pragma once
#include "FlyBehavior.h"
#include "BezierFly.h"
#include "Point.h"
#include "Resource.h"
#include <math.h>


BezierFly::BezierFly(Point& a, Point& b, Point& c) :FlyBehavior(a), b_(&b), c_(&c)
{
	SetCtrlPoint(*(a_),*(b_),*(c_));
	CreateCurve();
	int Temp = curvePt_.size();
	//CString temp;
	//temp.Format(_T("%d"), Temp);
	//MessageBox(0,temp,0,0);
	pos = 0;
	back = FALSE;
}

BezierFly::~BezierFly() {};


void BezierFly::SetCtrlPoint(Point& p,Point& q,Point& m)
{
	ctrlPt_.push_back(p);
	ctrlPt_.push_back(q);
	ctrlPt_.push_back(m);
}

void BezierFly::CreateCurve()
{
	//ȷ���Ƕ������ߣ�2������ 1�����Ƶ�
//	assert(ctrlPt_.size() == 3);

	//t������������ͨ��step��Сȷ����Ҫ����������ϵ�ĸ���
	double step = 0.01;
	for (double t = 0.0; t <= 1.0; t += step)
	{
		Point stPt;
		CalCurvePoint(t, stPt);
		curvePt_.push_back(stPt);
	}
}

//��Ҫ�㷨�����������ϸ���������
void BezierFly::CalCurvePoint(double t, Point& p)
{
	//ȷ���Ƕ������ߣ� 2�����㣬1�����Ƶ�
	//assert(ctrlPt_.size() == 3);

	// �������ߵ����꣬��Ϊ2���㷨���ı�˴�����ʵ�ֶ������ 
	double x = ctrlPt_[0].X() * pow(1 - t, 2) + ctrlPt_[1].X() * t * (1 - t) * 2 + ctrlPt_[2].X() * pow(t, 2);
	double y = ctrlPt_[0].Y() * pow(1 - t, 2) + ctrlPt_[1].Y() * t * (1 - t) * 2 + ctrlPt_[2].Y() * pow(t, 2);

	p.X(x);
	p.Y(y);
}

void  BezierFly::Fly()
{
	if (pos < curvePt_.size() && pos >= 0) {
		Point target = curvePt_[pos];
		double ox = a_->X();
		double oy = a_->Y();

		double tx = curvePt_[pos].X();
		double ty = curvePt_[pos].Y();

		if (std::fabs(ox - tx) <= 0.1 && std::fabs(oy - ty) <= 0.1) {
			if (!back) ++pos;
			else --pos;
		}
		else {
			for (int i = 0; i < 200; i++)
			{
				if (std::fabs(ox - tx) >= 0.1) {
					if (ox < tx) { ox += 0.01; }
					else if (ox > tx) { ox -= 0.01; }
				}
				if (std::fabs(oy - ty) >= 0.1) {
					if (oy < ty) { oy += 0.01; }
					else if (oy > ty) { oy -= 0.01; }
				}
			}
		}
		a_->SetPoint(ox, oy);
	}

	else {
		if (!back) {
			--pos;
			back = TRUE;
		}
		else {
			++pos;
			back = FALSE;
		}
	}
}

//���α��������߷������£�

//B(t) = (1-t)^2 * P0 + 2 * t * (1-t) * P1 + t^2 * P2;

//PO����� P2���յ� һ�㲻����P3��
