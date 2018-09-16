#include "map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Tile.h"
#include  "entity.h"

Map::Map()
{
	groundTileSet = new sf::Image();
	groundDecoTileSet = new sf::Image();
	
	
}

void Map::Load(std::string filename)
{
	
	std::string temp;
	
	std::ifstream mapFile("Graphics/maps/testArea.map");
	std::ifstream mapDecoFile("Graphics/maps/testAreaDeco.map");
	std::ifstream colFile("Graphics/maps/testAreaCol.map");
	std::ifstream objectFile("Graphics/maps/testAreaObj.map");
		std::getline(mapFile, temp);
		groundTileSet->loadFromFile("Graphics/TileSets/GroundTileSet.png");  //get Ground Tile Set
		groundDecoTileSet->loadFromFile("Graphics/TileSets/GroundDecoTileSet.png");  //get Ground Tile Set

		std::getline(mapFile,temp);
		tileWidth = std::stoi(temp, nullptr); 
		std::getline(mapFile, temp);
		tileHeight = std::stoi(temp, nullptr);
		std::getline(mapFile, temp);
		width = std::stoi(temp, nullptr); // in  Tiles
		std::getline(mapFile, temp);
		height = std::stoi(temp, nullptr); // in  Tiles

		std::getline(colFile, temp);
		colHeight = std::stoi(temp, nullptr); 
		std::getline(colFile, temp);
		colWidth = std::stoi(temp, nullptr); 
		std::getline(colFile, temp);
		colTileHeight = std::stoi(temp, nullptr);
		std::getline(colFile, temp);
		colTileWidth = std::stoi(temp, nullptr); 
	





		
		

		
		
		
		//load Textures from the Ground TileSet
		for (int y = 0; y < 7; y ++)
		{
			for (int x = 0; x <11; x ++) {
				TileTextures.push_back(new sf::Texture);
			//	TileTextures.back()->create(tileWidth, tileHeight);
				TileTextures.back()->loadFromImage(*groundTileSet, sf::IntRect(tileHeight*x, tileWidth*y, tileHeight, tileWidth));
				TileTextures.back()->setSmooth(true);
			//	TileTextures.back()->setRepeated(true);
				//std::cout << x << " " << y << std::endl;
				
			}
		}
		for (int y = 0; y < 3; y += 1)
		{
			for (int x = 0; x <10; x += 1) {
				DecoTileTextures.push_back(new sf::Texture);
				//DecoTileTextures.back()->create(tileWidth, tileHeight);
				DecoTileTextures.back()->loadFromImage(*groundDecoTileSet, sf::IntRect(tileHeight*x, tileWidth*y, tileHeight, tileWidth));
				TileTextures.back()->setSmooth(true);
			//	TileTextures.back()->setRepeated(true);
				//std::cout << x << " " << y << std::endl;

			}
		}


		for (int y = 0; y < height; y += 1)
		{
			for (int x = 0; x < width; x += 1)
			{
				char t;
				int currentTile;
				mapFile >> currentTile >> t;
				groundLayer.push_back(new Tile());
				//std::cout << groundLayer.size();
				groundLayer.back()->setPosition((x*(tileHeight)), (y*(tileWidth )));
				std::cout << currentTile;
				if (currentTile > 0) {
					//Tile* k = groundLayer.at(x + y*width);
					//sf::Texture* kk = (TileTextures.at(currentTile - 1));
					groundLayer.at(x + y*width)->setTexture(*(TileTextures.at(currentTile - 1)));
					
				}
				
			}
			}
		for (int y = 0; y < height; y += 1)
		{
			for (int x = 0; x < width; x += 1)
			{
				char t;
				int currentTile;
				mapDecoFile >> currentTile >> t;
				groundLayerDeco.push_back(new Tile());
				//std::cout << groundLayer.size();
				groundLayerDeco.back()->setPosition((x*(tileHeight)), (y*(tileWidth)));
				std::cout << currentTile;
				if (currentTile > 0) {
					//Tile* k = groundLayer.at(x + y*width);
					//sf::Texture* kk = (TileTextures.at(currentTile - 1));
					groundLayerDeco.at(x + y*width)->setTexture(*(DecoTileTextures.at(currentTile - 1)));
					
				}
				
				
			}
		}

		for (int y = 0; y < colHeight; y += 1)
	
		{
			for (int x = 0; x < colWidth; x += 1)
			{
			char t;
			int currentTile;
			colFile >> currentTile >> t;
			
				colLayer.push_back(currentTile);
			
			
				
			
		}
	}
		//get Sprite Textures
		int objectTypeCount;
		int type=0;
		
		std::getline(objectFile, temp);
		objectTypeCount = std::stoi(temp, nullptr);
		for (int i = 0;i < objectTypeCount;i++) {
			std::getline(objectFile, temp);
			type = std::stoi(temp, nullptr); //getType
			spriteTextures[type] = new TexturePair(); //set Type as Key
			std::getline(objectFile, temp);
			spriteTextures[type]->loadVisible("Graphics/TileSets/" + temp); //load normal texture
			std::getline(objectFile, temp);
			spriteTextures[type]->loadTransperant("Graphics/TileSets/" + temp); //load Transperant Texture
		}
	
		int objectCount;

		std::getline(objectFile, temp);
		objectCount = std::stoi(temp, nullptr); //getType
		for (int i = 0;i < objectCount;i++) {
			char t;
			int type;
			int x;
			int y;
			objectFile >> type >> t >> x >> t >> y >> t;
			TransSprite * current = new TransSprite();
			current->setVisibleTexture(spriteTextures[type]->vis);
			current->setTransperantTexture(spriteTextures[type]->tran);
			current->setPosition(x, y);
			sprites.push_back(current);
			}
		
		std::cout << "  :::  "<<sprites.size() << "  :::  " << std::endl;
		////std::cout << " :: " << "trans layer loaded" << " :: " << std::endl;
		//std::cout << " :: " << "ground layer size :"<<groundLayer.size() << " :: " << std::endl;
		mapFile.close();
		mapDecoFile.close();
		colFile.close();
		objectFile.close();
		//std::cout << "GroundLayer : " << groundLayer.size() << std::endl;
		//std::cout << "colLayer : " << colLayer.size() << std::endl;
		//std::cout << "TransLayer : " << transLayer.size() << std::endl;
		//std::cout << "height : " << height<< std::endl;
		//std::cout << "width : " << width << std::endl;
		//test
		






			}
void Map::Update(sf::RenderWindow* window, Entity * entity) {



			}
void Map::Render(sf::RenderWindow * window) {


	for (int y = 0; y <height; y++)
	{
		for (int x = 0; x< width; x++)
		{
			
				window->draw(*groundLayer.at(x + y*width));
			
				window->draw(*groundLayerDeco.at(x + y*width));
		

			}

		}
	
	

	


}


int Map::getColType(sf::Vector2f pos) {
	int x = (int)pos.x / colTileWidth;
	int y = (int)pos.y / colTileHeight;
	
		return colLayer.at(x + y*colWidth);
	

}



int Map::CheckCollision(sf::Vector2f pos, sf::Vector2f velocity)
{ 
	
		return getColType(pos + velocity);
	

}




Map::~Map()
{
	for (int y = 0; y <height; y++)
	{
		for (int x = 0; x< width; x++)
		{

			delete groundLayer.at(x + y*width);


		}

	}

	
}