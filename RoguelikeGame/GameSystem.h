#pragma once
#include <string>
#include <conio.h>
#include "Player.h"
#include "Level.h"

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFile);

	void PlayGame();
	void PlayerMove();
private:
	Level _level;
	Player _player;
};