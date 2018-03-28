#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level, int attack, int defence, int health, int experience);
private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defence;
	int _health;
	int _experience;
};

