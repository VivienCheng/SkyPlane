#include "PlayerWingGun.h"
#include "FlyBehavior.h"
#include "SimpleFly.h"
#include "Resource.h"



PlayerWingGun::PlayerWingGun(Point p) :Weapon(Player_Wing_Gun_Height, Player_Wing_Gun_Width, p)
{
	Group(1);
	Speed(Player_Wing_Gun_Init_Speed);
	Name(_T("PlayerBomb"));
	Power(Player_Wing_Gun_Power);
	Load_Image(wing_shot, Player_Wing_Gun_Image_Height, Player_Wing_Gun_Image_Width);
	flyBehavior_ = new SimpleFly(*(Position()), -SpeedY());//此处传入SpeedY() 代表运动轨迹为直线向上
}

PlayerWingGun::~PlayerWingGun() {}

