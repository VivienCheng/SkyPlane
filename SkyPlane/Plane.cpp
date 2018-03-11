#pragma once;
#include "Plane.h"
#include "GameObject.h"
#include "FlyObject.h"


Plane::Plane(int h, int w, Point p):FlyObject(h, w, p) 
{
	counter2_ = 0;
	fire_ = FALSE;
	numOfStars_ = 0;
	shine_ = FALSE;
}
Plane::~Plane() {}

//get
int Plane::HP() { return HP_; }
BOOL Plane::Fire() { return fire_; }
int Plane::FireOpenTimes() { return fireOpenTimes_; }
int Plane::WeaponID() { return weaponID_; }
int Plane::NumOfStars() { return numOfStars_; }
CString Plane::DetailedName() {return detailedName_;}
BOOL Plane::Shine() { return shine_; }
int Plane::Stars() { return numOfStars_; }

//set
void Plane::HP(int x) { HP_ = x; }
void Plane::Fire(BOOL x) { fire_ = x; }
void Plane::FireOpenTimes(int x) { fireOpenTimes_ = x; }
void Plane::WeaponID(int x) { weaponID_ = x; }
void Plane::FireOn() { fire_ = TRUE; }
void Plane::FireOff() { fire_ = FALSE; }
void Plane::NumOfStars(int x) { numOfStars_ = x; }
void Plane::DetailedName(CString s){detailedName_ = s;}
void Plane::Shine(BOOL x) { shine_ = x; }

//function
void Plane::AddHP(int x) { HP_ += x; }
void Plane::SubHP(int x) 
{
	if (HP_ >= x)
	{
		HP_ -= x;
	}
	else {
		HP_ = 0;
		Killed();
	}
}
void Plane::AddStars(int x) { numOfStars_ += x; }
void Plane::SubStars(int x) 
{
	if (numOfStars_ >= x)
	{
		numOfStars_ -= x;
	}
}
BOOL Plane::FireStatus()
{

	if (Fire())
	{
		FireOff();
		counter2_ = 0;
		return TRUE;
	}
	else {
		counter2_++;
		if (counter2_ == FireOpenTimes())
		{
			FireOn();
		}
		return FALSE;
	}
}

void Plane::AddTool(CString name,CString planeName, int num)
{
	if (planeName == "EnemyPrimaryPlane") 
	{
		AddStars(num);
		/*
		if (Shine() == TRUE)
		{
			AddSpeed(num);
		}
		else {
			AddStars(num);
		}*/
	}
	else if (planeName == "PropellerPlane")
	{
		AddHP(num);
		/*
		if (Shine() == TRUE)
		{
			AddSpeed(num);
		}
		else {
			AddHP(num);
		}*/
	}
	else if (planeName == "Tank")
	{
		AddSpeed(num);
	}
	else if (planeName == "Box")
	{
		if (name == "Heart")
		{
			AddHP(num);
		}
		else if (name == "Star")
		{
			AddStars(num);
		}
		else if (name == "Wing")
		{
			AddSpeed(num);
		}
	}
}
