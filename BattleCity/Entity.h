#pragma once

#include "IComponent.h"
#include "Point.h"
#include "ResourceManager.h"
#include "GameTime.h"


namespace BattleCity
{
	class Game;

	class Entity
	{
	protected:
		Point point;
		const Game & game;

	public:
		virtual const Point & getPoint(void) const;
		virtual void setPoint(const Point &);

	protected:
		Entity(const Game & game);
		Entity(const Game & game, const Point &);

	public:
		virtual void init(const ResourceManager & resource) = 0;
		virtual void update(void) = 0;
		virtual void draw(DrawingManager & drawing) = 0;
	};


	inline const Point & Entity::getPoint(void) const
	{
		return point;
	}


	inline void Entity::setPoint(const Point & value)
	{
		this->point = value;
	}
}
