#pragma once

#include "Coordinate.h"


namespace BattleCity
{
	class Entity
	{
	protected:
		Coordinate coor;

	public:
		const Coordinate & getCoordinate(void) const;
		void setCoordinate(const Coordinate &);

	public:
		Entity(void);
		Entity(const Coordinate &);
		~Entity(void);

		virtual void loadContent(void) = 0;
		virtual void update(int gameTime) = 0;
		virtual void draw(int gameTime) = 0;
	};


	inline const Coordinate & Entity::getCoordinate(void) const
	{
		return coor;
	}


	inline void Entity::setCoordinate(const Coordinate & value)
	{
		this->coor = value;
	}
}
