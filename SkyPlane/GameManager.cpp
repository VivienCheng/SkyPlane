#pragma once
#include "Factory.h"
#include "GameState.h"
#include "FlyObject.h"
#include "SlantFly.h"
#include "GameManager.h"
#include "Tool.h"
#include "Point.h"
#include "Star.h"
#include "Music.h"
#include "FlyNoWay.h"


int GameManager::GetKey(int nVirtKey) 
{
	int ans = (GetKeyState(nVirtKey) & 0x8000) ? 1 : 0;
	return ans;
}

int  GameManager::Rand(int a, int b) 
{
	return (rand() % (b - a + 1)) + a;
}

void GameManager::Produce(CString ID, Point p = Point(0, 0), int weaponID = 1, CList<GameObject*, GameObject*>* List = NULL,CString name = "")
{
	if (ID == "Explosion")
	{
		Play(_T("WAV_Explosion_Small"));
	}
	factory_.ProduceObject(ID, p, weaponID, List,name);
}
void GameManager::Play(CString ID)
{
	music_.Play(ID);
}

//get
CList<GameObject*, GameObject*>* GameManager::GetList(int i)
{
	return factory_.GetList(i);
}
Player* GameManager::GetPlayer()
{
	return factory_.GetPlayer();
}
int GameManager::PlayerHP()
{
	return factory_.GetPlayer()->HP();
}
int GameManager::PlayerStars()
{
	return factory_.GetPlayer()->Stars();
}
int GameManager::PlayerScore()
{
	return state_.Score();
}

GameManager::GameManager()
{
	srand(static_cast<unsigned>(time(nullptr)));
}
GameManager::~GameManager(){}


