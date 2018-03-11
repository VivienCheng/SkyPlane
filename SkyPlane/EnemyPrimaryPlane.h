#pragma once
#include "EnemyPlane.h"
#include "Resource.h"



// 设定：让部分基础敌机不能扔炸弹 只能通过飞行方式阻碍玩家

class EnemyPrimaryPlane :public EnemyPlane
{
public:
	EnemyPrimaryPlane(int h,int w,Point p);
	~EnemyPrimaryPlane();
public:
	BOOL FireStatus();
	
};