#pragma once
#include "FlyObject.h" 

class Weapon: public FlyObject
{
protected:
	int power_;//Œ‰∆˜…À∫¶÷µ
public:
	Weapon(int h,int w,Point p);
	~Weapon();
public:
	//set
	void Power(int x);
public:
	//get
	int Power();
};