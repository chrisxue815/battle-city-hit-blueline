#pragma once

#include "LevelComponent.h"
#include "Bullet.h"
#include <list>
using namespace std;


namespace BattleCity
{
	class BulletController : public LevelComponent
	{
	protected:
		list<Bullet> bullets;

	public:
		BulletController(Level & level);

	public:
		void update(void);
		void draw(void);

	public:
		void add(Bullet & bullet) { bullets.push_back(bullet); }

	public:
		list<Bullet> getBullets() { return bullets; }
	};
}
