#include "Level.h"

Level::Level()
{
}
//Load file
void Level::LoadLevel(string fileName, Player &player)
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
				_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 50, 3));
				_enemies.back().SetPosition(j, i);
				break;
			case 'g':
				_enemies.push_back(Enemy("Goblin", tile, 1, 6, 2, 30, 150, 5));
				_enemies.back().SetPosition(j, i);
				break;
			case 'O':
				_enemies.push_back(Enemy("Ogre", tile, 4, 20, 4, 200, 500, 6));
				_enemies.back().SetPosition(j, i);
				break;
			case 'D':
				_enemies.push_back(Enemy("Dragon", tile, 10, 2000, 10, 2000, 50000000, 6));
				_enemies.back().SetPosition(j, i);
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

void Level::UpdateEnemies(Player & player)
{
	int playerX, playerY;
	player.GetPosition(playerX, playerY);
	int enemyX, enemyY;
	char aiMove;
	for (int i = 0; i < _enemies.size(); i++)
	{
		aiMove = _enemies[i].GetMove(playerX, playerY);
		_enemies[i].GetPosition(enemyX, enemyY);
		switch (aiMove)
		{
		case 'w': //up
			ProcessEnemyMove(player, i, enemyX, enemyY - 1);
			break;
		case 's': //down
			ProcessEnemyMove(player, i, enemyX, enemyY + 1);
			break;
		case 'a': //left
			ProcessEnemyMove(player, i, enemyX - 1, enemyY);
			break;
		case 'd': // Right
			ProcessEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		}
	}
}

void Level::BattleEnemy(Player &player, int targetX, int targetY)
{
	int enemyX, enemyY, attackRoll, attackResult, playerX, playerY;
	string name;
	player.GetPosition(playerX, playerY);
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].GetPosition(enemyX, enemyY);
		if (targetX == enemyX && targetY == enemyY)
		{
			//Battle
			attackRoll = player.Attack();
			name = _enemies[i].GetName();
			printf("\nPlayer attacked %s with a roll of %d", name.c_str(), attackRoll);
			attackResult = _enemies[i].TakeDamage(attackRoll);
			if (attackResult != 0)
			{
				printf("\n%s die!", name.c_str());
				player.AddExperience(attackResult);
				//delete
				SetTile(targetX, targetY, '.');
				_enemies[i] = _enemies.back();
				_enemies.pop_back();
				i--;
			}
			//Monster fight
			attackRoll = _enemies[i].Attack();
			attackResult = _enemies[i].TakeDamage(attackRoll);
			if (attackResult != 0)
			{
				printf("\nYou die!");
				SetTile(playerX, playerY, 'x');
				system("pause");
				exit(0);
			}
			system("pause");
			return;
		}
	}
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
	default: //hit enemy
		BattleEnemy(player, targetX, targetY);
		break;
	}
}

void Level::ProcessEnemyMove(Player & player, int enemyIndex, int targetX, int targetY)
{
	char movingTile;
	int enemyX, enemyY;
	_enemies[enemyIndex].GetPosition(enemyX, enemyY);
	movingTile = GetTile(targetX, targetY);
	switch (movingTile)
	{
	case '#': //stop
		break;
	case '.': //move
		_enemies[enemyIndex].SetPosition(targetX, targetY);
		SetTile(targetX, targetY, _enemies[enemyIndex].GetTile());
		SetTile(enemyX, enemyY, '.');
		break;
	case '@':
		BattleEnemy(player, enemyX, enemyY);
		break;
	default: //hit enemy
		break;
	}
}
