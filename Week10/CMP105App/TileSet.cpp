#include "TileSet.h"

TileSet::TileSet(sf::Texture* texture, sf::Vector2f tileSize, float scale)
{
	GameObject tile;
	for (int i = 0; i < 7; i++) {
		tile.setSize(sf::Vector2f(tileSize.x*scale, tileSize.y*scale));
		tile.setCollisionBox(0, 0, tileSize.x*scale, tileSize.y*scale);
		tile.setCollider(true);
		tileSet.push_back(tile);
	}

	tileSet[0].setCollider(false);
	tileSet[0].setTextureRect(sf::IntRect(187, 51, tileSize.x, tileSize.y));
	tileSet[1].setTextureRect(sf::IntRect(0, 0, tileSize.x, tileSize.y));
	tileSet[2].setTextureRect(sf::IntRect(17, 0, tileSize.x, tileSize.y));
	tileSet[3].setTextureRect(sf::IntRect(34, 0, tileSize.x, tileSize.y));
	tileSet[4].setTextureRect(sf::IntRect(0, 34, tileSize.x, tileSize.y));
	tileSet[5].setTextureRect(sf::IntRect(17, 34, tileSize.x, tileSize.y));
	tileSet[6].setTextureRect(sf::IntRect(34, 34, tileSize.x, tileSize.y));
	tileSet_T = texture;
}

TileSet::~TileSet()
{
}

void TileSet::setTexture(sf::Texture* tileset_T)
{
	this->tileSet_T = tileSet_T;
}

