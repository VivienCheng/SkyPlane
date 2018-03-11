#pragma once
#include "EnemyPlane.h"
#include "EnemySeniorPlane.h"
#include "Resource.h"
#include "Point.h"

EnemySeniorPlane::EnemySeniorPlane(int h, int w, Point p) :EnemyPlane(h, w, p)
{

}
EnemySeniorPlane::~EnemySeniorPlane() {}

BOOL EnemySeniorPlane::FireStatus()
{
	if (Fire())
	{
		FireOff();
		ClearCounter();
		return TRUE;
	}
	else {
		AddCounter();
		if (Counter() == FireOpenTimes())
		{
			FireOn();
		}
		return FALSE;
	}
}