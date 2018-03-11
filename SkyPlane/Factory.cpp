#pragma once
#include "GameObject.h"
#include "Background.h"
#include "Player.h"
#include "TrackBomb.h"
#include "TankBomb.h"
#include "EnemySimpleBomb.h."
#include "PlayerMainGun.h"
#include "EnemyRedPlane.h"
#include "EnemyBluePlane.h"
#include "EnemyYellowPlane.h"
#include "PropellerPlane.h"
#include "Tank.h"
#include "Heart.h"
#include "Wing.h"
#include "Cloud.h"
#include "Box.h"
#include "Angela.h"
#include "Explosion.h"
#include "PlayerWingGun.h"
#include "PlayerTrackBomb.h"
#include "Factory.h"
#include "Tool.h"
#include "Star.h"
#include "BossLeft.h"
#include "BossMid.h"
#include "BossRight.h"
Factory::Factory()
{
	num = 0;
	tw = 0;
	flag = FALSE;
}
Factory::~Factory() {}


int Factory::Rand(int a, int b) { return (rand() %(b - a + 1)) + a; }
CList<GameObject*, GameObject*>* Factory::GetList(int i)
{
	return objectList + i;
}
Player* Factory::GetPlayer()
{
	return static_cast<Player*>(objectList[Index_Player].GetHead());
}


void Factory::ProduceObject(CString Name, Point p, int ID, CList<GameObject*, GameObject*>* List,CString name = "")
{
	if (Name == "Background")
	{
		ProduceBackground();
	}
	else if (Name == "Player")
	{
		ProducePlayer();
	}
	else if (Name == "Enemy")
	{
		ProduceEnemy();
	}
	else if (Name == "Explosion")
	{
		ProduceExplosion(p);
	}
	else if (Name == "Weapon")
	{
		ProduceWeapon(ID, p,List);
	}
	else if (Name == "Tool")
	{
		ProduceTool(ID,p,name);
	}
	else if (Name == "Cloud")
	{
		ProduceCloud();
	} 
	else if (Name == "Angela")
	{
		if (GetPlayer()->Stars() >= 150 && flag == FALSE)
		{
			flag = TRUE;
			ProduceWinGun(p);
		}
	}
}
void Factory::ProduceBackground()
{
	objectList[Index_Background].AddHead(new Background);
}
void Factory::ProducePlayer()
{
	objectList[Index_Player].AddHead(new Player);
}
void Factory::ProduceWinGun(Point p)
{
	objectList[Index_Angela].AddHead(new Angela(Point(GetPlayer()->X() - 50, GetPlayer()->Y()), 1));
	objectList[Index_Angela].AddHead(new Angela(Point(GetPlayer()->X() + 50, GetPlayer()->Y()), 2));
}

