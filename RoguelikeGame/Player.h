#pragma once
#include <conio.h>
#include <random>
#include <ctime>
using namespace std;

class Player
{

public:
	Player();
	void StartupDialog();
	void Init(int level, int health, int attack, int defence, int experience);
	//Setters
	void SetPosition(int x, int y);

	//Getters
	void GetPosition(int &x, int &y);

	int Attack();

	void AddExperience(int experience);

	int TakeDamage(int damage);
	int GetHealth() { return _health; }
	int GetExperience() { return _experience; }
	int GetLevel() { return _level; }
	int GetAttack() { return _attack; }
	int GetDefence() { return _defence; }
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