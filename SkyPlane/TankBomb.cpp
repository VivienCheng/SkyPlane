#pragma once
#include "TrackBomb.h"
#include "Weapon.h"
#include "TankBomb.h"
#include "Resource.h"
#include "TrackFly.h"
#include "Player.h"

TankBomb::TankBomb(Point p, Point& q) :Weapon(Tank_Bomb_Height, Tank_Bomb_Width, p), playerPos_(&q)
{
	Delayer(100);
	Loop(TRUE);
	Group(2);
	Speed(Tank_Bomb_Init_Speed);
	Name(_T("EnemyBomb"));
	Power(Tank_Bomb_Power);
	Load_Image(track_bomb_2, Tank_Bomb_Image_Height, Tank_Bomb_Image_Width, Tank_Bomb_Image_Column, Tank_Bomb_Image_Row);
	flyBehavior_ = new TrackFly(*(Position()), *(playerPos_), SpeedX(), SpeedY());
}

TankBomb::~TankBomb() {};
