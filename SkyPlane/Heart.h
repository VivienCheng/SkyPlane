#pragma once
#include "Tool.h"
#include "Plane.h"
#include "Player.h"



#define Heart_Height 21.5
#define Heart_Width  21.5
#define Heart_Image_Height 64
#define Heart_Image_Width  64
#define Heart_Image_Row 1
#define Heart_Image_Column 1
#define Add_HP 15
#define Heart_Init_Speed 0.6

class Heart :public Tool
{
public:
	Heart(Point m,CString name);
	~Heart();
	int AddMark();
};