#pragma once
#include <afxwin.h>
#include <atlimage.h>
#include "Point.h"
#include "Image.h"

class GameObject
{
protected:
	//以下是图片的属性
	Image ima_;
	int indexColumn_;
	int indexRow_;
	BOOL loop_; //是否循环播放动画
	int counter_;//定时器
	int delayer_;//延时器

	//以下是物体的属性
	int height_;
	int width_;
	Point position_;
	BOOL killed_;

public:
	GameObject();
	GameObject(int height, int width, Point p);
	~GameObject();
public:
	//function
	static void TransparentPNG(CImage *png);
	BOOL LoadImageFromResource(UINT nResID, LPCTSTR lpTyp);
	void Load_Image(UINT nResID, int image_Height, int image_Width, int image_Column=1, int image_Row=1, LPCTSTR lpTyp=_T("PNG"));
	virtual void Draw(CDC *cDC);
	virtual void DelayerCount();
public:
	//get
	double X();
	double Y();
	Image* Ima();
	Point* Position();
	int Height();
	int Width();
	int IndexColumn();
	int IndexRow();
	BOOL Kill();
	int Delayer();
	int Counter();
	BOOL Loop();
	int Index();
public:
	//set
	/*
	void Position(CPoint &a);
	void Position(int x,int y);
	void Position(double x, double y);
	*/
	void Height(int x);
	void Width(int x);
	void IndexColumn(int x);
	void IndexRow(int x);
	void Killed();
	void Delayer(int x);
	void Counter(int x);
	void Loop(BOOL x);
	void Index(int x);
	void Index(int x, int y);
public:
	//add
	void AddCounter();
	void AddIndexColumn();
	void AddIndexRow();
	void AddIndex();

	//sub
	void ClearCounter();
	void SubIndexColumn();
	void SubIndexRow();
	void SubIndex();

	//funciton
	void MoveX(int x);
	void MoveY(int y);
	void MoveX(double x);
	void MoveY(double y);
	void SetX(int x);
	void SetY(int y);
	void SetX(double x);
	void SetY(double y);
	void JudgeKill();
};