#pragma once
#include "TrackBomb.h"
#include "Point.h"

#define Tank_Bomb_Height 64.7
#define Tank_Bomb_Width 64.7
#define Tank_Bomb_Image_Height 194
#define Tank_Bomb_Image_Width  194
#define Tank_Bomb_Image_Row 1
#define Tank_Bomb_Image_Column 1
#define Tank_Bomb_Power   50
#define Tank_Bomb_Init_Speed 3


class TankBomb:public Weapon
{
protected:
	Point *playerPos_;
public:
	TankBomb(Point p,Point &q);
	~TankBomb();
};