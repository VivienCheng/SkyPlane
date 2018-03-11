#pragma once
#include "FlyObject.h"
#include "Point.h"
#include "Image.h"
#include "GameObject.h"

//构造函数以及析构函数
FlyObject::FlyObject(int h,int w,Point p) :GameObject(h, w, p) {}
FlyObject::~FlyObject(){}

//get
int FlyObject::Group() { return group_; }
double  FlyObject::SpeedX() { return speedX_; }
double  FlyObject::SpeedY() { return speedY_; }
CString FlyObject::Name() { return name_; }
FlyBehavior* FlyObject::GetFlyBehavior() { return flyBehavior_; }

//set
void  FlyObject::Group(int g) { group_ = g; }
void FlyObject::Speed(double x) { speedX_ = x; speedY_ = x; }
void  FlyObject::SpeedX(double x) { speedX_ = x; }
void  FlyObject::SpeedY(double y) { speedY_ = y; }
void  FlyObject::Name(CString n) { name_ = n; }
void FlyObject::SetFlyBehavior(FlyBehavior *f) { flyBehavior_ = f; }

//function

void FlyObject:: PerformFly()
{
	GetFlyBehavior()->Fly(); 
	JudgeKill();
}

void  FlyObject::AddSpeed(double a)
{
	speedX_ += a;
	speedY_ += a;
}



