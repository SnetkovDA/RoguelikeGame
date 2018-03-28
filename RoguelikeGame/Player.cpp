#include "Player.h"

//Constructor sets position to zero
Player::Player()
{
	_x = 0; _y = 0;
}

//Initializes player with properties
void Player::Init(int level, int health, int attack, int defence, int experience)
{
	_level = level; _health = health;
	_attack = attack; _defence = defence;
	_experience = experience;
}

//Set the position of the player
void Player::SetPosition(int x, int y)
{
	_x = x; _y = y;
}

//Gets the position of the player using reference varibles 
void Player::GetPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

int Player::Attack()
{
	static default_random_engine randEng(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);
	return attackRoll(randEng);
}

void Player::AddExperience(int experience)
{
	_experience += experience;
	while (_experience > 50)
	{
		printf("\nLevel up!");
		_experience -= 50;
		_attack += 10;
		_defence += 1;
		_health += 10;
		_level++;
		system("pause");
	}
}

int Player::TakeDamage(int damage)
{
	damage -= _defence;
	if (damage > 0)
	{
		_health -= damage;
		if (_health <= 0)
			return 1;
	}
	return 0;
}
