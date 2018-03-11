#pragma once
#include "Plane.h"
#include "FlyObject.h"
#include "Point.h"
#include "stdafx.h"

class Plane:public FlyObject
{
protected:
	int HP_;
	BOOL fire_;
	int fireOpenTimes_;
	int counter2_;
	int weaponID_;
	int numOfStars_;
	CString detailedName_;
	BOOL shine_;
public:
	Plane(int h, int w, Point p);
	~Plane();
public:
	//get
	int HP();
	BOOL Fire();
	int Stars();
	int FireOpenTimes();
	int WeaponID();
	int NumOfStars();
	CString DetailedName();
	BOOL Shine();
public:
	//set
	void HP(int x);
	void Fire(BOOL x);
	void FireOpenTimes(int x);
	void WeaponID(int x);
	void FireOn();
	void FireOff();
	void NumOfStars(int x);
	void DetailedName(CString s);
	void Shine(BOOL x);
public:
	//function
	void AddStars(int x);//打灭敌人的时候用得到
	void SubStars(int x);//升级装备的时候用得到
	void AddHP(int x);
	void SubHP(int x);
	virtual BOOL FireStatus();
	void AddTool(CString name, CString planeName, int mark);
	
};