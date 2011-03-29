#pragma once

#include "Tank.h"
#include "Math.h"


namespace BattleCity
{
	class Player : public Tank
	{
	protected:
		static const int MS_PER_GRID = 150;
		static const int SHOOTING_COOLDOWN = 150;
		static const int ICE_COEFFICIENT = 2;

		int xOffset;
		int yOffset;
		int shootingCooldown;
		
		char lastKeyDown[NO_DIRECTION];  //TODO: fix this hard code

		BITMAP * current;

		BITMAP * upTexture;
		BITMAP * downTexture;
		BITMAP * leftTexture;
		BITMAP * rightTexture;

	public:
		Player(Level & level);
		Player(Level & level, const Point &);

		// @override
		void update(void);
		// @override
		void draw(void);

	protected:
		void loadContent(void);
		void updateMoving(int milliseconds);
		void updateShooting(int milliseconds);
	};
}
