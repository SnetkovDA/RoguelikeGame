#include "Enemy.h"


Enemy::Enemy(string name, char tile, int level, int attack, int defence, int health, int experience, int x , int y)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defence = defence;
	_health = health;
	_experience = experience;
	_x = x;
	_y = y;
}

void Enemy::SetPosition(int x, int y)
{
	_x = x; _y = y;
}

void Enemy::GetPosition(int &x, int &y)
{
	x = _x; y = _y;
}

string Enemy::GetName()
{
	return _name;
}

int Enemy::Attack()
{
	static default_random_engine randEng(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);
	return attackRoll(randEng);
}

int Enemy::TakeDamage(int damage)
{
	damage -= _defence;
	if (damage > 0)
	{
		_health -= damage;
		if (_health <= 0)
			return _experience;
	}
	return 0;
}
