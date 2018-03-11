#include "Cloud.h"
#include "GameObject.h"
#include "Resource.h"
#include "Point.h"
#include "SlantFly.h"


Cloud::Cloud(int h  , int w , Point p,int op):GameObject(h, w, p),op_(op)
{
	switch (op_)
	{
	case 1:Load_Image(cloud_1, Cloud_1_Height, Cloud_1_Width); break;
	case 2:Load_Image(cloud_2, Cloud_2_Height, Cloud_2_Width); break;
	case 3:Load_Image(cloud_3, Cloud_3_Height, Cloud_3_Width); break;
	case 4:Load_Image(cloud_4, Cloud_4_Height, Cloud_4_Width); break;
	case 5:Load_Image(cloud_5, Cloud_5_Height, Cloud_5_Width); break;
	}
	speed_ = Init_Speed;
	y_ = 0;
}
Cloud::~Cloud() {};

void Cloud::Draw(CDC *cDC)
{
	Ima()->Draw(*cDC, X(), Y(), Width(), Height(), indexColumn_ * Ima()->Width(), indexRow_ * Ima()->Height(), Ima()->Width(), Ima()->Height());
	//如果延时器阈值为初始值0，则说明图片只有一张
	if (delayer_ != 0) {
		DelayerCount();
	}
	Move();
}
void Cloud::Move()
{
	MoveY(RollSpeed());
	if (Y() < 0)
	{
		MoveY(RollSpeed());
	}
	if (Y() >= Game_Height)
	{
		Killed();
	}
}
double Cloud::RollSpeed() { return speed_; }