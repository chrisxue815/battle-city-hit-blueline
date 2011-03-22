#pragma once

#include "Game.h"
#include "Entity.h"


namespace BattleCity
{
	class Player : public Entity
	{
	public:
		Player(void);
		Player(const Coordinate &);
		~Player(void);

		// @override
		void loadContent(void);
		// @override
		void update(int gameTime);
		// @override
		void draw(int gameTime);
	};
}
