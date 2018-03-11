#pragma once
#include "Background.h"
#include "GameObject.h"
#include "Resource.h"
#include "Point.h"

Background::Background():GameObject(Background_Height, Background_Width,Point(0,0))
{
	delayer_ = 4;
	counter_ = 0;
	y_ = 0;
	rollSpeed_ = Init_Roll_Speed;
	Load_Image(back_ground, Background_Image_Height, Background_Image_Width);
}
Background::Background(int h, int w, Point p):GameObject(h,w,p)
{
	Load_Image(back_ground, Background_Image_Width, Background_Image_Width);
}

Background::~Background() {}

//function
void Background::MoveImage()
{
	MoveY(RollSpeed());
	if (Position()->Y() >= Game_Height)
	{
		Position()->Y(0);
	}
}
void Background::Draw(CDC *cDC)
{
	Ima()->Draw(*cDC,0, Position()->Y(), Width(), Height());
	Ima()->Draw(*cDC,0,Position()->Y() - Height(),Width(),Height());
	MoveImage();
}

//set
void Background::RollSpeed(double x) { rollSpeed_ = x; }

//get	
double Background::RollSpeed() { return rollSpeed_; };