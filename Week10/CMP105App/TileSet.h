#pragma once
#include "Framework/GameObject.h"

class TileSet
{
	float scale = 1;
	std::vector<GameObject> tileSet;
	sf::Vector2f tileSize;
	int clearTile = 1;
	const char* textureAddress;
	void initialise(sf::Vector2u tileDimensions, int spacing, const char* textureAddress, sf::Vector2f tileSize, float scale);

public:
	TileSet();
	TileSet(sf::Vector2u tileDimensions, int spacing , const char* textureAddress, sf::Vector2f tileSize ,float scale);
	TileSet(sf::Vector2u tileDimensions, int spacing, const char* textureAddress, sf::Vector2f tileSize, float scale, int clearTile);
	~TileSet();

	std::vector<GameObject> getTileSet() { return tileSet; }
	const char* getTexture() { return textureAddress; }
};

