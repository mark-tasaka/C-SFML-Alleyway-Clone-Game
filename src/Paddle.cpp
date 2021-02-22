#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


// This the constructor and it is called when we create an object
Paddle::Paddle(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Texture.loadFromFile("../assets/images/paddle.png");

	if (!m_Texture.loadFromFile("../assets/images/paddle.png"))
	{
		std::cout << "Error loading paddle image";
	}

	m_Sprite.setTexture(m_Texture);

	m_Sprite.setOrigin(50, 10);
	
}

FloatRect Paddle::getPosition()
{
	return m_Sprite.getGlobalBounds();
}


void Paddle::moveLeft()
{
	m_MovingLeft = true;

}

void Paddle::moveRight()
{
	m_MovingRight = true;
}

void Paddle::stopLeft()
{
	m_MovingLeft = false;

}

void Paddle::stopRight()
{
	m_MovingRight = false;
}

void Paddle::update(Time dt)
{
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Sprite.setPosition(m_Position);
}


Sprite Paddle::getSprite()
{
	return m_Sprite;
}