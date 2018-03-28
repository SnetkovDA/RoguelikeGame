#pragma once
#include <random>
#include <ctime>
using namespace std;

class Player
{

public:
	Player();
	void Init(int level, int health, int attack, int defence, int experience);
	//Setters
	void SetPosition(int x, int y);

	//Getters
	void GetPosition(int &x, int &y);

	int Attack();

	void AddExperience(int experience);

	int TakeDamage(int damage);

private:
	//Properties
	int _level;
	int _health;
	int _attack;
	int _defence;
	int _experience;
	//Position
	int _x;
	int _y;
};