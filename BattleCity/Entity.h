#pragma once

#include "Component.h"
#include "Point.h"
#include "ResourceManager.h"
#include "TimeManager.h"


namespace BattleCity
{
	class Level;
	/**
		*Entity是一个能在Level中运行的类	
	*/
	class Entity
	{
	protected:
		Level & level;
		Point point;

	public:
		virtual const Point & getPoint(void) const;
		virtual void setPoint(const Point &);

	protected:
		Entity(Level & level);
		Entity(Level & level, const Point &);

	public:
		virtual void init(void) = 0;
		virtual void update(void) = 0;
		virtual void draw(void) = 0;
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
