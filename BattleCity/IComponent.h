#pragma once

#include "ResourceManager.h"
#include "DrawingManager.h"
#include "GameTime.h"


namespace BattleCity
{
	// @interface
	class IComponent
	{
	protected:
		IComponent(void);

	public:
		virtual void init(const ResourceManager & resource) = 0;
		virtual void update(void) = 0;
		virtual void draw(DrawingManager & drawing) = 0;
	};

	inline IComponent::IComponent(void)
	{
	}
}
