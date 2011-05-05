#pragma once

#include "Game.h"
#include "GameComponent.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include "Player.h"
#include "Point.h"
#include <allegro.h>


namespace BattleCity
{
	class GameStateMonitor : public GameComponent
	{
	protected:
		char notification[100];

	public:
		GameStateMonitor(Game & game);

		// @override
		void update(void);
		// @override
		void draw(void);

		void showFps(const TimeManager & timeManager);
		void showPlayerPoint(const Player & player);
	};

	inline GameStateMonitor::GameStateMonitor(Game & game)
		: GameComponent(game)
	{
	}
}
