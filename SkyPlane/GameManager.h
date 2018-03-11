#pragma once
#include "Factory.h"
#include "GameState.h"
#include "FlyObject.h"
#include "Music.h"
#include <utility>

enum Move
{
	Up,Down,Left,Right,Stay
};

class GameManager
{
private:
	Factory factory_;
	GameState state_;
	Music music_;

private:
	static int GetKey(int nVirtKey);
	static int Rand(int a, int b);
	void Produce(CString ID, Point p, int weaponID, CList<GameObject*, GameObject*>* List,CString name);
	void Play(CString ID);
	CList<GameObject*, GameObject*>* GetList(int i);
	Player* GetPlayer();
	int PlayerHP();
	int PlayerScore();
	int PlayerStars();
public:
	GameManager();
	~GameManager();
	void InitGame();
	void Draw_Text(CDC *cDC, CString content, Point pos);
	void Draw_Text(CDC* cDC, CString content, int value, Point pos);
	void Draw(CDC *cDC);
	void AI();
	void MovePlane(Move move);
	void CheckKey();

	//碰撞检测
	void CheckCollision();
	void Collision(FlyObject* objectA, FlyObject* objectB);

	//垃圾收集器
	void TrashRecycle();


	/*游戏物体控制*/
	void MoveIt();
	void Fire();

	/*游戏状态控制*/
	void StartGame();
	void PauseGame();
	void ResumeGame();
	void OverGame();
	void OnGod();
	void OffGod();

	/*游戏状态查询*/
	BOOL GameStart();
	BOOL GamePause();
	BOOL God();
	BOOL GameOver();

};