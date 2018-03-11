#pragma once
#include "GameObject.h"
#include "Point.h"
#include "Resource.h"


GameObject::GameObject() 
{
	killed_ = FALSE;
	indexColumn_ = 0;
	indexRow_ = 0;
	loop_ = FALSE;
	delayer_ = 0;
	counter_ = 0;
}

GameObject::GameObject(int height,int width,Point p) :height_(height), width_(width), position_(p)
{
	killed_ = FALSE;
	indexColumn_ = 0;
	indexRow_ = 0;
	loop_ = FALSE;
	delayer_ = 0;
	counter_ = 0;
}

GameObject::~GameObject() {}

//透明特效
void GameObject::TransparentPNG(CImage *png)
{
	if (png->GetBPP() == 32)
	{
		for (int i = 0; i < png->GetWidth(); ++i)
		{
			for (int j = 0; j < png->GetHeight(); ++j)
			{
				unsigned char* pucColor = reinterpret_cast<unsigned char*>(png->GetPixelAddress(i, j));
				pucColor[0] = pucColor[0] * pucColor[3] / 255;
				pucColor[1] = pucColor[1] * pucColor[3] / 255;
				pucColor[2] = pucColor[2] * pucColor[3] / 255;
			}
		}
	}
}

BOOL GameObject::LoadImageFromResource(UINT nResID, LPCTSTR lpTyp)
{
	// 查找资源
	HRSRC hRsrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL) return false;

	// 加载资源
	HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}

	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);

	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);

	// 解除内存中的指定资源
	::GlobalUnlock(hNew);

	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
	if (ht != S_OK)
	{
		GlobalFree(hNew);
	}
	else
	{
		// 加载图片
		ima_.Load_Image(pStream);

		GlobalFree(hNew);
	}
	// 释放资源
	::FreeResource(hImgData);
	return true;
}

void GameObject::Load_Image(UINT nResID, int image_Height, int image_Width, int image_Column, int image_Row , LPCTSTR lpTyp )
{
	ima_.Height(image_Height);
	ima_.Width(image_Width);
	ima_.Column(image_Column);
	ima_.Row(image_Row);

	LoadImageFromResource(nResID, lpTyp);
	if (lpTyp == _T("PNG"))
	{
		TransparentPNG(&ima_);
	}
}

//延时器函数 放慢动画的模仿速度
void GameObject::DelayerCount()
{
	AddCounter();
	if (Counter() >= Delayer()) {
		AddIndexColumn();
		if (IndexColumn() == Ima()->Column())
		{
			IndexColumn(0);
			AddIndexRow();
		}
		if (IndexRow() == Ima()->Row())
		{
			if (Loop()) {
				IndexRow(0);
				IndexColumn(0);
			}
			else Killed();
		}
		ClearCounter();
	}
}
void GameObject::Draw(CDC *cDC)
{
	Ima()->Draw(*cDC, X(), Y(), Width(), Height(),indexColumn_ * Ima()->Width(), indexRow_ * Ima()->Height(),Ima()->Width(),Ima()->Height());
	//如果延时器阈值为初始值0，则说明图片只有一张
	if (delayer_ != 0) {
		DelayerCount();
	}

 }

//get 
double GameObject::X() { return Position()->X(); }
double GameObject::Y() { return Position()->Y(); }
Image* GameObject::Ima() {return &ima_;}
Point* GameObject::Position(){return &position_;}
int GameObject::Height() { return height_; }
int GameObject::Width() { return width_; }
int GameObject::IndexColumn() { return indexColumn_; }
int GameObject::IndexRow() { return indexRow_; }
BOOL GameObject::Kill() { return killed_; }
BOOL GameObject::Loop() { return loop_; }
int GameObject::Delayer() { return delayer_; }
int GameObject::Counter() { return counter_; }
int GameObject::Index()
{
	return IndexRow() * Ima()->Column() + IndexColumn() + 1;
}

//set
void GameObject::Height(int x) { height_ = x; }
void GameObject::Width(int x) { width_ = x; }
void GameObject::IndexColumn(int x) { indexColumn_ = x;}
void GameObject::IndexRow(int x) { indexRow_ = x; }
void GameObject::Counter(int x) { counter_ = x; }
void GameObject::Killed() {	killed_ = TRUE; }
void GameObject::Loop(BOOL x) { loop_ = x; }
void GameObject::Delayer(int x) {  delayer_ = x; }
void GameObject::Index(int x, int y) { indexRow_ = x; indexColumn_ = y; }
void GameObject::Index(int x)
{
	IndexRow(x / Ima()->Column());
	IndexColumn(x % Ima()->Column() - 1);
}

//add
void GameObject::AddCounter() { counter_++; }
void GameObject::AddIndexColumn() { indexColumn_++; }
void GameObject::AddIndexRow() { indexRow_++; }
void GameObject::AddIndex()
{
	AddIndexColumn();
	if (IndexColumn() == Ima()->Column())
	{
		IndexColumn(0);
		AddIndexRow();
	}
	if (IndexRow() == Ima()->Row())
	{
		IndexRow(Ima()->Row() - 1);
		IndexColumn(Ima()->Column() - 1);
	}
}

//sub
void GameObject::ClearCounter() { counter_ = 0; }
void GameObject::SubIndexColumn() { indexColumn_--; }
void GameObject::SubIndexRow() { indexRow_--; }
void GameObject::SubIndex()
{
	SubIndexColumn();
	if (IndexColumn() == -1)
	{
		IndexColumn(Ima()->Column()-1);
		SubIndexRow();
	}
	if (IndexRow() == -1)
	{
		IndexColumn(0);
		IndexRow(0);
	}
}

//function

void GameObject::MoveX(int x) { Position()->x_ = x; }
void GameObject::MoveY(int y) { Position()->y_ = y; }
void GameObject::MoveX(double x) { Position()->x_ += x; }
void GameObject::MoveY(double y) { Position()->y_ += y; }
void GameObject::SetX(int x) { Position()->x_ = x; }
void GameObject::SetY(int y) { Position()->y_ = y; }
void GameObject::SetX(double x) { Position()->x_ = x; }
void GameObject::SetY(double y) { Position()->y_ = y; }
void GameObject::JudgeKill()
{
	if (Position()->X() < 0 || Position()->X() > Game_Width || Position()->Y() < 0 || Position()->Y() > Game_Height)
	{
		killed_ = TRUE;
	}
}