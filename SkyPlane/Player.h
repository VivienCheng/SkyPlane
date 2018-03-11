#pragma once
#include "Plane.h"
#include "resource.h"


#define Player_Height          60
#define Player_Width		   60
#define Player_Init_Speed      5
#define Player_Init_HP         10000
#define Player_Fire_Open_Time  15
#define Player_Init_Weapon_ID  1

#define Player_Init_Pos_X      Game_Width / 2 - Player_Width / 2
#define Player_Init_Pos_Y	   Game_Height - Player_Height
#define Player_Image_Height    306.5
#define Player_Image_Width     308.5
#define Player_Image_Column    4
#define Player_Image_Row       8

class Player :public Plane
{
protected:
	int counterLeft_;
	int counterRight_;
	int counterCenter_;
public:
	Player();
	~Player();
public:
	//get
	int CounterLeft();
	int CounterRight();
	int CounterCenter();
public:
	//set
	void CounterLeft(int x);
	void CounterRight(int x);
	void CounterCenter(int x);
public:
	//Add
	void AddCounterLeft();
	void AddCounterRight();
	void AddCounterCenter();
public:
	//Sub
	void SubCounterLeft();
	void SubCounterRight();
	void SubCounterCenter();
public:
	//function
	void LoadLeftImage();
	void LoadRightImage();
	void LoadForwardImage();
	void MoveToRight();
	void MoveToLeft();
	void MoveToTop();
	void MoveToBottom();

	void PerformFly();


};