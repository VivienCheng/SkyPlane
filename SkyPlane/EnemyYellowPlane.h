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
	int  op_;//1:纵向移动，左侧 2：纵向移动 右侧 3：横向移动 左侧向上 4：横向移动 左侧向下
			//5：横向移动 右侧向上 6：横向移动 右侧向下 7:从中间向右 8：从中间向左 
			//9:从左上向中下 10：从右上向中下
public:
	EnemyYellowPlane(int x,Point p);
	~EnemyYellowPlane();
};
