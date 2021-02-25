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

std::vector<Brick> SpawnBricks::generateBrickVector()
{
	vector <Brick> bricks;
	float startX = 300.0f;
	float startY = 50.0f;

	srand(time(NULL));


	for (int i = 1; i < 46; i++)
	{
		m_BrickSelect = rand() % 7 + 1;

		Vector2f brickPos = Vector2f(startX, startY);
		Brick brick (brickPos, m_BrickSelect);
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