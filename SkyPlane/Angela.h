#pragma once
#include "Plane.h"
#include "Point.h"
#include "Resource.h"
#include "FlyNoWay.h"

#define Angela_Height         70.8
#define Angela_Width		   70.8
#define Angela_Init_Speed      0.5//0.5
#define Angela_Init_HP         300
#define Angela_Fire_Open_Time  30
#define Angela_Weapon_ID  10 //使用PlayerWingGun

#define Angela_Image_Height    141.6
#define Angela_Image_Width     141.6
#define Angela_Image_Column    3
#define Angela_Image_Row       3


class Angela :public Plane
{
protected:
	int op_; // 1:左翼飞机  2：右翼飞机
public:
	Angela(Point p, int op);
	~Angela();
	void PerformFly();
	int Op();
	void Op(int x, Point* p,Point *q, double a,double b);
};