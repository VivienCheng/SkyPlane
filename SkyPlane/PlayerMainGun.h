#pragma once
#include "Point.h"
#include "Weapon.h"
#include "FlyObject.h"

//玩家主炮，是玩家最基础的设备。
//玩家主炮的武器的飞行方式及其简单，直线向上飞行。

#define Player_Main_Gun_Height 38
#define Player_Main_Gun_Width  6
#define Player_Main_Gun_Image_Height 84
#define Player_Main_Gun_Image_Width  15
#define Player_Main_Gun_Power   5
#define Player_Main_Gun_Init_Speed 5

class PlayerMainGun : public Weapon
{
protected:
public:
	PlayerMainGun(Point p);
	~PlayerMainGun();

};