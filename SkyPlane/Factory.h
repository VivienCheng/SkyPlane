#pragma once
#include "GameObject.h"
#include "Cloud.h"
#include "Background.h"
#include "Player.h"
#include "EnemySimpleBomb.h."
#include "EnemyRedPlane.h"
#include "Explosion.h"
#include "Angela.h"

enum Index
{
	Index_Background,
	Index_Player,
	Index_Enemy,
	Index_Bomb,
	Index_Explosion,
	Index_Tool,
	Index_Cloud,
	Index_Angela
};
class Factory
{
protected:
	CList<GameObject*, GameObject*> objectList[8];
	int num;
	int tw;
	BOOL flag;
public:
	Factory();
	~Factory();
public:
	int Rand(int a, int b);
	CList<GameObject*, GameObject*>* GetList(int i);
	Player* GetPlayer();

public:
	void ProduceObject(CString Name, Point p, int ID, CList<GameObject*, GameObject*>* List,CString name);
	void ProduceBackground();
	void ProducePlayer();
	void ProduceWinGun(Point p);
	void ProduceWeapon(int ID, Point p, CList<GameObject*, GameObject*>* List);
	void ProduceEnemy();
	void ProduceCloud();
	void ProduceExplosion(Point p);
	void ProduceTool(int ID, Point p,CString name);
};

