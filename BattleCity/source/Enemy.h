#pragma once

#include "Tank.h"
#include "Point.h"
#include "BattleCityMath.h"
#include <allegro.h>


namespace BattleCity
{
	class Enemy : public Tank
	{
	protected:
		static const int MOVING_COOLDOWN = 1000;
		static const int SHOOTING_COOLDOWN = 1000;

		int movingCooldown;
		int shootingCooldown;

	public:
		Enemy(Level & level);
		Enemy(Level & level, const Point &);

	public:
		// @override
		void update(void);

	protected:
		void init(void);
		void loadContent(void);
		void updateMoving(int milliseconds);
		void updateShooting(int milliseconds);
	};
}
