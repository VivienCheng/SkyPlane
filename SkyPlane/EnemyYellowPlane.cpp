#pragma once
#include "EnemyPrimaryPlane.h"
#include "EnemyYellowPlane.h"
#include "Point.h"
#include "BezierFly.h"
#include "Resource.h"

EnemyYellowPlane::EnemyYellowPlane(int x,Point p) :EnemyPrimaryPlane(Enemy_Yellow_Plane_Height, Enemy_Yellow_Plane_Width, p),op_(x)
{
	HP(Enemy_Yellow_Plane_Init_HP);
	FireOpenTimes(Enemy_Yellow_Plane_Fire_Open_Time);
	Speed(Enemy_Yellow_Plane_Init_Speed);
	Load_Image(enemy_yellow_plane, Enemy_Yellow_Plane_Image_Height, Enemy_Yellow_Plane_Image_Width);
	//1:�����ƶ������ 2�������ƶ� �Ҳ� 
	//3�������ƶ� ������� 4�������ƶ� �������
	//5�������ƶ� �Ҳ����� 6�������ƶ� �Ҳ����� 
	//7:���м������� 8�����м������� 
	//9:������������ 10��������������
	     if (op_ == 1)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Position()->X() + 200, Position()->Y() + 200), Point(Position()->X(), Position()->Y() + 400));
	}     
	else if (op_ == 2)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Position()->X() - 200, Position()->Y() + 200), Point(Position()->X(), Position()->Y() + 400));
	}
	else if (op_ == 3)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Position()->X() + 200, Position()->Y() + 200), Point(Game_Width, Position()->Y()));
	}
	else if (op_ == 4)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Position()->X() + 200, Position()->Y() - 200), Point(Game_Width, Position()->Y()));
	}
	else if (op_ == 5)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Position()->X() - 200, Position()->Y() + 200), Point(0, Position()->Y()));
	}
	else if (op_ == 6)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Position()->X() - 200, Position()->Y() - 200), Point(0, Position()->Y()));
	}
	else if (op_ == 7)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Game_Width / 5 * 2, Game_Height / 3), Point(Game_Width, Game_Height / 3));
	}
	else if (op_ == 8)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Game_Width / 5 * 3, Game_Height / 3), Point(0, Game_Height / 3));
	}
	else if (op_ == 9)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Game_Width / 5 * 2, Position()->Y()), Point(Game_Width / 5 * 2, Game_Height));
	}
	else if (op_ == 10)
	{
		flyBehavior_ = new BezierFly(*(Position()), Point(Game_Width/ 5 * 3, Position()->Y()), Point(Game_Width / 5 * 3, Game_Height));
	}
}
EnemyYellowPlane::~EnemyYellowPlane() {}
