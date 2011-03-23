#pragma once

#include "IEntityDrawing.h"
#include <allegro.h>


namespace BattleCity
{
	class ImageDrawing : public IEntityDrawing
	{
	protected:
		BITMAP * texture;

	public:
		ImageDrawing(void);
		~ImageDrawing(void);

	public:
		// @override
		void init(const ResourceManager & resource, const char fileName[MAX_PATH_SIZE]);
		// @override
		void draw(const LevelDrawing & levelDrawing);
	};
}
