#pragma once
#ifndef BRICK_H
#define BRICK_H
/*Alleyway Clone is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong' game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include <time.h>

using namespace sf;
using namespace std;

class Brick
{
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	IntRect m_SpriteRect;
	Texture m_Texture;
	int m_BrickId;
	int m_YLocation;
	bool m_IsAlive = true;
	bool m_PowerBall = false;


public:
	Brick(Vector2f position, int id);
	Sprite getSprite(int id);
	IntRect getSpriteRect();
	Vector2f topRight();
	Vector2f topLeft();
	Vector2f bottomRight();
	Vector2f bottomLeft();
	void destroyBrick();

	void update(Clock clock);

};


#endif