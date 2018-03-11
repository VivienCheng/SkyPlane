#pragma once
#include "TrackBomb.h"
#include "Resource.h"
#include "EnemySeniorPlane.h"

#define Propeller_Plane_Height         69
#define Propeller_Plane_Width		   90
#define Propeller_Plane_Init_Speed      0.75
#define Propeller_Plane_Init_HP         5
#define Propeller_Plane_Fire_Open_Time  60
#define Propeller_Plane_Init_Waepon_ID  3 //ʹ��TrackBomb

#define Propeller_Plane_Init_Pos_X      Game_Width / 2 - Player_Width / 2
#define Propeller_Plane_Init_Pos_Y	   Game_Height - Player_Height

#define Propeller_Plane_Image_Height    69
#define Propeller_Plane_Image_Width     90


class PropellerPlane:public EnemySeniorPlane
{
protected:
	int op_;//1���������� 2���������� 
public:
	PropellerPlane(int x, Point p);
	~PropellerPlane();
};