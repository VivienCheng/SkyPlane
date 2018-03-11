#pragma once
#include "EnemyPlane.h"
#include "EnemyPrimaryPlane.h"
#include "Resource.h"

EnemyPrimaryPlane::EnemyPrimaryPlane(int h,int w,Point p):EnemyPlane(h,w, p)
{
	DetailedName(_T("EnemyPrimaryPlane"));
}
EnemyPrimaryPlane::~EnemyPrimaryPlane() {}


BOOL EnemyPrimaryPlane::FireStatus()
{ 
	return FALSE; 
}

