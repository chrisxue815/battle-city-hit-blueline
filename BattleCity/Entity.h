#pragma once

#include "Component.h"
#include "Rectangle.h"
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
		Rectangle rect;

	public:
		const Rectangle & getRect(void) const;
		void setRect(const Rectangle & rect);

		Point getPoint(void) const;
		void setPoint(const Point & point);

	protected:
		Entity(Level & level);
		Entity(Level & level, const Rectangle & rect);

	public:
		virtual void update(void) = 0;
		virtual void draw(void) = 0;

	protected:
		bool cannotGoLeft(void);
		bool cannotGoRight(void);
		bool cannotGoUp(void);
		bool cannotGoDown(void);
	};

	inline const Rectangle & Entity::getRect(void) const {
		return rect;
	}

	inline void Entity::setRect(const Rectangle & rect) {
		this->rect = rect;
	}

	inline Point Entity::getPoint(void) const {
		return rect.getLeftTop();
	}

	inline void Entity::setPoint(const Point & point) {
		rect.setLeftTop(point);
	}
}
