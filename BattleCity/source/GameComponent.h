#pragma once

#include "Game.h"


namespace BattleCity
{
	class GameComponent
	{
	protected:
		Game & game;

	protected:
		GameComponent(Game & game);

	public:
		virtual void update(void) = 0;
		virtual void draw(void) = 0;
	};

	inline GameComponent::GameComponent(Game & game)
		: game(game)
	{
	}
}
