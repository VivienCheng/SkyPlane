#pragma once
#include "Image.h"


//成员变量
Image::Image():height_(0),width_(0),column_(0),row_(0) {}
Image::Image(int h,int w,int c,int r):height_(h),width_(w),column_(c),row_(r){}
Image::~Image() {}

//get
int Image::Height() {return height_;}
int Image::Width() {return width_;}
int Image::Column() { return column_; }
int Image::Row() { return row_; }
//set
void Image::Height(int x) { height_ = x; }
void Image::Width(int x) { width_ = x; }
void Image::Column(int x) { column_ = x; }
void Image::Row(int x) { row_ = x; }
//function
void Image::Load_Image(LPSTREAM pStream)
{
	Load(pStream);
}