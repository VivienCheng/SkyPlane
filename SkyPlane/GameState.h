#pragma once
#include<Windows.h>
#include<bemapiset.h>

class GameState
{
protected:
	BOOL gameStart_;
	BOOL gameEnd_;
	BOOL gamePause_;
	BOOL gameOver_;
	BOOL godMode_;
	int score_;
public:
	GameState();
	~GameState();

public:
	/*��Ϸ���ƺ���*/
	void StartGame();
	void EndGame();
	void PauseGame();
	void ResumeGame();
	void OverGame();
	void OnGod();
	void OffGod();

public:
	/*��Ϸ״̬��ѯ*/
	BOOL GameStart();
	BOOL GameEnd();
	BOOL GamePause();
	BOOL God();
	BOOL GameOver();
	int Score();
};