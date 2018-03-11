#pragma once
#include "PropellerPlane.h"
#include "Point.h"
#include "EnemySeniorPlane.h"
#include "SlantFly.h"
#include "Resource.h"

PropellerPlane::PropellerPlane(int x, Point p): EnemySeniorPlane(Propeller_Plane_Height, Propeller_Plane_Width,p),op_(x)
{
	DetailedName("PropellerPlane");
	HP(Propeller_Plane_Init_HP);
	FireOpenTimes(Propeller_Plane_Fire_Open_Time);
	WeaponID(Propeller_Plane_Init_Waepon_ID);
	Speed(Propeller_Plane_Init_Speed);
	Load_Image(track_plane_1, Propeller_Plane_Image_Height, Propeller_Plane_Image_Width);
	if (op_ == 1) {
		flyBehavior_ = new SlantFly(*(Position()), SpeedX() + 1.25, SpeedY() - 0.25);
	}
	else if (op_ == 2)
	{
		flyBehavior_ = new SlantFly(*(Position()), -SpeedX() - 1.25, SpeedY() - 0.25);
	}
}

PropellerPlane::~PropellerPlane() {};