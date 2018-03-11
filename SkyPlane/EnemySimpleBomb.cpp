#pragma once
#include "EnemySimpleBomb.h"
#include "FlyBehavior.h"
#include "SimpleFly.h"
#include "Resource.h"



EnemySimpleBomb::EnemySimpleBomb(Point p):Weapon(Enemy_Simple_Bomb_Height, Enemy_Simple_Bomb_Width,p)
{
	Delayer(10);
	Loop(TRUE);
	Group(-1);
	Speed(Enemy_Simple_Bomb_Init_Speed);
	Name(_T("EnemyBomb"));
	Power(Enemy_Simple_Bomb_Power);
	Load_Image(bomb_down_1,Enemy_Simple_Bomb_Image_Height, Enemy_Simple_Bomb_Image_Width,  Enemy_Simple_Bomb_Image_Column, Enemy_Simple_Bomb_Image_Row);
	flyBehavior_ = new SimpleFly(*(Position()), SpeedY());//此处传入SpeedY() 代表敌机炸弹运动轨迹为直线向下
}


EnemySimpleBomb::~EnemySimpleBomb() {}
