/*Breakout Clone is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/
#include "SpawnBricks.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "Brick.h"


SpawnBricks::SpawnBricks()
{
	//srand(time(NULL));
	//int selectNumber = rand() % 5;
	//int selectNumber = 0;


}

std::vector<Brick> SpawnBricks::generateBrickVector(int choice)
{
	
	vector <Brick> bricks;

	if (choice == 0)
	{
		bricks = configure0();
	}
	else if (choice == 1)
	{
		bricks = configure1();
	}
	else
	{
		bricks = configure0();
	}

	return bricks;

}

std::vector<Brick> SpawnBricks::configure0()
{
	vector <Brick> bricks;
	float startX = 300.0f;
	float startY = 50.0f;
	int m_BrickSelect;

	srand(time(NULL));


	for (int i = 1; i < 46; i++)
	{
		m_BrickSelect = rand() % 7 + 1;

		Vector2f brickPos = Vector2f(startX, startY);
		Brick brick(brickPos, m_BrickSelect);
		bricks.push_back(brick);

		startX += 100.0f;

		if (i % 9 == 0)
		{
			startY += 20.0f;
			startX = 300.0f;
		}

	}

	return bricks;
}


std::vector<Brick> SpawnBricks::configure1()
{
	vector <Brick> bricks;
	float startX = 200.0f;
	float startY = 50.0f;
	int m_BrickSelect;

	srand(time(NULL));


	for (int i = 0; i < 24; i++)
	{
		if (i < 9)
		{
			startX += 100.0f;
		}
		else if (i == 9 || i == 11 || i ==13)
		{
			startY += 20.0f;
			startX = 300.0f;
		}
		else if (i == 10 || i == 12 || i == 14)
		{
			startX = 1100.0f;
		}
		else if (i == 15)
		{
			startY += 20.0f;
			startX = 300.0f;
		}
		else
		{
			startX += 100.0f;
		}

		m_BrickSelect = rand() % 7 + 1;
		Vector2f brickPos = Vector2f(startX, startY);
		Brick brick(brickPos, m_BrickSelect);
		bricks.push_back(brick);

	}

	return bricks;
}