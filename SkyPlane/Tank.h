#pragma once
#include "EnemySeniorPlane.h"
#include "Resource.h"

#define Tank_Height        57
#define Tank_Width		   74
#define Tank_Image_Column     2
#define Tank_Image_Row        1
#define Tank_Init_Speed      0.3
#define Tank_Init_HP         50
#define Tank_Fire_Open_Time  100
#define Tank_Init_Waepon_ID  2  //²úÉúÌ¹¿ËÕ¨µ¯

#define Tank_Init_Pos_X      Game_Width / 3
#define Tank_Init_Pos_Y	   Game_Height /8

#define Tank_Image_Height    57
#define Tank_Image_Width     74

class Tank :public EnemySeniorPlane
{
public:
	Tank(Point p);
	~Tank();
};
