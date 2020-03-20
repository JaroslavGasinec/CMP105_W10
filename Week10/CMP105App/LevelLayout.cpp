#include "LevelLayout.h"

LevelLayout::LevelLayout()
{
	tileMap.loadTexture("gfx/marioTiles.png");

	//Simple Mario
	GameObject tile;
	std::vector<GameObject> tiles;

	for (int i = 0; i < 7; i++) {
		tile.setSize(sf::Vector2f(tileSize.x, tileSize.y));
		tile.setCollisionBox(0, 0, tileSize.x, tileSize.y);
		tile.setCollider(true);
		tiles.push_back(tile);
	}

	tiles[0].setCollider(false);
	tiles[0].setTextureRect(sf::IntRect(187, 51, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16)); 
	tiles[2].setTextureRect(sf::IntRect(17, 0, 16, 16)); 
	tiles[3].setTextureRect(sf::IntRect(34, 0, 16, 16)); 
	tiles[4].setTextureRect(sf::IntRect(0, 34, 16, 16)); 
	tiles[5].setTextureRect(sf::IntRect(17, 34, 16, 16)); 
	tiles[6].setTextureRect(sf::IntRect(34, 34, 16, 16));

	tileMap.setTileSet(tiles);
	sf::Vector2u mapSize(10, 6);
	std::vector<int> map = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 3, 0, 0, 0, 0, 0,
		1, 2, 3, 4, 6, 1, 2, 3, 0, 0,
		4, 5, 6, 0, 0, 4, 5, 6, 0, 0};
	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 408));
	tileMap.buildLevel();

	//Complex Mario
	tileSet = TileSet(sf::Vector2u(12,6),1,"gfx/marioTiles.png", sf::Vector2f(16, 16), 2, 48);
	tileMap2.loadTexture(tileSet.getTexture());
	tileMap2.setTileSet(tileSet.getTileSet());
	std::vector<int> map2 = {
		 1,  2,  3,  0,  0,  0,  0,  0, 
		13, 14, 15,  0,  0,  9, 10,  3, 
		13, 14, 29,  2,  2, 21, 22, 15, 
		13, 14, 14, 14, 14, 14, 35, 36, 
		13, 14, 14, 14, 14, 15,  0,  0,   };
	tileMap2.setTileMap(map2, sf::Vector2u(8, 5));
	tileMap2.setPosition(sf::Vector2f(50, 200));
	tileMap2.buildLevel();
	//Pokemon
	tileSet2 = TileSet(sf::Vector2u(28, 41), 1, "gfx/PokemonTileset.png", sf::Vector2f(16, 16), 10, 6);
	tileMap3.loadTexture(tileSet2.getTexture());
	tileMap3.setTileSet(tileSet2.getTileSet());
	std::vector<int> map3 = {
		 7,  7,  7, 15, 16, 17,  7,  7,
		 7,  8,  7, 43, 44, 45,  7,  7,
		 7,  8,  7, 71, 72, 73,  7,  7,
		 7,  8,  8, 99,100,101,  8,  7,
		 7,  8,  8,  8,  8,  8,  8,  7, };
	tileMap3.setTileMap(map3, sf::Vector2u(8, 5));
	tileMap3.setPosition(sf::Vector2f(350, 100));
	tileMap3.buildLevel();


}

LevelLayout::~LevelLayout()
{
}

void LevelLayout::render(sf::RenderWindow* window)
{
	tileMap.render(window);
	tileMap2.render(window);
	tileMap3.render(window);
}
