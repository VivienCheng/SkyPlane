#pragma once
#include "PlayerTrackBomb.h"
#include "Weapon.h"
#include "Resource.h"
#include "PlayerTrackFly.h"
#include "Player.h"
#include "FlyNoWay.h"

PlayerTrackBomb::PlayerTrackBomb(Point p, CList <GameObject*, GameObject*> *list):Weapon(Player_Track_Bomb_Height, Player_Track_Bomb_Width, p)
{
	plane_ = NULL;
	list_ = list;
	Delayer(10);
	Loop(TRUE);//PlayerTrackBomb
	Group(1);
	SpeedY(Player_Track_Bomb_Init_Speed);
	SpeedX(Player_Track_Bomb_Init_Speed / 2);
	Name(_T("PlayerBomb"));
	Power(Player_Track_Bomb_Power);
	Load_Image(bomb_up_1, Player_Track_Bomb_Image_Height, Player_Track_Bomb_Image_Width, Player_Track_Bomb_Image_Column, Player_Track_Bomb_Image_Row);
	SelectTarget();
	flyBehavior_ = new PlayerTrackFly(*(Position()),*(plane_),SpeedX(),SpeedY());
}

PlayerTrackBomb::~PlayerTrackBomb() {};

void PlayerTrackBomb::SelectTarget()
{
	POSITION pos = list_->GetHeadPosition();

	while (pos != NULL)
	{
		EnemyPlane *p = (EnemyPlane *)list_->GetNext(pos);
		if (!p->GetLock())
		{
			p->Lock();
			plane_ = p;
			return;
		}
	}

	Killed();
}

void PlayerTrackBomb::PerformFly()
{
	if (plane_ == NULL)
	{
		Killed();
		return;
	}
	GetFlyBehavior()->Fly();
	JudgeKill();

}