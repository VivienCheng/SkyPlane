#pragma once
#include "FlyBehavior.h"
#include "Point.h"
#include "EnemyPlane.h"
#include "Resource.h"
#include "GameObject.h"


class PlayerTrackFly :public FlyBehavior
{
protected:
	EnemyPlane *tar_;
	double xp_, yp_;
	int num;
public:
	PlayerTrackFly(Point&a, EnemyPlane& t,double c,double b);
	~PlayerTrackFly();
	void Fly();
};