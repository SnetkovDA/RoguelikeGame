#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameSystem.h"

using namespace std;

int main()
{
	GameSystem gameSystem("level1.txt");
	gameSystem.PlayGame();

	/*
	char input;
	string clearScreenString (100, '\n');
	while (true)
	{
		input = _getch();
		cout << clearScreenString;
		cout << "You entered: " << input << endl;
	}
	*/
	return 0;
}