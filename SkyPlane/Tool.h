#pragma once
#include "FlyObject.h"
#include "Player.h"
#include "Plane.h"
#include "Point.h"

#define Tool_Init_Speed 0.6

class Tool :public FlyObject
{
protected:
	Point toolPos_;
	CString enemyName_;
	CString detailedName_;
public:
	Tool(int h,int w,Point m,CString name);
	~Tool();		
	virtual int AddMark() = 0;
	void DestroyTool();
	CString EnemyName();
	void DetailedName(CString s);
	CString DetailedName();
};