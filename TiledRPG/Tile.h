#pragma once
#include <SFML/Graphics.hpp>



class Tile : public sf::Sprite {
public:
	
	Tile();
	void setType(int t);
	
	int getType();
private:
	int type;
	//0 floor
	//1 col
	//2 trans
	

};