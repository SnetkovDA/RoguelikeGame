#pragma once
#include <string>
#include <conio.h>
#include "Player.h"
#include "Level.h"
#include "Enemy.h"

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
	vector<Enemy> _enemies;
};