void GameManager::InitGame()
{
	Produce(_T("Background"));
	Produce(_T("Player"));
	Play(_T("BGM"));
}
void GameManager::Draw_Text(CDC *cDC, CString content, Point pos)
{
	cDC->SetBkMode(TRANSPARENT);
	cDC->SetTextAlign(TA_CENTER);
	cDC->SetTextColor(RGB(255, 0, 0));

	CString Out;
	Out.Format(content);
	cDC->TextOut(pos.x_, pos.y_, Out);
}
void GameManager::Draw_Text(CDC* cDC, CString content, int value, Point pos)
{
	cDC->SetBkMode(TRANSPARENT);
	cDC->SetTextAlign(TA_CENTER);
	cDC->SetTextColor(RGB(255, 0, 0));

	CString Out;
	Out.Format(content + " : %d", value);
	cDC->TextOut(pos.x_, pos.y_, Out);
}
void GameManager::Draw(CDC *cDC)
{
	if (GameStart())
	{
		if (GamePause() == TRUE)
		{
			Draw_Text(cDC, _T("按下回车恢复游戏"), Point(Game_Width / 2, Game_Height / 2));
		}
		else if (GameOver() == TRUE) {
			Draw_Text(cDC, _T("游戏结束"), Point(Game_Width / 2, Game_Height / 2));
		}
		else
		{
			for (int i = Index_Background; i <= Index_Angela; ++i) //Index_Cloud
			{
				CList<GameObject*, GameObject*> *now = GetList(i);
				POSITION pos = now->GetHeadPosition();
				while (pos != NULL)
				{
					now->GetNext(pos)->Draw(cDC);
				}
			}
			if (God()) {
				Draw_Text(cDC, _T("无敌模式已开启,按下F键关闭"), Point(110, 50));
			}
			else {
				Draw_Text(cDC, _T("无敌模式未开启，按下G键开启"), Point(118, 50));
			}
			Draw_Text(cDC, _T("生命值"), PlayerHP(), Point(60, 10));
			Draw_Text(cDC, _T("星星值"), PlayerStars(), Point(48, 30));

		}
	}
	else {

		Draw_Text(cDC,_T("按下回车键开始游戏"),Point(Game_Width/2, Game_Height/2));
	}
}
void GameManager::AI()
{
	CheckKey();
	if (GameStart() && !GamePause() && !GameOver())
	{
		Produce(_T("Enemy"));
		Produce(_T("Cloud"));
		Produce(_T("Angela"));
		CheckCollision();
		MoveIt();
		Fire();
		TrashRecycle();
	}
}
void GameManager::MovePlane(Move move)
{
	switch (move)
	{
	case Up:    GetPlayer()->MoveToTop(); break;
	case Down:  GetPlayer()->MoveToBottom(); break;
	case Left:  GetPlayer()->MoveToLeft(); break;
	case Right: GetPlayer()->MoveToRight(); break;
	case Stay:  GetPlayer()->LoadForwardImage(); break;
	}
}
void GameManager::CheckKey()
{
	if (GameStart() && !GamePause() && !GameOver() )
	{
		if (GetKey('w') || GetKey('W') || GetKey(VK_UP)) { MovePlane(Up); }
		if (GetKey('s') || GetKey('S') || GetKey(VK_DOWN)) { MovePlane(Down); }
		if (GetKey('a') || GetKey('A') || GetKey(VK_LEFT)) { MovePlane(Left); }
		if (GetKey('d') || GetKey('D') || GetKey(VK_RIGHT)) { MovePlane(Right); }
		if (!(GetKey('a') || GetKey('A') || GetKey(VK_LEFT)) && !(GetKey('d') || GetKey('D') || GetKey(VK_RIGHT)) ) { MovePlane(Stay); }

		//功能检测
		if (GetKey('G') || GetKey('g'))
		{
			OnGod();
		}

		if (GetKey('F') || GetKey('f'))
		{
			OffGod();
		}

		if (GameManager::GetKey(VK_SPACE))//!GetPlayer()->Kill()
		{
			Player* p = GetPlayer();
			if (p->FireStatus())
			{
				Play(_T("Player_Shot"));
				Produce(_T("Weapon"), Point(p->X() + p->Width() / 2 - 3, p->Y() - 4), p->WeaponID());
			}
		}

		if (GetKey('Q') || GetKey('q'))
		{
			Player* p = GetPlayer();
			if (p->FireStatus())
			{
				Produce(_T("Weapon"), Point(p->X() + p->Width() / 2 - 3, p->Y() - 4),11, GetList(Index_Enemy));
			}
		}
		if (GetKey('Z') || GetKey('z'))
		{
			CList<GameObject*, GameObject*> *now = GetList(Index_Angela);
			POSITION pos = now->GetHeadPosition();
			while (pos != NULL)
			{
				Angela* angela_ = static_cast<Angela*>(now->GetNext(pos));
				if (angela_->Op() == 1) {
					angela_->SetX(GetPlayer()->X() - 80);
					angela_->SetY(GetPlayer()->Y());
					angela_->Op(3, angela_->Position(), GetPlayer()->Position(), GetPlayer()->SpeedX(), GetPlayer()->SpeedY());
				}
				else if (angela_->Op() == 2)
				{
					angela_->SetX(GetPlayer()->X() + 80);
					angela_->SetY(GetPlayer()->Y());
					angela_->Op(3, angela_->Position(), GetPlayer()->Position(), GetPlayer()->SpeedX(), GetPlayer()->SpeedY());
				}
				
			}
		}
		if (GetKey('X') || GetKey('x'))
		{
			CList<GameObject*, GameObject*> *now = GetList(Index_Angela);
			POSITION pos = now->GetHeadPosition();
			while (pos != NULL)
			{
				Angela* angela_ = static_cast<Angela*>(now->GetNext(pos));
				if (angela_->Op() == 1) 
				{
					angela_->Op(1,  angela_->Position(), GetPlayer()->Position(), 0,0);
				}
				else if (angela_->Op() == 2)
				{
					angela_->Op(2,  angela_->Position(), GetPlayer()->Position(), 0,0);
				}
				

			}
		}
		if (GameManager::GetKey(VK_ESCAPE))
		{
			PauseGame();
		}
	}

	if (GameManager::GetKey(VK_RETURN))
	{
		if (GameStart() && GamePause() )
		{
			ResumeGame();
		}
		else if(!GameStart())
		{
			StartGame();
			Play(_T("Mission_Begin"));
		}
	}
}

