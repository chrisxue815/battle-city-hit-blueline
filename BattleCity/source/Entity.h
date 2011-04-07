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
		bool alive;

	protected:
		Entity(Level & level);
		Entity(Level & level, const Rectangle & rect);

	public:
		virtual void update(void) = 0;
		virtual void draw(void) = 0;

	public:
		const Rectangle & getRect(void) const;
		void setRect(const Rectangle & rect);

		Point getPosition(void) const;
		void setPosition(const Point & position);

		bool getAlive(void) const;
		void setAlive(bool alive);

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

	inline Point Entity::getPosition(void) const {
		return rect.getLeftTop();
	}

	inline void Entity::setPosition(const Point & position) {
		rect.setLeftTop(position);
	}

	inline bool Entity::getAlive(void) const {
		return alive;
	}

	inline void Entity::setAlive(bool alive) {
		this->alive = alive;
	}
}
