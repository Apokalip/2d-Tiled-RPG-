#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "TransSprite.h" 
#include <unordered_map>
#include "Tile.h"



typedef enum {
	NONE=-1,
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
}Direction;
class Entity;
class Map 
{
public:
	sf::Vector2f velocity;

	Map();

	void Load(std::string filename);

	virtual void Update(sf::RenderWindow* window, Entity * entity);
	


	int CheckCollision(sf::Vector2f pos, sf::Vector2f velocity);
	
	void Render(sf::RenderWindow * window);
	
	
	
	int getColType(sf::Vector2f pos);
	std::vector<TransSprite*> sprites;
	~Map();
protected:
	std::string tileSet;
	int width = 0;
	int height = 0;
	int colWidth = 0;
	int colHeight = 0;
	int colTileWidth = 0;
	int colTileHeight = 0;
	int tileWidth = 0;
	int tileHeight = 0;
	sf::Image * groundTileSet;
	sf::Image * groundDecoTileSet;
	std::vector<Tile *> groundLayer;
	std::vector<Tile *> groundLayerDeco;
	std::vector<int> colLayer;
	std::unordered_map<int, TexturePair *> spriteTextures;
	
	std::vector<sf::Texture*> TileTextures;
	std::vector<sf::Texture*> DecoTileTextures;
	
	
private:
	
	
	

};
