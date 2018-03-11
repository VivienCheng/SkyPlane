#pragma once
#include "Tank.h"
#include "Point.h"
#include "EnemySeniorPlane.h"
#include "FlyNoWay.h"
#include "Resource.h"


Tank::Tank(Point p):EnemySeniorPlane(Tank_Height, Tank_Width,p)
{
	DetailedName("Tank");
	HP(Tank_Init_HP);
	FireOpenTimes(Tank_Fire_Open_Time);
	WeaponID(Tank_Init_Waepon_ID);
	Speed(Tank_Init_Speed);
	Load_Image(tank, Tank_Image_Height, Tank_Image_Width, Tank_Image_Column, Tank_Image_Row);
	flyBehavior_ = new FlyNoWay(*(Position()));
}
Tank::~Tank(){}

