#pragma once


namespace BattleCity
{
	class Coordinate
	{
	protected:
		int x;
		int y;

	public:
		int getX(void);
		void setX(int);

		int getY(void);
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
}
