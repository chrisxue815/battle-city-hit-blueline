#pragma once


namespace BattleCity
{
	class Point
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
		Point(void);
		Point(int, int);
		~Point(void);

		Point operator + (const Point &);
		Point operator - (const Point &);
		Point operator * (const Point &);
		Point operator / (const Point &);
		Point operator * (int);
		Point operator / (int);
		Point & operator += (const Point &);
		Point & operator -= (const Point &);
		Point & operator *= (int);
		Point & operator /= (int);
		bool operator == (const Point &);
		bool operator != (const Point &);
	};


	inline int Point::getX(void) const {
		return x;
	}

	inline void Point::setX(int x) {
		this->x = x;
	}

	inline int Point::getY(void) const {
		return y;
	}

	inline void Point::setY(int y) {
		this->y = y;
	}

	inline Point Point::operator + (const Point & value) {
		return Point(x + value.x, y + value.y);
	}

	inline Point Point::operator - (const Point & value) {
		return Point(x - value.x, y - value.y);
	}

	inline Point Point::operator * (const Point & value) {
		return Point(x * value.x, y * value.y);
	}

	inline Point Point::operator / (const Point & value) {
		return Point(x / value.x, y / value.y);
	}

	inline Point Point::operator * (int value) {
		return Point(x * value, y + y * value);
	}

	inline Point Point::operator / (int value) {
		return Point(x / value, y / value);
	}

	inline Point & Point::operator += (const Point & value) {
		x += value.x;
		y += value.y;
		return *this;
	}

	inline Point & Point::operator -= (const Point & value) {
		x -= value.x;
		y -= value.y;
		return *this;
	}

	inline Point & Point::operator *= (int value) {
		x *= value;
		y *= value;
		return *this;
	}

	inline Point & Point::operator /= (int value) {
		x /= value;
		y /= value;
		return *this;
	}

	inline bool Point::operator == (const Point & value) {
		return x == value.x && y == value.y;
	}

	inline bool Point::operator != (const Point & value) {
		return !(*this == value);
	}
}
