#include "Paddle.h"

// This the constructor and it is called when we create an object
Paddle::Paddle(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(100, 5));
	m_Shape.setPosition(m_Position);
	
}

FloatRect Paddle::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Paddle::getShape()
{
	return m_Shape;
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

	m_Shape.setPosition(m_Position);
}
