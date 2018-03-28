#include "Enemy.h"


Enemy::Enemy(string name, char tile, int level, int attack, int defence, int health, int experience)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defence = defence;
	_health = health;
	_experience = experience;
}
