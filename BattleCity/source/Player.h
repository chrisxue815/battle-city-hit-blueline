﻿#pragma once

#include "BulletType.h"
#include "Tank.h"
#include "Point.h"
#include "BattleCityMath.h"
#include <allegro.h>


namespace BattleCity
{
	class Player : public Tank
	{
	protected:
		static const int SHOOTING_COOLDOWN = 300;

		char lastKeyLeft;
		char lastKeyRight;
		char lastKeyUp;
		char lastKeyDown;

	public:
		Player(Level & level);
		Player(Level & level, const Point &);

		// @override
		void update(void);
		// @override
		BulletType getBulletType(void) const { return PLAYER_BULLET; }

	protected:
		void init(void);
		void loadContent(void);
		void updateMoving(int milliseconds);
		void updateShooting(int milliseconds);
	};
}
