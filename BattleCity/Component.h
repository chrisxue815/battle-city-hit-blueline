#pragma once

#include "ResourceManager.h"
#include "DrawingManager.h"
#include "TimeManager.h"


namespace BattleCity
{
	class Game;

	/**
		*Component是一个能在Game中运行的类；
	*/
	class Component
	{
	protected:
		Game & game;
		Component(Game & game);

	public:
		virtual void init(void) = 0;
		virtual void update(void) = 0;
		virtual void draw(void) = 0;
	};

	inline Component::Component(Game & game)
		: game(game)
	{
	}
}
