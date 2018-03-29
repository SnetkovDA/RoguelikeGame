#pragma once
#include <string>
#include <random>
#include <ctime>
#include "Player.h"

using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level, int attack, int defence, int health, int experience, int attackDist);
	void SetPosition(int x, int y);
	void GetPosition(int &x, int &y);
	char GetTile();
	string GetName();
	int Attack();
	int TakeDamage(int damage);//returns experience points
	char GetMove(int playerX, int playerY); //Gets AI move command

private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defence;
	int _health;
	int _experience;
	int _attackDist;
	//position
	int _x;
	int _y;
};

