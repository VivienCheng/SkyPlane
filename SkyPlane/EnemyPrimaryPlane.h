#pragma once
#include "EnemyPlane.h"
#include "Resource.h"



// �趨���ò��ֻ����л�������ը�� ֻ��ͨ�����з�ʽ�谭���

class EnemyPrimaryPlane :public EnemyPlane
{
public:
	EnemyPrimaryPlane(int h,int w,Point p);
	~EnemyPrimaryPlane();
public:
	BOOL FireStatus();
	
};