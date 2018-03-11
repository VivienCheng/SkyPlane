#pragma once
#include "Tool.h"
#include "Plane.h"
#include "Player.h"



#define Star_Height 20
#define Star_Width  21
#define Star_Image_Height 60
#define Star_Image_Width  63
#define Star_Image_Row 1
#define Star_Image_Column 1
#define Star_Num 1
#define Star_Init_Speed 0.6

class Star :public Tool
{
public:
	Star(Point m,CString name);
	~Star();
	int AddMark();
};