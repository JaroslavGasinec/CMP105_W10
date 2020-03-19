#include "TileSet.h"

TileSet::TileSet()
{
}

TileSet::TileSet(sf::Vector2u tileDimensions, int spacing ,sf::Texture* texture, sf::Vector2f tileSize, float scale)
{
	GameObject tile;
	for (int i = 0; i < tileDimensions.x*tileDimensions.y; i++) {
		tile.setSize(sf::Vector2f(tileSize.x*scale, tileSize.y*scale));
		tile.setCollisionBox(0, 0, tile.getSize().x, tile.getSize().y);
		tile.setCollider(true);
		tileSet.push_back(tile);
	}

	tileSet[0].setCollider(false);
	tileSet[0].setTextureRect(sf::IntRect(187, 51, tileSize.x, tileSize.y));
	for (int i = 1; i < tileDimensions.x * tileDimensions.y; i++) {
		int posX = 0 + ((int)tileSize.x * ((i - 1) % tileDimensions.x)) + spacing * ((i - 1) % tileDimensions.x);
		int posY = 0 + ((int)tileSize.y * ((i - 1) / tileDimensions.x)) + spacing * ((i - 1) / tileDimensions.x);
		tileSet[i].setTextureRect(sf::IntRect(posX,posY, tileSize.x, tileSize.y));
	}
	tileSet_T = texture;
}

TileSet::~TileSet()
{
}

void TileSet::setTexture(sf::Texture* tileset_T)
{
	this->tileSet_T = tileSet_T;
}

