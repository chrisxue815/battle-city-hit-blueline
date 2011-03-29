#pragma once

#include "Point.h"


namespace BattleCity
{
	class Rectangle
	{
	protected:
		int left;
		int top;
		int width;
		int height;

	public:
		Rectangle(void);
		Rectangle(int left, int top, int width, int height);
		Rectangle(const Point & leftTop, int width, int height);
		Rectangle(const Point & p1, const Point & p2);

	public:
		int getLeft(void) const;
		void setLeft(int left);

		int getTop(void) const;
		void setTop(int top);

		int getWidth(void) const;
		void setWidth(int width);

		int getHeight(void) const;
		void setHeight(int height);

		int getRight(void) const;
		void setRight(int right);

		int getBottom(void) const;
		void setBottom(int bottom);

		int getX(void) const;
		void setX(int x);

		int getY(void) const;
		void setY(int y);

		Point getLeftTop(void) const;
		void setLeftTop(const Point & leftTop);

		Point getCenter(void) const;
		void setCenter(const Point & center);

		Point getSize(void) const;
		void setSize(const Point & size);

	public:
		Rectangle operator + (const Point & point);
		Rectangle operator - (const Point & point);
		Rectangle & operator += (const Point & point);
		Rectangle & operator -= (const Point & point);
	};

	inline int Rectangle::getLeft(void) const {
		return left;
	}

	inline void Rectangle::setLeft(int left) {
		this->left = left;
	}

	inline int Rectangle::getTop(void) const {
		return top;
	}

	inline void Rectangle::setTop(int top) {
		this->top = top;
	}

	inline int Rectangle::getWidth(void) const {
		return width;
	}

	inline void Rectangle::setWidth(int width) {
		this->width = width;
	}

	inline int Rectangle::getHeight(void) const {
		return height;
	}

	inline void Rectangle::setHeight(int height) {
		this->height = height;
	}

	inline int Rectangle::getRight(void) const {
		return left + width;
	}

	inline void Rectangle::setRight(int right) {
		this->left = right - width;
	}

	inline int Rectangle::getBottom(void) const {
		return top + height;
	}

	inline void Rectangle::setBottom(int bottom) {
		this->top = bottom - height;
	}

	inline Point Rectangle::getLeftTop(void) const {
		return Point(left, top);
	}

	inline void Rectangle::setLeftTop(const Point & leftTop) {
		left = leftTop.getX();
		top = leftTop.getY();
	}

	inline Point Rectangle::getCenter(void) const {
		return Point(left + width / 2, top + height / 2);
	}

	inline void Rectangle::setCenter(const Point & center) {
		left = center.getX() - width / 2;
		top = center.getY() - height / 2;
	}

	inline Point Rectangle::getSize(void) const {
		return Point(width, height);
	}

	inline void Rectangle::setSize(const Point & size) {
		width = size.getX();
		height = size.getY();
	}

	inline int Rectangle::getX(void) const {
		return left;
	}

	inline void Rectangle::setX(int x) {
		left = x;
	}

	inline int Rectangle::getY(void) const {
		return top;
	}

	inline void Rectangle::setY(int y) {
		top = y;
	}

	inline Rectangle Rectangle::operator + (const Point & point) {
		return Rectangle(left + point.getX(), top + point.getY(), width, height);
	}

	inline Rectangle Rectangle::operator - (const Point & point) {
		return Rectangle(left - point.getX(), top - point.getY(), width, height);
	}

	inline Rectangle & Rectangle::operator += (const Point & point) {
		left += point.getX();
		top += point.getY();
		return *this;
	}

	inline Rectangle & Rectangle::operator -= (const Point & point) {
		left -= point.getX();
		top -= point.getY();
		return *this;
	}
}
