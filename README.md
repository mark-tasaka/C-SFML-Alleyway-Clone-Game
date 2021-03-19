# C-SFML-Alleyway-Clone-Game
‘Alleyway Clone’ builds on John Horton’s ‘Pong’ example from his book, ‘Beginning C++ Game Programming’ book (published by Packt>) as a starting point.  This project takes a similar path to a project I created earlier, titled ‘Breakout Clone’.  However, Alleyways Clone utilizes graphics to represent the various objects (i.e., the paddle, the ball, the bricks) in the game and generates a random configuration of level designs.  As well, there is more diversity added to the bricks in the game, such as some bricks are hard to destroy than others (i.e., take multiple hits) and other bricks increases the difficulty of the game (i.e., increases the ball’s speed for 30 seconds).

The name ‘Alleyway’ itself comes from a Nintendo Game developed for the Gameboy system, which is modelled on the classics 1976 ‘Breakout’ video game.

-------------------

RULES/GOAL:

The goal ‘Alleyway Clone’ is to receive the highest score possible by destroying bricks and conquering levels. Bricks are destroyed upon contact with the ball. Every brick destroyed is worth Points! When all the bricks are destroyed, the level is conquered. The player will then move on to the next level. Each new level becomes more challenging than the last as the ball moves faster. 

--------------------

HOW TO PLAY:

Move Paddle Left = 'Left' Arrow Key

Move Paddle Right = 'Right' Arrow Key

Pause Game = 'P' Keyboard Key

Exit Game = 'Escape' Key


------------------------

Reference: John Horton's (Packt) Beginning C++ Game Programing (Second Edition): http://gamecodeschool.com/books/beginning-c-plus-plus-game-programming-2nd-edition/

----------------------




Update 1.06: 2021-03-18

Created an alternate level layout and added the ability to randomly generate the level.



Update 1.05: 2021-02-26

Add the stage transition functionality (Start Game to Play Game, etc.) to the game.



Update 1.04: 2021-02-25

New graphics have been added for the 'start game', 'pause game' and 'game over' stages.  More functionality has been added to the program.


Update 1.03: 2021-02-24

Added a new SpawnBrick class (SpawnBrick.h and SpawnBrick.cpp) that will randomly generate the layout of bricks for the games. 


Update 1.02: 2021-02-23

A new folder containing .wav files has been added, containg the sounds for the game.  As well, a new spritesheet for the bricks and brick animations has been added.  A brick class (brick.h and brick.cpp) has been created to allowing for brick objects to be initialized.


Update 1.01: 2021-02-22

Added stage tranisition graphics (pause game and game over), paddle graphic and a sprite sheet for the ball animation.  Updated the code to allow for an animation sequence for the ball.


Initial commit: 2021-02-21

The initial commit for the game project.