//碰撞检测
void GameManager::CheckCollision()
{
	for (int i = Index_Player; i <= Index_Tool; ++i)//Index_Bomb
	{
		if (i == Index_Explosion)continue;
		CList<GameObject*, GameObject*> *listA = GetList(i);
		POSITION posA = listA->GetHeadPosition();
		while (posA != NULL)
		{
			FlyObject* objectA = static_cast<FlyObject*>(listA->GetAt(posA));
			for (int j = Index_Player; j <=  Index_Tool; ++j)//Index_Bomb
			{
				if (j == Index_Explosion)continue;
				CList<GameObject*, GameObject*> *listB = GetList(j);
				POSITION posB = listB->GetHeadPosition();
				while (posB != NULL)
				{
					FlyObject* objectB = static_cast<FlyObject*>(listB->GetAt(posB));
					//碰撞检测
					if (objectA->Group() == objectB->Group())
					{
						listB->GetNext(posB);
						continue;
					}
					CPoint leftTop = CPoint(objectA->X() - objectB->Width() / 2, objectA->Y() - objectB->Height() / 2);
					CPoint rightBottom = CPoint(objectA->X() + objectA->Width() + objectB->Width() / 2, objectA->Y() + objectA->Height() + objectB->Height() / 2);
					CPoint objectCenter = CPoint(objectB->X() + objectB->Width()/2, objectB->Position()->Y() + objectB->Height() / 2);
					if (objectCenter.x <= rightBottom.x && objectCenter.y <= rightBottom.y && objectCenter.x >= leftTop.x && objectCenter.y >= leftTop.y)
					{
						Collision(objectA, objectB);
					}
					listB->GetNext(posB);
				}
			}
			listA->GetNext(posA);
		}
	}
}
void GameManager::Collision(FlyObject* objectA, FlyObject* objectB)
{
	int type_ = 0;
	if (objectA->Name() == "Player" || objectB->Name() == "Player")
	{
		if (objectB->Name() == "Player"){
			std::swap(objectA, objectB);
		}
		Player* play = static_cast<Player*>(objectA);

		if (objectB->Name() == "EnemyBomb")
		{
			Weapon *bomb = static_cast<Weapon*>(objectB);
			Produce(_T("Explosion"), Point(objectB->X() + objectB->Width() / 2, objectB->Y() + objectB->Height() / 2));
			if (!God()){ play->SubHP(bomb->Power());}
			if (play->HP() <= 0){
				//play->Killed();
				OverGame();}
			bomb->Killed();
		}
		if (objectB->Name() == "Enemy")
		{
			Plane *enemy = static_cast<Plane *>(objectB);
			if (enemy->DetailedName() == "Box" || enemy->DetailedName() == "BossLeft" || enemy->DetailedName() == "BossMid" || enemy->DetailedName() == "BossRight") return;
			Produce(_T("Explosion"), Point(objectB->X() + objectB->Width() / 2, objectB->Y() + objectB->Height() / 2));

			if (!God()) play->SubHP(1);
			if (play->HP() <= 0) {
				//play->Killed();
				OverGame();
			}

			if (enemy->DetailedName() == "EnemyPrimaryPlane")
			{
				factory_.ProduceTool(5, *(enemy->Position()), enemy->DetailedName());
			}
			else if (enemy->DetailedName() == "PropellerPlane")
			{
				factory_.ProduceTool(6, *(enemy->Position()), enemy->DetailedName());
			}
			else if (enemy->DetailedName() == "Tank")
			{
				factory_.ProduceTool(7, *(enemy->Position()), enemy->DetailedName());
			}
			else if (enemy->DetailedName() == "Box")
			{
				factory_.ProduceTool(Rand(5, 7), *(enemy->Position()), enemy->DetailedName());
			}

			enemy->Killed();

		}
		if (objectB->Name() == "Tool")
		{
			Tool *tool = static_cast<Tool *>(objectB);
			play->AddTool(tool->DetailedName(),tool->EnemyName(),tool->AddMark());
			tool->DestroyTool();
		}
	}
	else if (objectA->Name() == "PlayerBomb" || objectB->Name() == "PlayerBomb")
	{
		if (objectB->Name() == "PlayerBomb")
		{
			std::swap(objectA,objectB);
		}
		Weapon* bomb = static_cast<Weapon*>(objectA);
		
		if (objectB->Name() == "Enemy")
		{
			Plane* enemy = static_cast<Plane*>(objectB);
			bomb->Killed();
			enemy->SubHP(bomb->Power());
			if (enemy->HP() <= 0)
			{
				Produce(_T("Explosion"),Point(objectB->X() + objectB->Width()/2, objectB->Y() + objectB->Height() / 2));
				if (enemy->DetailedName() == "EnemyPrimaryPlane")
				{
					factory_.ProduceTool(5, *(enemy->Position()),enemy->DetailedName());
				}
				else if (enemy->DetailedName() == "PropellerPlane")				
				{
					factory_.ProduceTool(6, *(enemy->Position()), enemy->DetailedName());
				}
				else if (enemy->DetailedName() == "Tank")
				{
					factory_.ProduceTool(7, *(enemy->Position()), enemy->DetailedName());
				}
				else if (enemy->DetailedName() == "Box")
				{
					factory_.ProduceTool(Rand(5,7), *(enemy->Position()), enemy->DetailedName());
				}
				enemy->Killed();
			}

		}
	}
}

