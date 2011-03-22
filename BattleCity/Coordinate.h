#pragma once


namespace BattleCity
{
	class Coordinate
	{
	protected:
		int x;
		int y;

	public:
		int getX(void) const;
		void setX(int);

		int getY(void) const;
		void setY(int);

	public:
		Coordinate(void);
		Coordinate(int, int);
		~Coordinate(void);

		Coordinate operator + (const Coordinate &);
		Coordinate operator - (const Coordinate &);
		Coordinate operator * (int);
		Coordinate operator / (int);
		bool operator == (const Coordinate &);
		bool operator != (const Coordinate &);
	};


	inline int Coordinate::getX(void) const
	{
		return x;
	}


	inline void Coordinate::setX(int x)
	{
		this->x = x;
	}


	inline int Coordinate::getY(void) const
	{
		return y;
	}


	inline void Coordinate::setY(int y)
	{
		this->y = y;
	}


	inline Coordinate Coordinate::operator + (const Coordinate & value)
	{
		return Coordinate(x + value.x, y + value.y);
	}


	inline Coordinate Coordinate::operator - (const Coordinate & value)
	{
		return Coordinate(x - value.x, y - value.y);
	}


	inline Coordinate Coordinate::operator * (int value)
	{
		return Coordinate(x * value, y + y * value);
	}


	inline Coordinate Coordinate::operator / (int value)
	{
		return Coordinate(x / value, y / value);
	}


	inline bool Coordinate::operator == (const Coordinate & value)
	{
		return x == value.x && y == value.y;
	}


	inline bool Coordinate::operator != (const Coordinate & value)
	{
		return !(*this == value);
	}
}
