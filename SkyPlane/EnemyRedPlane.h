#pragma once
#include "EnemyPrimaryPlane.h"
#include "Resource.h"

#define Enemy_Red_Plane_Height         48
#define Enemy_Red_Plane_Width		   66
#define Enemy_Red_Plane_Init_Speed     2.75
#define Enemy_Red_Plane_Init_HP         10
#define Enemy_Red_Plane_Fire_Open_Time  60

#define Enemy_Red_Plane_Image_Height    134
#define Enemy_Red_Plane_Image_Width     197


class EnemyRedPlane :public EnemyPrimaryPlane
{
protected:
	int op_;
public:
	EnemyRedPlane(int x,Point p);
	~EnemyRedPlane();
};