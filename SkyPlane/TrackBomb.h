#pragma once
#include "Weapon.h"
#include "Resource.h"
#include "Player.h"



#define Track_Bomb_Height 23
#define Track_Bomb_Width 24
#define Track_Bomb_Image_Height 23
#define Track_Bomb_Image_Width  24
#define Track_Bomb_Image_Row 1
#define Track_Bomb_Image_Column 2
#define Track_Bomb_Power   5
#define Track_Bomb_Init_Speed 2

class TrackBomb:public Weapon
{
protected:
	Point *playerPos_;
public:
	TrackBomb(Point p,Point& q);
	~TrackBomb();
};