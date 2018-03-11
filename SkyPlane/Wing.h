#pragma once
#include "Tool.h"
#include "Plane.h"
#include "Player.h"



#define Wing_Height 20.6
#define Wing_Width  24
#define Wing_Image_Height 31
#define Wing_Image_Width  36
#define Wing_Image_Row 1
#define Wing_Image_Column 1
#define Add_Speed 0.25
#define Wing_Init_Speed 0.6

class Wing :public Tool
{
public:
	Wing(Point m, CString name);
	~Wing();
	int AddMark();
};