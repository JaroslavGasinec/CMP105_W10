#pragma once
#include "Framework/GameObject.h"
#include "Framework/TileMap.h"
#include "TileSet.h"

class LevelLayout
{
	sf::Vector2f tileSize = sf::Vector2f(32,32);
public:
	LevelLayout();
	~LevelLayout();

	TileMap tileMap;
	TileMap tileMap2;
	TileMap tileMap3;
	TileSet tileSet;
	TileSet tileSet2;
	void render(sf::RenderWindow* window);
};

