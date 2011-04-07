#pragma once

#include "Entity.h"
#include "LevelDrawing.h"
#include <allegro.h>


namespace BattleCity
{
	class AnimationDrawing
	{
	protected:
		const Entity & entity;
		BITMAP * texture;

	public:
		AnimationDrawing(const Entity & entity);
		~AnimationDrawing(void);

	public:
		virtual void init(const ResourceManager & resource, const char fileName[MAX_PATH_SIZE]) = 0;
		virtual void draw(DrawingManager & drawing, const LevelDrawing & levelDrawing) = 0;
	};


	inline AnimationDrawing::AnimationDrawing(const Entity & entity)
		: entity(entity)
	{
	}


	inline AnimationDrawing::~AnimationDrawing(void)
	{
		if (texture != NULL)
			destroy_bitmap(texture);
	}
}
