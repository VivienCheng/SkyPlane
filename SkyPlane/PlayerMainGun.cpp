#include "PlayerMainGun.h"
#include "FlyBehavior.h"
#include "SimpleFly.h"
#include "Resource.h"
#include "PlayerMainGun.h"



PlayerMainGun::PlayerMainGun(Point p) :Weapon(Player_Main_Gun_Height, Player_Main_Gun_Width, p)
{
	Delayer(10);
	Loop(TRUE);
	Group(1);

	Speed(Player_Main_Gun_Init_Speed);
	Name(_T("PlayerBomb"));
	Power(Player_Main_Gun_Power);
	Load_Image(bullet_1, Player_Main_Gun_Image_Height, Player_Main_Gun_Image_Width);
	flyBehavior_ = new SimpleFly(*(Position()), -SpeedY());//此处传入SpeedY() 代表敌机炸弹运动轨迹为直线向上
}

PlayerMainGun::~PlayerMainGun() {}

