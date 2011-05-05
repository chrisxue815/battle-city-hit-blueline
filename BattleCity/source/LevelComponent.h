#pragma once

#include "Level.h"


namespace BattleCity
{
	class LevelComponent
	{
	protected:
		Level & level;

	protected:
		LevelComponent(Level & level);

	public:
		virtual void update(void) = 0;
		virtual void draw(void) = 0;
	};

	inline LevelComponent::LevelComponent(Level & level)
		: level(level)
	{
	}
}
