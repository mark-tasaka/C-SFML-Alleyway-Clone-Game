#pragma once
#ifndef SPAWNBRICKS_H
#define SPAWNBRICKS_H
/*Breakout Clone is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/
#include "Brick.h"
#include <vector>

using namespace std;

class SpawnBricks
{
private:
	int m_Bricks;
	int m_BricksRemaining;
	int m_BrickSelect;
	float m_StartX;
	float m_StartY;
	//vector <Brick> m_Bricks;

public:
	SpawnBricks();
	std::vector<Brick> generateBrickVector(int choice);
	std::vector<Brick> configure0();
	std::vector<Brick> configure1();
	std::vector<Brick> configure2();
	std::vector<Brick> configure3();
};


#endif // SPAWNBRICKS_H