void Factory::ProduceWeapon(int ID,Point p, CList<GameObject*, GameObject*>* List)
{
	switch (ID)
	{
	case 1:  objectList[Index_Bomb].AddTail(new PlayerMainGun(p)); break;
	case 2:  objectList[Index_Bomb].AddTail(new TankBomb(p, *(GetPlayer()->Position()))); break; 
	case 3:  objectList[Index_Bomb].AddTail(new TrackBomb(p, *(GetPlayer()->Position()))); break;
	case 10: objectList[Index_Bomb].AddTail(new PlayerWingGun(p)); break;
	case 11: objectList[Index_Bomb].AddTail(new PlayerTrackBomb(p, List)); break;

	}
}
void Factory::ProduceTool(int ID, Point p,CString name)
{
	switch (ID)
	{
	case 5: objectList[Index_Tool].AddTail(new Star(p,name)); break;
	case 6: objectList[Index_Tool].AddTail(new Heart(p,name)); break;
	case 7: objectList[Index_Tool].AddTail(new Wing(p, name)); break;
	}
}
void Factory::ProduceEnemy()
{
	num++;
	if (num >= 53 && num <= 211)
	{
		if(num == 53 || num == 83 || num == 127 || num == 167 || num == 211 )
			objectList[Index_Enemy].AddTail(new EnemyRedPlane(1, Point(Game_Width / 3 * 2, 0)));  
	}
	else if (num >= 257 && num < 479)
	{
		if (num == 257 || num == 293 || num == 331 || num == 379 || num == 419)
		objectList[Index_Enemy].AddTail(new EnemyRedPlane(1, Point(Game_Width / 3 , 0)));
	}

	else if (num >= 503 && num < 720)
	{
		if ( num == 541 || num == 587 || num == 631 || num == 677 || num == 717)
		objectList[Index_Enemy].AddTail(new EnemyBluePlane(1, Point(0, Game_Height / 4)));
	}
	else if (num >= 718 && num < 960)
	{
		if ( num == 797 || num == 839 || num == 877 || num == 917 || num == 957)
			objectList[Index_Enemy].AddTail(new EnemyBluePlane(2, Point(Game_Width, Game_Height / 4)));
	}
	else if (num >= 1100 && num <= 1400)//高级敌机  类似游戏中的螺旋桨飞机
	{
		if(num == 1100)
			objectList[Index_Enemy].AddTail(new Tank(Point(Game_Width / 3 , Game_Height / 8)));
	}
	else if (num >= 1420 && num <= 1680 )
	{
		if ( num == 1429 || num == 1479 || num == 1533 || num == 1583 || num == 1633) {
			objectList[Index_Enemy].AddTail(new EnemyYellowPlane(9, Point(0, Game_Height / 8)));
			objectList[Index_Enemy].AddTail(new EnemyYellowPlane(10, Point(Game_Width, Game_Height / 8)));
		}
	}
	else if (num >= 1700 && num < 1709)
	{
		if (num == 1700) 
			objectList[Index_Enemy].AddTail(new Tank(Point(Game_Width / 3 * 2, Game_Height / 8)));	
	}

	else if (num >= 2570 && num < 3000)
	{
		if ( num == 2589 || num == 2663 || num == 2741 || num == 2819 || num == 2879 )
		{
			objectList[Index_Enemy].AddTail(new EnemyYellowPlane(4, Point(0, Game_Height / 4)));
			objectList[Index_Enemy].AddTail(new EnemyYellowPlane(5, Point(Game_Width, Game_Height / 4)));
		}
	}

	else if (num >= 3531 && num < 3900) 
	{
		if (num == 3533 || num == 3633 || num == 3733 || num == 3833) 
		{
			objectList[Index_Enemy].AddTail(new PropellerPlane(2, Point(Game_Width / 5 * 4, 0)));
		}
	}
	else if (num >= 3933 && num < 4200)
	{
		if (num == 3973 || num == 4023 || num == 4073 || num == 4123 )
		{
			objectList[Index_Enemy].AddTail(new EnemyRedPlane(2, Point(Game_Width / 3 * 2, Game_Height)));
			objectList[Index_Enemy].AddTail(new EnemyRedPlane(2, Point(Game_Width / 3, Game_Height)));
		}
	}
	else if (num >= 4300 && num <= 4520)
	{
		if ( num == 4317 || num == 4363 || num == 4413 || num == 4463 || num == 4513)
		{
			objectList[Index_Enemy].AddTail(new EnemyBluePlane(1, Point(0, Game_Height / 5)));
			objectList[Index_Enemy].AddTail(new EnemyBluePlane(1, Point(0, Game_Height / 5 + 100)));
		}
	}
	else if (num >= 4613 && num <= 4901)
	{
		if (num == 4613)
		{
			objectList[Index_Enemy].AddTail(new Box(Point(Game_Width / 3, Game_Height / 4)));
			objectList[Index_Enemy].AddTail(new Box(Point(Game_Width / 3 - 50, Game_Height / 4 + 50)));
			objectList[Index_Enemy].AddTail(new Box(Point(Game_Width / 3 + 50, Game_Height / 4 + 50)));
			objectList[Index_Enemy].AddTail(new Box(Point(Game_Width / 3, Game_Height / 4 + 100)));
		}
	}
	else if (num >= 5213 && num < 5600)
	{
		if( num == 5213 || num == 5313 ||num == 5413 || num == 5513)
		objectList[Index_Enemy].AddTail(new PropellerPlane(2, Point(Game_Width , Game_Height / 4)));
	}

	else if (num >= 5800 && num < 7000)
	{
		if (num == 5800)
		{
			objectList[Index_Enemy].AddTail(new BossLeft(Point(20, 0)));
			objectList[Index_Enemy].AddTail(new BossMid(Point(20+81 , 0)));
			objectList[Index_Enemy].AddTail(new BossRight(Point(20 + 81 + 223, 0)));
		}
	}
	else if (num == 7000)
	{
		num = 0;
	}


}
void Factory::ProduceExplosion(Point p)
{
 	objectList[Index_Explosion].AddTail(new Explosion(p));
}

void Factory::ProduceCloud()
{
	tw++;
	if (tw == 50) {
		objectList[Index_Cloud].AddTail(new Cloud(391, 512, Point(-100, -512),2));
	}
	else if (tw == 800)
	{
		objectList[Index_Cloud].AddTail(new Cloud(282, 512, Point(Game_Width / 3, -512), 1));
	}
	else if (tw == 2100)
	{
		objectList[Index_Cloud].AddTail(new Cloud(512, 282, Point(-80, -512), 3));
	}
	else if (tw == 4600)
	{
		objectList[Index_Cloud].AddTail(new Cloud(512, 391, Point(Game_Width, -512), 4));
	}
	if (tw == 6000)
	{
		tw = 0;
	}
}