#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position;	
	//RectangleShape m_Shape;

	Sprite m_Sprite;


	sf::IntRect m_SpriteRect;

	Texture m_Texture;


	float m_Speed = 1000.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();


	IntRect getSpriteRect();

	void setSpriteRect(IntRect newPos);


	Sprite getSprite();

	float getXVelocity();

	void reboundSides();

	void reboundPaddleOrTop();

	void reboundBrick();

	void ballReSpawn();

	void reboundBottom();

	void update(Time dt, Clock clock);

};
