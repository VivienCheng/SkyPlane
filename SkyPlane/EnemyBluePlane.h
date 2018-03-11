#pragma once
#include "EnemyPrimaryPlane.h"
#include "Resource.h"

#define Enemy_Blue_Plane_Height         48
#define Enemy_Blue_Plane_Width		   66
#define Enemy_Blue_Plane_Init_Speed      1.75
#define Enemy_Blue_Plane_Init_HP         10
#define Enemy_Blue_Plane_Fire_Open_Time  60

#define Enemy_Blue_Plane_Init_Pos_X      Game_Width / 2 - Player_Width / 2
#define Enemy_Blue_Plane_Init_Pos_Y	   Game_Height - Player_Height

#define Enemy_Blue_Plane_Image_Height    134
#define Enemy_Blue_Plane_Image_Width     197


class EnemyBluePlane :public EnemyPrimaryPlane
{
protected:
	int op_; // 1:从左上向右下 2：从右上向左下
public:
	EnemyBluePlane(int x,Point p);
	~EnemyBluePlane();
};