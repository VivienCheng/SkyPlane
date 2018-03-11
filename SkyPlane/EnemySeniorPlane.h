#pragma once
#include "EnemyPlane.h"
#include "Resource.h"


class EnemySeniorPlane :public EnemyPlane
{
public:
	EnemySeniorPlane(int h, int w, Point p);
	~EnemySeniorPlane();
public:
	BOOL FireStatus();

};