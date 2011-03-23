#pragma once

#include "IComponent.h"
#include "ResourceManager.h"
#include "GameTime.h"
#include "Player.h"
#include "Point.h"
#include <allegro.h>


namespace BattleCity
{
	class GameStateMonitor : public IComponent
	{
	protected:
		char notification[100];

	public:
		GameStateMonitor(void);
		~GameStateMonitor(void);

		// @override
		void init(const ResourceManager & resource);
		// @override
		void update(void);
		// @override
		void draw(DrawingManager & drawing);

		void showFps(const GameTime & gameTime);
		void showPlayerPoint(const Player & player);
	};
}
