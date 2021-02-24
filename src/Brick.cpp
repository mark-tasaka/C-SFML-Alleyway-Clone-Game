/*Breakout Clone is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Brick.h"
#include "Constant.h"
#include <iostream>

using namespace sf;



Brick::Brick(Vector2f position, int id)
{
	m_BrickId = id;
	setSprite(m_BrickId);
	m_Sprite = getSprite();
	m_Sprite.setPosition(position);

	if (m_BrickId == 6)
	{
		m_PowerBall = true;
	}
}

void Brick::setSprite(int id)
{

	switch (id)
	{
	case 1:
		m_YLocation = 0;
		break;

	case 2:
		m_YLocation = 25;
		break;

	case 3:
		m_YLocation = 50;
		break;

	case 4:
		m_YLocation = 75;
		break;

	case 5:
		m_YLocation = 100;
		break;

	case 6:
		m_YLocation = 125;
		break;

	case 7:
		m_YLocation = 150;
		break;

	default:
		m_YLocation = 0;
		break;
	}


	m_Texture.loadFromFile("../assets/images/brickSpriteSheet.png");

	if (!m_Texture.loadFromFile("../assets/images/brickSpriteSheet.png"))
	{
		std::cout << "Error loading paddle image";
	}
	m_SpriteRect = sf::IntRect(0, m_YLocation, 100, 20);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(m_SpriteRect);

	m_Sprite.setOrigin(50, 10);

}

Sprite Brick::getSprite()
{
	return m_Sprite;
}


Vector2f Brick::topRight()
{
	return Vector2f(m_Sprite.getPosition().x + BRICK_WIDTH,
		m_Sprite.getPosition().y);
}

Vector2f Brick::topLeft()
{
	return m_Sprite.getPosition();
}

Vector2f Brick::bottomRight()
{
	return Vector2f(m_Sprite.getPosition().x + BRICK_WIDTH,
		m_Sprite.getPosition().y + BRICK_HEIGHT);
}

Vector2f Brick::bottomLeft()
{
	return Vector2f(m_Sprite.getPosition().x,
		m_Sprite.getPosition().y + BRICK_HEIGHT);
}

void Brick::destroyBrick()
{
	m_Sprite.setPosition(90000, 90000);
	m_IsAlive = false;
}

IntRect Brick::getSpriteRect()
{
	return m_SpriteRect;
}


void Brick::update(Clock clock)
{
	//2-hit brick, no damage
	if (m_BrickId == 5)
	{
		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (m_SpriteRect.left == 315)
			{
				m_SpriteRect.left = 0;
			}
			else
			{
				m_SpriteRect.left += 105;
			}
		}
	}

	//2-hit brick, 1 damage
	if (m_BrickId == 7)
	{
		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (m_SpriteRect.left == 315)
			{
				m_SpriteRect.left = 0;
			}
			else
			{
				m_SpriteRect.left += 105;
			}
		}
	}

	//Powerball Brick
	if (m_BrickId == 6)
	{
		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (m_SpriteRect.left == 315)
			{
				m_SpriteRect.left = 0;
			}
			else
			{
				m_SpriteRect.left += 105;
			}
		}
	}
}

/*
bool Brick::isBrickAlive()
{
	return m_IsAlive;
}*/