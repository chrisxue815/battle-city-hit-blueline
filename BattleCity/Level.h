#pragma once

#include "Player.h"
#include "GameTime.h"
#include <allegro.h>
#include <vector>


namespace BattleCity
{
	class Game;

	class Level : public IComponent
	{
	protected:
		const Game & game;

		typedef vector<int> vector1;
		typedef vector<vector1> vector2;

		vector2 board;
		Player player;

	public:
		const Player & getPlayer(void) const;

	public:
		Level(const Game & game);

		// @override
		void init(const ResourceManager & resource);
		// @override
		void update(void);
		// @override
		void draw(DrawingManager & drawing);
	};


	inline const Player & Level::getPlayer(void) const
	{
		return player;
	}
}
