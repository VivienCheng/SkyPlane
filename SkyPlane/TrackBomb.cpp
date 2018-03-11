#pragma once
#include "TrackBomb.h"
#include "Weapon.h"
#include "Resource.h"
#include "TrackFly.h"
#include "Player.h"

TrackBomb::TrackBomb(Point p, Point& q) :Weapon(Track_Bomb_Height, Track_Bomb_Width, p), playerPos_(&q)
{
	Delayer(10);
	Loop(TRUE);
	Group(-1);
	Speed(Track_Bomb_Init_Speed);
	Name(_T("EnemyBomb"));
	Power(Track_Bomb_Power);
	Load_Image(track_bomb_1, Track_Bomb_Image_Height, Track_Bomb_Image_Width, Track_Bomb_Image_Column, Track_Bomb_Image_Row);
	flyBehavior_ = new TrackFly(*(Position()),*(playerPos_),SpeedX(),SpeedY());
}

TrackBomb::~TrackBomb() {};

