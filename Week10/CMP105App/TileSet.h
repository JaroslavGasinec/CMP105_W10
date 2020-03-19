#pragma once
#include "Framework/GameObject.h"

class TileSet
{
	float scale = 1;
	std::vector<GameObject> tileSet;
	sf::Vector2f tileSize;
	sf::Texture* tileSet_T;

public:
	TileSet(sf::Texture* texture, sf::Vector2f tileSize ,float scale);
	~TileSet();

	void setTexture(sf::Texture* tileset_T);

};

