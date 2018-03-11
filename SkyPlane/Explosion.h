#pragma once
#include "GameObject.h"
#include "Resource.h"

#define Exploision_Height 60
#define Explosion_Width  60
#define Image_Height 64
#define Image_Width  64
#define Image_Column 4
#define Image_Row    8
#define Delayer_Num  1

class Explosion:public GameObject
{
public:
	Explosion(Point p);
	~Explosion();
};