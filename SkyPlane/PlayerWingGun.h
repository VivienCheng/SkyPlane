#pragma once
#include "Point.h"
#include "Weapon.h"
#include "FlyObject.h"

//玩家翼炮，是玩家升级的设备之一。
//玩家翼炮的武器的飞行方式及其简单，直线向上飞行。

#define Player_Wing_Gun_Height 21
#define Player_Wing_Gun_Width  21
#define Player_Wing_Gun_Image_Height 64
#define Player_Wing_Gun_Image_Width  64
#define Player_Wing_Gun_Power   3
#define Player_Wing_Gun_Init_Speed 5

class PlayerWingGun : public Weapon
{
protected:
public:
	PlayerWingGun(Point p);
	~PlayerWingGun();
};