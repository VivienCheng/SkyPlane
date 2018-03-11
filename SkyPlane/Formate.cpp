#include "Formate.h"
#include "EnemyRedPlane.h"
#include "EnemyBluePlane.h"
#include "EnemyYellowPlane.h"

Formate::Formate(int posID, CString name,Point &p,int x):posID_(posID),planeName_(name),pos_(&p),numOfPlane_(x)
{
	if (planeName_ == _T("EnemyRedPlane"))
	{
		enemyPlane_ = new EnemyRedPlane(p);
	}
	else if (planeName_ == _T("EnemyBluePane"))
	{
		enemyPlane_ = new EnemyBluePlane(p);
	}
	else if (planeName_ == _T("EnemyYellowPane"))
	{
		enemyPlane_ = new EnemyYellowPlane(p);
	}
}
Formate::~Formate() {}
void Formate::FormateFly(int ID)
{
	switch(ID)£º
	case 1:
}