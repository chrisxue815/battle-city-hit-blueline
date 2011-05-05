#pragma once

#include "Tank.h"
#include "Point.h"
#include "BattleCityMath.h"
#include <allegro.h>


namespace BattleCity
{
	enum EnemyType
	{
		ENEMY_NORMAL,
		ENEMY_HIGH_SPEED,
		ENEMY_HIGH_ARMOR,
		ENEMY_HIGH_DAMAGE
	};

	class Enemy : public Tank
	{
	protected:
		EnemyType enemyType;
		int MOVING_COOLDOWN;
		int SHOOTING_COOLDOWN;

		int movingCooldown;
		int shootingCooldown;

	public:
		Enemy(Level & level, EnemyType enemyType = ENEMY_NORMAL);
		Enemy(Level & level, const Point &, EnemyType enemyType = ENEMY_NORMAL);

	public:
		// @override
		void update(void);
		// @override
		TankType getTankType(void) const { return ENEMY_TANK; }

	protected:
		void init(EnemyType enemyType);
		void loadContent(void);
		void updateMoving(int milliseconds);
		void updateShooting(int milliseconds);
	};
}
