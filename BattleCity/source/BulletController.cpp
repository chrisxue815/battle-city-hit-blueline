#include "BulletController.h"
using namespace BattleCity;


BulletController::BulletController(Level & level)
	: LevelComponent(level)
{

}


void BulletController::update( void )
{
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end();)
	{
		it->update();

		if (it->getLives() == 0)
			it = bullets.erase(it);
		else
			++it;
	}
}


void BulletController::draw( void )
{
	for (list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
		it->draw();
	}
}
