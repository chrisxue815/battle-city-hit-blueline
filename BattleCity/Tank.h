#pragma once

#include "Entity.h"
#include "Rectangle.h"
#include <allegro.h>


namespace BattleCity
{
	class Tank : public Entity
	{
	protected:
		static const int TANK_GRID_WIDTH = 2;
		static const int TANK_GRID_HEIGHT = 2;

		bool alive;

	public:
		Tank(Level & level);
		Tank(Level & level, const Point & point);

	public:
		const bool getAlive(void) const;
		void setAlive(bool alive);
	};

	inline const bool Tank::getAlive(void) const {
		return alive;
	}

	inline void Tank::setAlive(bool alive) {
		this->alive = alive;
	}
}
