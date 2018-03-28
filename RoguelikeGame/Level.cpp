#include "Level.h"

Level::Level()
{
	_clearString = (1000, '\n');
}
//Load file
void Level::LoadLevel(string fileName, Player &player, vector<Enemy> &enemies)
{
	//Load level
	ifstream file;
	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		system("pause");
		exit(1);
	}
	string line;
	while (getline(file, line))
	{
		_levelData.push_back(line);
	}
	file.close();

	//Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++)
	{
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];
			switch (tile)
			{
			case '@':
				player.SetPosition(j, i);
				cout << j << " : " << i;
				break;
			case 'S': //Snake
				enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
				break;
			case 'g':
				enemies.push_back(Enemy("Goblin", tile, 1, 6, 2, 30, 10));
				break;
			case 'O':
				enemies.push_back(Enemy("Ogre", tile, 4, 20, 4, 200, 500));
				break;
			case 'D':
				enemies.push_back(Enemy("Dragon", tile, 10, 2000, 10, 2000, 50000000));
				break;
			default:
				break;
			}
		}
	}
}
//Show level
void Level::PrintLevel()
{
	system("cls");
	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s",_levelData[i].c_str());
		printf("\n");
	}
	printf("\n");
}

char Level::GetTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::SetTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::MovePlayer(char input, Player &player)
{
	int playerX, playerY;
	player.GetPosition(playerX, playerY);
	switch (input)
	{
	case 'w': //up
	case 'W':
		ProcessPlayerMove(player, playerX, playerY - 1);
		break;
	case 's': //down
	case 'S':
		ProcessPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a': //left
	case 'A':
		ProcessPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd': // Right
	case 'D':
		ProcessPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		printf("INVALID INPUT! \n");
		system("pause");
		break;
	}
	
}

void Level::BattleMonster(Player &player, int targetX, int targetY)
{

}

void Level::ProcessPlayerMove(Player &player, int targetX, int targetY)
{
	char movingTile;
	int playerX, playerY;
	player.GetPosition(playerX, playerY);
	movingTile = GetTile(targetX, targetY);
	switch (movingTile)
	{
	case '#': //stop
		break;
	case '.': //move
		player.SetPosition(targetX, targetY);
		SetTile(targetX, targetY, '@');
		SetTile(playerX, playerY, '.');
		break;
	default:

		break;
	}
}
