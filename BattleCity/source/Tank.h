#pragma once

#include "Entity.h"
#include "Rectangle.h"
#include <allegro.h>


namespace BattleCity
{
	class Level;

	// 玩家的子弹不会打中玩家，敌军的子弹不会打中敌军
	enum TankType
	{
		PLAYER_TANK,
		ENEMY_TANK
	};

	class Tank : public Entity
	{
	protected:
		static const int TANK_GRID_WIDTH = 2;
		static const int TANK_GRID_HEIGHT = 2;
		static const float ICE_COEFFICIENT;

		int MS_PER_GRID;  //  1/speed
		int xOffset;
		int yOffset;
		Direction direction;

		int shootingCooldown;

		BITMAP * current;
		BITMAP * upTexture;
		BITMAP * downTexture;
		BITMAP * leftTexture;
		BITMAP * rightTexture;

	protected:
		Tank(Level & level);
		Tank(Level & level, const Point & point);

	public:
		// @override
		void draw(void);
		virtual TankType getTankType(void) const = 0;

	protected:
		void init(void);
		void move(int milliseconds);
		void shoot(int milliseconds);
		bool onIce(void);
	};
}
