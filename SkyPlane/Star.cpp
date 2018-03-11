#include "GameObject.h"
#include "Tool.h"
#include "Plane.h"
#include "Player.h"
#include "Star.h"
#include "resource.h"

Star::Star(Point m,CString name):Tool(Star_Height,Star_Width,m,name)
{
	Group(5);
	toolPos_.SetPoint(m);
	DetailedName("Star");
	Load_Image(star, Star_Image_Height, Star_Image_Width, Star_Image_Column, Star_Image_Row);
}
Star::~Star(){}

int Star::AddMark()
{
	return Star_Num;
}