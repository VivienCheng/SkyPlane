#pragma once
#include "EnemyPlane.h"

#define	Boss_Right_Height         129
#define Boss_Right_Width		   81
#define Boss_Right_Init_Speed     0.5
#define Boss_Right_Init_HP         100
#define Boss_Right_Fire_Open_Time  45
#define Boss_Right_Init_Waepon_ID   3 //Ð¡ÐÍ×·×ÙÅÚ
#define Boss_Right_Image_Height    129
#define Boss_Right_Image_Width     81


class BossRight :public EnemyPlane
{
public:
	BossRight(Point& p);
	~BossRight();
	void PerformFly();
};