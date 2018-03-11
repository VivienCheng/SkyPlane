#pragma once
#include "EnemyPrimaryPlane.h"
#include "Resource.h"
#include "EnemyRedPlane.h"
#include "EnemyBluePlane.h"
#include <vector>

#define Enemy_Yellow_Plane_Height         48
#define Enemy_Yellow_Plane_Width		   66
#define Enemy_Yellow_Plane_Init_Speed      2.25
#define Enemy_Yellow_Plane_Init_HP         5
#define Enemy_Yellow_Plane_Fire_Open_Time  60

#define Enemy_Yellow_Plane_Init_Pos_X      Game_Width / 2 - Player_Width / 2
#define Enemy_Yellow_Plane_Init_Pos_Y	   Game_Height - Player_Height

#define Enemy_Yellow_Plane_Image_Height    134
#define Enemy_Yellow_Plane_Image_Width     197


class EnemyYellowPlane :public EnemyPrimaryPlane
{
protected:
	std::vector<Point>* pointArray_;
	int  op_;//1:�����ƶ������ 2�������ƶ� �Ҳ� 3�������ƶ� ������� 4�������ƶ� �������
			//5�������ƶ� �Ҳ����� 6�������ƶ� �Ҳ����� 7:���м����� 8�����м����� 
			//9:������������ 10��������������
public:
	EnemyYellowPlane(int x,Point p);
	~EnemyYellowPlane();
};