//垃圾收集器
void GameManager::TrashRecycle()
{
	for (int i = Index_Background; i <= Index_Angela; ++i)
	{
		CList<GameObject*, GameObject*> * now = GetList(i);
		POSITION pos = now->GetHeadPosition();
		while(pos != NULL)
		{
			GameObject* object = now->GetNext(pos);
			if (object->Kill())
			{
				POSITION del = now->Find(object);
				delete now->GetAt(del);
				now->RemoveAt(del);
			}
		}
	}
}


/*游戏物体控制*/
void GameManager::MoveIt()
{
	for (int i = Index_Enemy; i <= Index_Angela; ++i)//Index_Bomb
	{
		if (i == Index_Explosion || i == Index_Tool || i == Index_Cloud) continue;
		CList<GameObject*, GameObject*> *now = GetList(i);
		POSITION pos = now->GetHeadPosition();

		while (pos != NULL)
		{
			FlyObject* fly = static_cast<FlyObject*>(now->GetNext(pos));
			fly->PerformFly();
		}
	}
}
void GameManager::Fire()
{
	for (int i = Index_Enemy; i <= Index_Angela; i++) {
		if (i == Index_Bomb || i == Index_Explosion || i == Index_Tool || i == Index_Cloud) continue;
		CList<GameObject*, GameObject*> *now = GetList(i);
		POSITION pos = now->GetHeadPosition();
		while (pos != NULL)
		{
			Plane* plane_ = static_cast<Plane*>(now->GetNext(pos));
			if (plane_->FireStatus())
			{
				Produce(_T("Weapon"), Point(plane_->X() + plane_->Width() / 4 + 8, plane_->Y() + plane_->Height() / 4 + 8), plane_->WeaponID());
			}

		}
	}
}

/*游戏状态控制*/
void GameManager::StartGame() { state_.StartGame(); }
void GameManager::PauseGame() { state_.PauseGame(); }
void GameManager::ResumeGame() { state_.ResumeGame(); }
void GameManager::OverGame() { state_.OverGame(); }
void GameManager::OnGod() { state_.OnGod();}
void GameManager::OffGod() { state_.OffGod();}

/*游戏状态查询*/
BOOL GameManager::GameStart() { return state_.GameStart(); }
BOOL GameManager::GamePause() { return state_.GamePause(); }
BOOL GameManager::God() { return state_.God(); }
BOOL GameManager::GameOver() { return state_.GameOver(); }
