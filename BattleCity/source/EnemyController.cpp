#include "EnemyController.h"
#include "Enemy.h"
using namespace BattleCity;


EnemyController::EnemyController( Level & level )
	: LevelComponent(level)
{
	add(Enemy(level, ENEMY_HIGH_DAMAGE));
	add(Enemy(level, ENEMY_NORMAL));
	add(Enemy(level, ENEMY_HIGH_SPEED));
	add(Enemy(level, ENEMY_HIGH_ARMOR));

	enemyBirthplace.push_back(Point(0, 0));
	enemyBirthplace.push_back(Point(10, 0));
	enemyBirthplace.push_back(Point(20, 0));
	enemyBirthplace.push_back(Point(30, 0));

	maxEnemyNumber = 3;
	enemyBirthCooldown = ENEMY_BIRTH_COOLDOWN;

	birthplaceTexture = level.getResourceManager().getBitmap(ENEMY_BIRTHPLACE_FRAME);
}


EnemyController::~EnemyController(void)
{
	destroy_bitmap(birthplaceTexture);
}


void EnemyController::update( void )
{
	// update enemies
	for (list<Enemy>::iterator it = enemies.begin(); it != enemies.end();)
	{
		it->update();

		if (it->getLives() == 0)
			it = enemies.erase(it);
		else
			++it;
	}

	if ((int)enemies.size() < maxEnemyNumber && !enemiesQueuing.empty())
	{
		if (enemyBirthCooldown > 0)
		{
			enemyBirthCooldown -= level.getMilliseconds();
		}
		else
		{
			generateEnemies();
			enemyBirthCooldown = ENEMY_BIRTH_COOLDOWN;
		}
	}
}


void EnemyController::add(Enemy & enemy, int num)
{
	while (num--)
		enemiesQueuing.push(enemy);
}


void EnemyController::draw( void )
{
	BITMAP * buffer = level.getDrawingManager().getBuffer();

	for (int i = 0; i < (int)enemyBirthplace.size(); i++)
	{
		Point & p = level.getLevelDrawing().getScreenPoint(enemyBirthplace[i]);
		draw_sprite(buffer, birthplaceTexture, p.getX(), p.getY());
	}

	for (list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		it->draw();
	}
}


void EnemyController::bulletHitEnemy( const Enemy & enemy )
{
	for (list<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{
		if (&(*it) == &enemy)
		{
			it->loseALife();
			break;
		}
	}
}


void EnemyController::generateEnemies( void )
{
	Enemy & enemy = enemiesQueuing.front();
	enemiesQueuing.pop();

	int birthplace;

	do
	{
		// 在enemyBirthplace中随机选择一个出生点
		birthplace = rand() % enemyBirthplace.size();
		Rectangle rect(enemyBirthplace[birthplace], 1, 1);

		// 如果该点没有坦克，就在该点产生Enemy
		if (! level.collidedWithTank(rect))
			break;

		// 如果该出生点已经有坦克，就继续随机选择出生点
	}
	while (true);

	enemy.setPosition(enemyBirthplace[birthplace]);

	enemies.push_back(enemy);
}
