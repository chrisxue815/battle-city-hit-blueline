#pragma once

#include "Point.h"
#include <allegro.h>


namespace BattleCity
{
	class LevelDrawing
	{
	protected:
		Point gridSize;
		Point levelPoint;
		float scale;

	public:
		LevelDrawing(void);
		LevelDrawing(const Point & gridSize, const Point & levelPoint, float scale);

	public:
		Point getScreenPoint(const Point & point) const;
		const Point & getGridSize(void) const;
		const Point & getLevelPoint(void) const;
	};


	inline const Point & LevelDrawing::getGridSize(void) const {
		return gridSize;
	}

	inline const Point & LevelDrawing::getLevelPoint(void) const {
		return levelPoint;
	}
}
