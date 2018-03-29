#include "Enemy.h"


Enemy::Enemy(string name, char tile, int level, int attack, int defence, int health, int experience, int attackRange)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defence = defence;
	_health = health;
	_experience = experience;
	_attackDist = attackRange;
}

void Enemy::SetPosition(int x, int y)
{
	_x = x; _y = y;
}

void Enemy::GetPosition(int &x, int &y)
{
	x = _x; y = _y;
}

char Enemy::GetTile()
{
	return _tile;
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

char Enemy::GetMove(int playerX, int playerY)
{
	static default_random_engine randEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);
	int distance;
	int dx = _x - playerX, dy = _y - playerY;
	int adx(abs(dx)), ady(abs(dy));
	distance = adx + ady;
	if (distance <= _attackDist)
	{
		if (adx > ady)
		{
			if (dx > 0)
				return 'a';
			else
				return 'd';
		}
		else
		{
			if (dy > 0)
				return 'w';
			else
				return 's';
		}
	}
	int randomMove = moveRoll(randEngine);
	switch (randomMove)
	{
	case 0: return 'w';
	case 1: return 'a';
	case 2: return 's';
	case 3: return 'd';
	default: return '.';
	}
}
