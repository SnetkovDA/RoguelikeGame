#include "GameSystem.h"

//Loading level
GameSystem::GameSystem(string levelFile)
{
	_player.Init(1, 100, 10, 1, 0);
	_level.LoadLevel(levelFile, _player);
	_level.PrintLevel();
	
}

void GameSystem::PlayGame()
{
	bool isDone = false;
	while (isDone != true)
	{
		_level.PrintLevel();
		PlayerMove();
		_level.UpdateEnemies(_player);
	}
}

void GameSystem::PlayerMove()
{
	char input;
	printf("Enter a move command (w/a/s/d)");
	input = _getch();
	_level.MovePlayer(input, _player);
}