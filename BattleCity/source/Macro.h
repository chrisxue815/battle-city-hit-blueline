#pragma once


namespace BattleCity
{
	#define MAX_PATH_SIZE 256

	#define GAME_WIDTH 800
	#define GAME_HEIGHT 600

	#define GRID_WIDTH 18
	#define GRID_HEIGHT 18

	#define LEVEL_GRID_WIDTH 38
	#define LEVEL_GRID_HEIGHT 30

	enum Direction {LEFT, RIGHT, UP, DOWN, NO_DIRECTION};

	enum BitmapFrame
	{
		PLAYER1_UP_FRAME,
		PLAYER1_DOWN_FRAME,
		PLAYER1_LEFT_FRAME,
		PLAYER1_RIGHT_FRAME,
		BULLET_FRAME,
		BRICK_FRAME,

		END_FRAME
	};
}
