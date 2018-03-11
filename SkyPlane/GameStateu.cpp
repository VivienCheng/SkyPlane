#pragma once
#include "GameState.h"


GameState::GameState()
{
	gameStart_ = FALSE;
	gameEnd_ = FALSE;
	gamePause_ = FALSE;
	gameOver_ = FALSE;
	godMode_ = FALSE;
	score_ = 0;
}
GameState::~GameState() {};


/*游戏控制函数*/
void GameState::StartGame()
{
	 gameStart_ = TRUE;
	 gameEnd_ = FALSE;
	 gamePause_ = FALSE;
	 gameOver_ = FALSE;
	 godMode_ = FALSE;
	 score_ = 0;
}
void GameState::EndGame() { gameEnd_ = TRUE; }
void GameState::PauseGame() { gamePause_ = TRUE;}
void GameState::ResumeGame() { gamePause_ = FALSE; }
void GameState::OverGame() {gameOver_ = TRUE;}
void GameState::OnGod() { godMode_ = TRUE; }
void GameState::OffGod() { godMode_ = FALSE; }


/*游戏状态查询*/
BOOL GameState::GameStart() { return gameStart_; }
BOOL GameState::GameEnd() { return gameEnd_; }
BOOL GameState::GamePause() { return gamePause_; }
BOOL GameState::God() { return godMode_; }
BOOL GameState::GameOver() { return gameOver_; }
int GameState::Score() { return score_; }