#pragma once
#include "stdafx.h"

class Image:public CImage
{
public:
	//成员变量
	int height_;
	int width_;
	int column_;
	int row_;
public:
	Image();
	Image(int h, int w, int c = 1, int r = 1);
	~Image();
public:
	//get
	int Height();
	int Width();
	int Column();
	int Row();

public:
	//set
	void Height(int x);
	void Width(int x);
	void Column(int x);
	void Row(int x);
public:
	//function
	void Load_Image(LPSTREAM pStream);
};