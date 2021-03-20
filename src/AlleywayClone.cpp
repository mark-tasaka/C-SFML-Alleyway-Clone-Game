/*Alleyway Clone is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/
#include "Paddle.h"
#include "stdafx.h"
#include "Ball.h"
#include "Constant.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "SpawnBricks.h"

using namespace sf;




int main()
{
	
	// Create a video mode object
	VideoMode vm(SCREEN_WIDTH, SCREEN_HEIGHT);

	enum class State { START, PLAY, PAUSE, GAME_OVER };

	//The Start of the Game
	State state = State::START;

	// Create and open a window for the game
	RenderWindow window(vm, "Alleyway Clone", Style::Close);

	sf::Clock clockTime;

	int score = 0;
	int lives = 3;
	int hiScore = 0;
	int level = 1;


	srand(time(NULL));
	int selectNumber = rand() % 4;
	//int selectNumber = 3;

	std::vector<Brick> bricks = SpawnBricks().generateBrickVector(selectNumber);

	srand(time(NULL));

	std:vector<int> brickTypeVector;

	//Brick types
	for (int k = 0; k < bricks.size(); ++k)
	{
		brickTypeVector.push_back(k);
	}

	int bType = 0;
	
	for (auto& theBrickLayout : bricks)
	{
		bType = rand() % 6 + 1;

		theBrickLayout.setSprite(bType);
	}

	// Create a bat
	Paddle paddle(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20);

	// We will add a ball in the next chapter
	Ball ball(SCREEN_WIDTH / 2, 200);

	// Create a Text object called HUD
	Text hud;

	// A cool retro-style font
	Font font;
	font.loadFromFile("../assets/font/forcedSquare.ttf");


	//Start Page State
	Texture startTexture;
	startTexture.loadFromFile("../assets/images/startGame.png");
	Sprite spriteStartGame;
	spriteStartGame.setTexture(startTexture);

	//Game Play State
	Texture background;
	background.loadFromFile("../assets/images/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(background);

	//Pause State
	Texture pauseGame;
	pauseGame.loadFromFile("../assets/images/pause.png");
	Sprite spritePause;
	spritePause.setTexture(pauseGame);

	//Pause State
	Texture GameOverTexture;
	GameOverTexture.loadFromFile("../assets/images/gameOver.png");
	Sprite spriteGameOver;
	spriteGameOver.setTexture(GameOverTexture);


	// Set the font to our retro-style
	hud.setFont(font);

	// Make it nice and big
	hud.setCharacterSize(30);

	// Choose a color
	hud.setFillColor(Color::White);

	hud.setPosition(20, 20);

	// Load the high score from a text file/
	std::ifstream inputFile("../assets/topScore/highScore.txt");
	if (inputFile.is_open())
	{
		inputFile >> hiScore;
		inputFile.close();
	}



	// Here is our clock for timing everything
	Clock clock;

	//hit sound
	SoundBuffer hitBuffer;
	hitBuffer.loadFromFile("../assets/sound/hit.wav");
	Sound hit;
	hit.setBuffer(hitBuffer);

	//hit paddle
	SoundBuffer hitBufferPaddle;
	hitBufferPaddle.loadFromFile("../assets/sound/hitPaddle.wav");
	Sound hit2;
	hit2.setBuffer(hitBufferPaddle);

	//Miss sound
	SoundBuffer missBuffer;
	missBuffer.loadFromFile("../assets/sound/miss.wav");
	Sound miss;
	miss.setBuffer(missBuffer);

	while (window.isOpen())
	{
		/*
		Handle the player input
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{// Quit the game when the window is closed
				window.close();
			}

			if (event.key.code == Keyboard::Return && state == State::START)
			{
				state = State::PLAY;
			}


			//return from paused game
			if (event.key.code == Keyboard::Return &&
				state == State::PAUSE)
			{
				state = State::PLAY;
				// Reset the clock so there isn't a frame jump
				clock.restart();
			}


		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}



		if (state == State::PLAY)
		{


			// Pause a game while playing
			if (event.key.code == Keyboard::Space &&
				state == State::PLAY)
			{
				state = State::PAUSE;
			}


			// Handle the pressing and releasing of the arrow keys
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (paddle.getPosition().left < 202)
				{
					paddle.stopLeft();
				}
				else
				{
					paddle.moveLeft();
				}
			}
			else
			{
				paddle.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::Right))
			{

				if (paddle.getPosition().left + 112 > window.getSize().x)
				{
					paddle.stopRight();
				}
				else
				{
					paddle.moveRight();
				}
			}
			else
			{
				paddle.stopRight();
			}

		}
		/*
		Update the paddle, bricks, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		// Update the delta time
		Time dt = clock.restart();
		paddle.update(dt);
		ball.update(dt, clockTime);

		/*
		for (auto& eachBrick : bricks)
		{
			eachBrick.update(dt);
		}*/
	
		
		// Update the HUD text
		std::stringstream ss;
		ss << "Level: " << level << "\n\nScore: " << score << "\n\nBalls: " << lives << "\n\nTop Score:\n" << hiScore;
		hud.setString(ss.str());

		//Ball hitting brick
		for (int i = 0; i < bricks.size(); i++)
		{
			//bricks[i].update(dt);
			//int brickType = rand() % 6 + 1;
			//bricks[i].setSprite(brickTypeVector[i]);
			//if(ball. >= bricks[i].bottomLeft() )
			if (ball.getPosition().intersects(bricks[i].getSprite().getGlobalBounds() ))
			{

				bricks[i].m_IsAlive = false;
				bricks[i].destroyBrick();
				hit.play();
				score += 10;
				//bricksRemaining -= 1;
				ball.reboundBrick();

				if (score > hiScore)
				{
					hiScore = score;
				}

			}
		}


		// Handle ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y)
		{
			// reverse the ball direction
			ball.ballReSpawn();

			// Remove a life
			lives--;

			miss.play();

			// Check for zero lives
			if (lives < 1) 
			{
				// reset the score
				score = 0;


				std::ofstream outputFile("../assets/topScore/highScore.txt");
				outputFile << hiScore;
				outputFile.close();

				// reset the lives
				lives = 3;
			}

		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundPaddleOrTop();

			// Add a point to the players score
			//score+= 5;

			if (score > hiScore)
			{
				hiScore = score;
			}

			hit.play();

		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 202 ||
			ball.getPosition().left + 26 > window.getSize().x)
		{
			ball.reboundSides();

			hit.play();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(paddle.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundPaddleOrTop();
			hit2.play();
		}
		/*
		Draw the bat, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		window.clear();

		if (state == State::START)
		{
			window.draw(spriteStartGame);
		}

		if (state == State::PLAY)
		{
			window.draw(spriteBackground);
			window.draw(hud);
			window.draw(paddle.getSprite());
			window.draw(ball.getSprite());

			for (auto& theBrick : bricks)
			{
				window.draw(theBrick.getSprite());
			}
		}

		if (state == State::PAUSE)
		{
			window.draw(spriteBackground);
			window.draw(hud);
			window.draw(paddle.getSprite());
			window.draw(ball.getSprite());

			for (auto& theBrick : bricks)
			{
				window.draw(theBrick.getSprite());
			}

			window.draw(spritePause);
		}

		window.display();
	}
	return 0;
}

