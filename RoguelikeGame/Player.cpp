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