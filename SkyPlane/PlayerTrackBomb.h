#pragma once
#include "Point.h"
#include "Weapon.h"
#include "Resource.h"
#include "EnemyPlane.h"
#include "FlyObject.h"
#include "GameObject.h"


#define Player_Track_Bomb_Height 46.5
#define Player_Track_Bomb_Width 15
#define Player_Track_Bomb_Image_Height 93
#define Player_Track_Bomb_Image_Width  30
#define Player_Track_Bomb_Image_Row 1
#define Player_Track_Bomb_Image_Column 2
#define Player_Track_Bomb_Power   20
#define Player_Track_Bomb_Init_Speed 2

class PlayerTrackBomb :public Weapon
{
protected:
	CList <GameObject*, GameObject*> *list_;
	EnemyPlane *plane_;
public:
	PlayerTrackBomb(Point p, CList <GameObject*, GameObject*> *list);
	~PlayerTrackBomb();
	void SelectTarget();
	void PerformFly();

};