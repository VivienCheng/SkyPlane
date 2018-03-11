#pragma once
#include "Point.h"
#include "Weapon.h"
#include "FlyObject.h"


#define Enemy_Simple_Bomb_Height 31
#define Enemy_Simple_Bomb_Width  20
#define Enemy_Simple_Bomb_Image_Height 93
#define Enemy_Simple_Bomb_Image_Width  30
#define Enemy_Simple_Bomb_Image_Row    1
#define Enemy_Simple_Bomb_Image_Column 2
#define Enemy_Simple_Bomb_Power   5
#define Enemy_Simple_Bomb_Init_Speed 2

class EnemySimpleBomb: public Weapon
{
protected:
public:
	EnemySimpleBomb(Point p);
	~EnemySimpleBomb();

};