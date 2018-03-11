#pragma once
#include "GameObject.h"
#include "Resource.h"

#define Background_Height Game_Height
#define Background_Width Game_Width
#define Background_Image_Height 800
#define Background_Image_Width  480
#define Init_Roll_Speed 0.5


class Background :public GameObject
{
protected:
	mutable int y_;
	double rollSpeed_;
public:
	Background();
	Background(int h,int w,Point p);
	~Background();
public:
	//function
	void MoveImage();
	void Draw(CDC *cDC);
public:
	//set
	void RollSpeed(double x);
public:
	//get
	double RollSpeed();
};