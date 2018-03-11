#pragma once
#include "Plane.h"
#include "resource.h"
#include "Player.h"
#include "FlyNoWay.h"
#include "Point.h"

Player::Player() :Plane(Player_Height, Player_Width, Point(Player_Init_Pos_X, Player_Init_Pos_Y))
{
	HP(Player_Init_HP);
	FireOpenTimes(Player_Fire_Open_Time);
	WeaponID(Player_Init_Weapon_ID);
	Group(1);
	Speed(Player_Init_Speed);
	Name(_T("Player"));
	Load_Image(player,Player_Image_Height, Player_Image_Width, Player_Image_Column, Player_Image_Row);
	NumOfStars(0);
	Index(17);//加载正中央的飞机图片
	counterLeft_ = 0;
	counterRight_ = 0;
	counterCenter_ = 0;
	flyBehavior_ = new FlyNoWay(*(Position()));

}
Player::~Player() {};

//get
int Player::CounterLeft() { return counterLeft_; }
int Player::CounterRight() { return counterRight_; }
int Player::CounterCenter() { return counterCenter_; }

//set
void Player::CounterLeft(int x) { counterLeft_ = x; }
void Player::CounterRight(int x) { counterRight_ = x;}
void Player::CounterCenter(int x) { counterCenter_ = x; }

//Add
void Player::AddCounterLeft() { counterLeft_++; }
void Player::AddCounterRight() { counterRight_++; }
void Player::AddCounterCenter() { counterCenter_++; }

//Sub
void Player::SubCounterLeft() { counterLeft_--; }
void Player::SubCounterRight() { counterRight_--; }
void Player::SubCounterCenter() { counterCenter_--; }

// 索引： 0-15 Left 16 Center 17-31 Right
void Player::LoadLeftImage()
{
	AddCounterLeft();
	if (CounterLeft() == 3)
	{
		SubIndex();
		CounterLeft(0);
	}
}
void Player::LoadRightImage()
{
	AddCounterRight();
	if (CounterRight() == 3)
	{
		AddIndex();
		CounterRight(0);
	}
}
void Player::LoadForwardImage()
{
	if (Index() > 17)
	{
		SubIndex();//如果在右边 则要加载左边图片，直至转到中心图片
	}
	else if (Index() < 17)
	{
		AddIndex();//如果在左边 则要加载右边图片，直至转到中心图片
	}
}
void Player::MoveToRight()
{
	MoveX(SpeedX());
	LoadRightImage();
	if (X() > Game_Width - Player_Width)
	{
		Position()->X(Game_Width - Player_Width);
	}
}
void Player::MoveToLeft()
{
	MoveX(-SpeedX());
	LoadLeftImage();
	if (X() < 0)
	{
		Position()->X(0);
	}
}
void Player::MoveToTop()
{
	MoveY(-SpeedY());
	LoadForwardImage();
	if (Y() < 0)
	{
		Position()->Y(0);
	}
}
void Player::MoveToBottom()
{
	MoveY(SpeedY());
	LoadForwardImage();
	if (Y() > Game_Height - Player_Height)
	{
		Position()->Y(Game_Height - Player_Height);
	}
}

void  Player::PerformFly()
{
	GetFlyBehavior()->Fly();
}

