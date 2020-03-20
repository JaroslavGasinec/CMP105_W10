#include "TileSet.h"


TileSet::TileSet()
{
}

TileSet::TileSet(sf::Vector2u tileDimensions, int spacing , const char* textureAddress, sf::Vector2f tileSize, float scale)
{
	initialise(tileDimensions, spacing, textureAddress, tileSize, scale);
}

TileSet::TileSet(sf::Vector2u tileDimensions, int spacing, const char* textureAddress, sf::Vector2f tileSize, float scale, int clearTile)
{
	this->clearTile = clearTile;
	initialise(tileDimensions, spacing, textureAddress, tileSize, scale);
}

TileSet::~TileSet()
{
}

void TileSet::initialise(sf::Vector2u tileDimensions, int spacing, const char* textureAddress, sf::Vector2f tileSize, float scale)
{
	GameObject tile;
	for (int i = 0; i < tileDimensions.x * tileDimensions.y; i++) {
		tile.setSize(sf::Vector2f(tileSize.x * scale, tileSize.y * scale));
		tile.setCollisionBox(0, 0, tile.getSize().x, tile.getSize().y);
		tile.setCollider(true);
		tileSet.push_back(tile);
	}

	int posX = 0 + ((int)tileSize.x * ((clearTile - 1) % tileDimensions.x)) + spacing * ((clearTile - 1) % tileDimensions.x);
	int posY = 0 + ((int)tileSize.y * ((clearTile - 1) / tileDimensions.x)) + spacing * ((clearTile - 1) / tileDimensions.x);
	tileSet[0].setCollider(false);
	tileSet[0].setTextureRect(sf::IntRect(187, 51, tileSize.x, tileSize.y));

	for (int i = 1; i < tileDimensions.x * tileDimensions.y; i++) {
		posX = 0 + ((int)tileSize.x * ((i - 1) % tileDimensions.x)) + spacing * ((i - 1) % tileDimensions.x);
		posY = 0 + ((int)tileSize.y * ((i - 1) / tileDimensions.x)) + spacing * ((i - 1) / tileDimensions.x);
		tileSet[i].setTextureRect(sf::IntRect(posX, posY, tileSize.x, tileSize.y));
	}
	this->textureAddress = textureAddress;
}