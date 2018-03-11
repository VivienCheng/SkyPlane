#pragma once
#include "Plane.h"
#include "Resource.h"



class EnemyPlane :public Plane
{
protected:
	BOOL lock_;
public:
	EnemyPlane(int h, int w, Point p);
	~EnemyPlane();
public:
	void Lock();
	BOOL GetLock();

};