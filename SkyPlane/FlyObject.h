#pragma once
#include "GameObject.h"
#include "FlyBehavior.h"

class FlyObject :public GameObject
{
public:
	int group_;//派别 -1代表是敌机武器
	double speedX_;
	double speedY_;
	CString name_;//名字
	FlyBehavior *flyBehavior_;//飞行方式
public:
	FlyObject(int height, int weight, Point pos);
	~FlyObject();
public:
	//get
	int Group();
	double SpeedX();
	double SpeedY();
	CString Name();
	FlyBehavior* GetFlyBehavior();

public:
	//set
	void Group(int g);
	void Speed(double x);
	void SpeedX(double x);
	void SpeedY(double y);
	void Name(CString n);
	void SetFlyBehavior(FlyBehavior *f);

public:
	void PerformFly(); 
	void AddSpeed(double a);
};