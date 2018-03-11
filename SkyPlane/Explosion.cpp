#pragma once
#include "GameObject.h"
#include "Explosion.h"
#include "Point.h"

Explosion::Explosion(Point p):GameObject(Exploision_Height, Explosion_Width,p)
{
	Delayer(Delayer_Num);
	Load_Image(explosion_1,Image_Height, Image_Width, Image_Column,Image_Row);
}
Explosion::~Explosion() {};