#include "Box.h"
#include "EnemyPrimaryPlane.h"
#include "Point.h"
#include "FlyNoWay.h"
#include "Resource.h"

Box::Box(Point p):EnemyPrimaryPlane(Box_Height, Box_Width, p)
{
	HP(Box_Init_HP);
	Speed(Box_Init_Speed);
	Load_Image(box, Box_Image_Height, Box_Image_Width);
	DetailedName("Box");
	flyBehavior_ = new FlyNoWay(*(Position()));
}
Box::~Box() {}
