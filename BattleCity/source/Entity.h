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
	 * Entity是一个能在Level中运行的类，是玩家Player、敌人Enemy、子弹Bullet的基类。
	 */
	class Entity
	{
	protected:
		Level & level;
		Rectangle rect;
		int lives;

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

		int getLives(void) const;
		void setLives(int lives);
		void loseALife(void);

	protected:
		bool cannotGoLeft(void);
		bool cannotGoRight(void);
		bool cannotGoUp(void);
		bool cannotGoDown(void);
		bool tileCollision(Rectangle rect);
		bool tankCollision(Rectangle rect);
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

	inline int Entity::getLives(void) const {
		return lives;
	}

	inline void Entity::setLives(int lives) {
		this->lives = lives;
	}

	inline void Entity::loseALife( void ) {
		--this->lives;
	}
}
