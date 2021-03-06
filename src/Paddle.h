#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle
{
private:
	Vector2f m_Position;

	// A RectangleShape object
	//RectangleShape m_Shape;
	Sprite m_Sprite;

	Texture m_Texture;

	float m_Speed = 1000.0f;

	bool m_MovingRight = false;
	bool m_MovingLeft = false;


public:
	Paddle(float startX, float startY);

	FloatRect getPosition();

	//RectangleShape getShape();
	Sprite getSprite();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void update(Time dt);

};
