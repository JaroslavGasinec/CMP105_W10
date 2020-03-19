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
	TileSet tileSet;
	sf::Texture tileSet_T;
	void render(sf::RenderWindow* window);
};

