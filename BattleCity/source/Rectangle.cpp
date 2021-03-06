﻿#include "Rectangle.h"
using namespace BattleCity;


Rectangle::Rectangle(void)
{
	left = 0;
	top = 0;
	width = 0;
	height = 0;
}


Rectangle::Rectangle(int left, int top, int width, int height)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}


Rectangle::Rectangle(const Point & leftTop, int width, int height)
{
	left = leftTop.getX();
	top = leftTop.getY();
	this->width = width;
	this->height = height;
}


Rectangle::Rectangle(const Point & p1, const Point & p2)
{
	if (p1.getX() < p2.getX())
	{
		left = p1.getX();
		width = p2.getX() - left;
	}
	else
	{
		left = p2.getX();
		width = p1.getX() - left;
	}

	if (p1.getY() < p2.getY())
	{
		top = p1.getY();
		height = p2.getY() - top;
	}
	else
	{
		top = p2.getY();
		height = p1.getY() - top;
	}
}


bool Rectangle::intersects( const Rectangle & rect )
{
	if (getLeft() > rect.getRight() || getRight() < rect.getLeft() ||
		getTop() > rect.getBottom() || getBottom() < rect.getTop())
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool Rectangle::intersects( const Point & point )
{
	if (getLeft() > point.getX() || getRight() < point.getX() ||
		getTop() > point.getY() || getBottom() < point.getY())
	{
		return false;
	}
	else
	{
		return true;
	}
}
