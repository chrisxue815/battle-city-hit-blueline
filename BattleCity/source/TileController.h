#pragma once

#include "LevelComponent.h"
#include "Tile.h"
#include <vector>
using namespace std;


namespace BattleCity
{
	class TileController : public LevelComponent
	{
	protected:
		vector<vector<Tile*>> tiles;
		list<Point> bushTiles;

	public:
		TileController(Level & level);
		~TileController();

	public:
		void update(void);
		void draw(void);
		void drawBushTiles(void);

	public:
		void bulletHitTile(int x, int y);

	public:
		const Tile * getTile(int x, int y) const;
	};
}
