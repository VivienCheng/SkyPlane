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


//��������Y����ֱ�ϻ���ֱ��
//������ĳЩ�����ĵл���ը������ҵ����ڹ���