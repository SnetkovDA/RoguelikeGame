#include "GameSystem.h"

//Loading level
GameSystem::GameSystem(string levelFile)
{
	_player.StartupDialog();
	_level.LoadLevel(levelFile, _player);
	_level.PrintLevel(_player);
	
}

void GameSystem::PlayGame()
{
	bool isDone = false;
	while (isDone != true)
	{
		_level.PrintLevel(_player);
		PlayerMove();
		_level.UpdateEnemies(_player);
	}
}

void GameSystem::PlayerMove()
{
	char input;
	printf("Enter a move command (w/a/s/d):\n");
	input = _getch();
	_level.MovePlayer(input, _player);
}