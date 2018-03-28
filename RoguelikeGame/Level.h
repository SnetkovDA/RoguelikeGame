#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
public:
	Level();
	void LoadLevel(string fireName, Player &player, vector<Enemy> &enemies);
	void PrintLevel();
	void MovePlayer(char input, Player &player);
	char GetTile(int x, int y);
	void SetTile(int x, int y, char tile);
private:
	void ProcessPlayerMove(Player &player, int targetX, int targetY);
	void BattleMonster(Player &player, int targetX, int targetY);
private:
	vector<string> _levelData;
	string _clearString;
};

