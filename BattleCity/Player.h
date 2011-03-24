#pragma once

#include "Entity.h"
#include "Math.h"


namespace BattleCity
{
	class Player : public Entity
	{
	protected:
		static const int MS_PER_GRID = 100;
		int xOffset;
		int yOffset;
		
		enum Move {NONE, LEFT, RIGHT, UP, DOWN};
		Move lastMove;

		BITMAP * texture;

	public:
		Player(Level & level);
		Player(Level & level, const Point &);
		~Player(void);

		// @override
		void init(void);
		// @override
		void update(void);
		// @override
		void draw(void);
	};
}
