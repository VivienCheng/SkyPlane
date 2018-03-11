#pragma once
#include "EnemyPrimaryPlane.h"
#include "Resource.h"

#define Box_Height         32
#define Box_Width		   32
#define Box_Init_Speed     0.5
#define Box_Init_HP        100
#define Box_Image_Height   128
#define Box_Image_Width    128


class Box :public EnemyPrimaryPlane
{
public:
	Box(Point p);
	~Box();

};