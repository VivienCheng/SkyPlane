#include "GameObject.h"
#include "Tool.h"
#include "Plane.h"
#include "Player.h"
#include "Wing.h"
#include "resource.h"

Wing::Wing(Point m, CString name) :Tool(Wing_Height, Wing_Width, m, name)
{
	Group(7);
	toolPos_.SetPoint(m);
	DetailedName("Wing");
	Load_Image(icon, Wing_Image_Height, Wing_Image_Width, Wing_Image_Column, Wing_Image_Row);
}
Wing::~Wing() {}

int Wing::AddMark()
{
	return Add_Speed;
}