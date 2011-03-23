#pragma once

#include "ResourceManager.h"
#include "GameTime.h"
#include "LevelDrawing.h"
#include "Macro.h"


namespace BattleCity
{
	// @interface
	class IEntityDrawing
	{
	protected:
		IEntityDrawing(void);

	public:
		virtual void init(const ResourceManager & resource, const char fileName[MAX_PATH_SIZE]) = 0;
		virtual void draw(const LevelDrawing & levelDrawing) = 0;
	};

	inline IEntityDrawing::IEntityDrawing(void)
	{
	}
}
