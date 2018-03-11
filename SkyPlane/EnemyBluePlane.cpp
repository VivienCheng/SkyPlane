#pragma once
#include "EnemyPrimaryPlane.h"
#include "EnemyBluePlane.h"
#include "Point.h"
#include "SlantFly.h"
#include "Resource.h"

EnemyBluePlane::EnemyBluePlane(int x,Point p) :EnemyPrimaryPlane(Enemy_Blue_Plane_Height, Enemy_Blue_Plane_Width, p),op_(x)
{
	HP(Enemy_Blue_Plane_Init_HP);
	FireOpenTimes(Enemy_Blue_Plane_Fire_Open_Time);
	Speed(Enemy_Blue_Plane_Init_Speed);
	Load_Image(enemy_blue_plane, Enemy_Blue_Plane_Image_Height, Enemy_Blue_Plane_Image_Width);
	if (op_ == 1) {
		flyBehavior_ = new SlantFly(*(Position()), SpeedX() + 1.5, SpeedY());
	}
	else if (op_ == 2)
	{
		flyBehavior_ = new SlantFly(*(Position()), -SpeedX() - 1.5, SpeedY());
	}
}
EnemyBluePlane::~EnemyBluePlane() {}
