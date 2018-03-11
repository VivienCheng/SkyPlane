#include "GameObject.h"
#include "Tool.h"
#include "Plane.h"
#include "Player.h"
#include "Heart.h"
#include "resource.h"

Heart::Heart(Point m,CString name) :Tool(Heart_Height, Heart_Width, m,name)
{
	Group(6);
	toolPos_.SetPoint(m);
	DetailedName("Heart");
	Load_Image(heart, Heart_Image_Height, Heart_Image_Width, Heart_Image_Column, Heart_Image_Row);
}
Heart::~Heart() {}

int Heart::AddMark()
{
	return Add_HP;
}