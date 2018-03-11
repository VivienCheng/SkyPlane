#pragma once
#include "EnemyPlane.h"

#define	Boss_Mid_Height         313
#define Boss_Mid_Width		  223
#define Boss_Mid_Init_Speed     0.5
#define Boss_Mid_Init_HP         300
#define Boss_Mid_Fire_Open_Time  45
#define Boss_Mid_Init_Waepon_ID   2 //´óÐÍ×·×ÙÅÚ
#define Boss_Mid_Image_Height    313
#define Boss_Mid_Image_Width     223


class BossMid :public EnemyPlane
{
public:
	BossMid(Point& p);
	~BossMid();
	void PerformFly();
};