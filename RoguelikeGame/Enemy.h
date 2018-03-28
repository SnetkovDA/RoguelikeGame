#pragma once
#include <string>
#include <random>
#include <ctime>
using namespace std;

class Enemy
{
public:
	Enemy(string name, char tile, int level, int attack, int defence, int health, int experience, int x , int y);
	void SetPosition(int x, int y);
	void GetPosition(int &x, int &y);
	string GetName();
	int Attack();
	int TakeDamage(int damage);//returns experience points
private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defence;
	int _health;
	int _experience;
	//position
	int _x;
	int _y;
};

