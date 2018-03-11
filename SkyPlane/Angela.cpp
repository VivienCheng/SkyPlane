#include "Point.h"
#include "Resource.h"
#include "Angela.h"
#include "Plane.h"
#include "AimFly.h"
#include "StrangeFly.h"

Angela::Angela(Point p, int op) :Plane(Angela_Height, Angela_Width, p), op_(op)
{
	HP(Angela_Init_HP);
	Delayer(5);
	Loop(TRUE);
	FireOpenTimes(Angela_Fire_Open_Time);
	Group(1);
	WeaponID(Angela_Weapon_ID);
	Speed(Angela_Init_Speed);
	Load_Image(angela, Angela_Image_Height, Angela_Image_Width, Angela_Image_Column, Angela_Image_Row);
	if (op_ == 1)
	{
		flyBehavior_ = new StrangeFly(*(Position()), SpeedX(), SpeedY(), op_, Angela_Image_Height);
	}
	else if (op_ == 2)
	{
		flyBehavior_ = new StrangeFly(*(Position()), SpeedX(), SpeedY(), op_, Angela_Image_Height);
	}
	fire_ = TRUE;
}

Angela::~Angela() {};
void Angela::PerformFly()
{
	GetFlyBehavior()->Fly();
}
int Angela::Op() { return op_; }

void Angela::Op(int x,Point* p, Point *q, double a,double b)
{
	if (x == 1)
	{
		SetFlyBehavior(new StrangeFly(*p, SpeedX(), SpeedY(), x, Angela_Image_Height));
	}
	else if (x == 2)
	{
		SetFlyBehavior(new StrangeFly(*p, SpeedX(), SpeedY(), x, Angela_Image_Height));
	}
	if (x == 3)
	{
		SetFlyBehavior(new AimFly(*p,q,a,b));
	}
}
