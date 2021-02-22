#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

// This the constructor function
Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;
	/**/
	m_Texture.loadFromFile("../assets/imagesballSpriteSheet.png");

	if (!m_Texture.loadFromFile("../assets/images/ballSpriteSheet.png"))
	{
		std::cout << "Error loading paddle image";
	}
	m_SpriteRect = sf::IntRect(0, 0, 16, 16);
	//m_Sprite(m_Texture, m_SpriteRect);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(m_SpriteRect);

	m_Sprite.setOrigin(8, 8);
}

FloatRect Ball::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Ball::getSprite()
{
	return m_Sprite;
}

float Ball::getXVelocity()
{
	return m_DirectionX;
}

void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundPaddleOrTop()
{
	m_DirectionY = -m_DirectionY;

}

void Ball::reboundBottom()
{
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionY = -m_DirectionY;
}


void Ball::ballReSpawn()
{
	m_Position.y = 200;
	m_Position.x = 500;

}

void Ball::reboundBrick()
{
	m_DirectionX = -m_DirectionX;
	m_DirectionY = -m_DirectionY;
}


void Ball::update(Time dt, Clock clock)
{
	// Update the ball position variables
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	
	if (clock.getElapsedTime().asSeconds() > 10.0f)
	{
		if (m_SpriteRect.left == 64)
		{
			m_SpriteRect.left = 0;
		}
		else
		{
			m_SpriteRect.left += 16;
		}
	}

//	m_SpriteRect = sf::IntRect(m_StartRectX, 0, 16, 16);

	//m_Sprite.setTextureRect(sf::IntRect(m_StartRectX, 0, 16, 16));

	m_Sprite.setTextureRect(m_SpriteRect);

	// Move the ball and the bat
	m_Sprite.setPosition(m_Position);
}


IntRect Ball::getSpriteRect()
{
	return m_SpriteRect;
}

void Ball::setSpriteRect(IntRect newpos)
{
	m_SpriteRect = newpos;
}