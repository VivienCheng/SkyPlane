#pragma once
#include "GameObject.h"
#include "Point.h"

#define Init_Speed 0.3

#define Cloud_1_Height 282
#define Cloud_1_Width 512
#define Cloud_1_Image_Height 282
#define Cloud_1_Image_Width  512

#define Cloud_2_Height 391
#define Cloud_2_Width 512
#define Cloud_2_Image_Height 391
#define Cloud_2_Image_Width  512

#define Cloud_3_Height 512
#define Cloud_3_Width 282
#define Cloud_3_Image_Height 512
#define Cloud_3_Image_Width  282

#define Cloud_4_Height 512
#define Cloud_4_Width 391
#define Cloud_4_Image_Height 512
#define Cloud_4_Image_Width 391 

#define Cloud_5_Height 64
#define Cloud_5_Width 64
#define Cloud_5_Image_Height 64
#define Cloud_5_Image_Width  64


class Cloud :public GameObject
{
protected:
	int op_; //
	double y_;
	double speed_;
public:
	Cloud(int h,int w,Point p,int op);
	~Cloud();
	void Draw(CDC *cDC);
	void Move();
	 
	//get
	double RollSpeed();
};