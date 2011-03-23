#pragma once

#include "Entity.h"
#include "ImageDrawing.h"


namespace BattleCity
{
	class Player : public Entity
	{
	protected:
		int milliseconds;
		
		enum Move {NONE, LEFT_RIGHT, UP_DOWN};
		Move lastMove;

		ImageDrawing image;

	public:
		Player(const Game & game);
		Player(const Game & game, const Point &);
		~Player(void);

		// @override
		void init(const ResourceManager & resource);
		// @override
		void update(void);
		// @override
		void draw(DrawingManager & drawing);
	};
}
