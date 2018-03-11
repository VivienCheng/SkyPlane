#pragma once
#include "EnemyPrimaryPlane.h"
#include "EnemyRedPlane.h"
#include "Point.h"
#include "SimpleFly.h"
#include "Resource.h"

EnemyRedPlane::EnemyRedPlane(int x,Point p):EnemyPrimaryPlane(Enemy_Red_Plane_Height, Enemy_Red_Plane_Width,p),op_(x)
{
	HP(Enemy_Red_Plane_Init_HP);
	FireOpenTimes(Enemy_Red_Plane_Fire_Open_Time);
	Speed(Enemy_Red_Plane_Init_Speed);
	Load_Image(enemy_red_plane, Enemy_Red_Plane_Image_Height, Enemy_Red_Plane_Image_Width);
	if (op_ == 1) {
		flyBehavior_ = new SimpleFly(*(Position()), SpeedY());
	}
	else if (op_ == 2)
	{
		flyBehavior_ = new SimpleFly(*(Position()), -SpeedY());
	}
}
EnemyRedPlane::~EnemyRedPlane() {}
