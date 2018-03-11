#pragma once
#include "EnemyPlane.h"

#define	Boss_Left_Height         129
#define Boss_Left_Width		   81
#define Boss_Left_Init_Speed     0.5
#define Boss_Left_Init_HP         100
#define Boss_Left_Fire_Open_Time  45
#define Boss_Left_Init_Waepon_ID   3 //Ð¡ÐÍ×·×ÙÅÚ
#define Boss_Left_Image_Height    129
#define Boss_Left_Image_Width     81


class BossLeft :public EnemyPlane
{
public:
	BossLeft(Point& p);
	~BossLeft();
	void PerformFly();
};