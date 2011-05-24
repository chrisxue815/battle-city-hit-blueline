#pragma once

#include "LevelComponent.h"
#include "Enemy.h"
#include <vector>
#include <queue>
using namespace std;


namespace BattleCity
{
	class EnemyController : public LevelComponent
	{
	protected:
		list<Enemy> enemies;
		queue<Enemy> enemiesQueuing;

		int maxEnemyNumber;
		vector<Point> enemyBirthplace;
		int enemyBirthCooldown;

		static const int ENEMY_BIRTH_COOLDOWN = 1000;

		BITMAP * birthplaceTexture;

	public:
		EnemyController(Level & level);
		~EnemyController(void);

	public:
		void update(void);
		void draw(void);

	public:
		void add(Enemy & enemy, int num = 1);
		void bulletHitEnemy(const Enemy & enemy);

	public:
		const list<Enemy> & getEnemies() const { return enemies; }

	protected:
		void generateEnemies(void);
	};
}
