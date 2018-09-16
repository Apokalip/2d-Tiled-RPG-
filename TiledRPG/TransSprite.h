#pragma once
#include <SFML/Graphics.hpp>

struct TexturePair {
	sf::Texture * vis;
	sf::Texture * tran;
	TexturePair() {
		vis = new sf::Texture();
		tran = new sf::Texture();
	}
	TexturePair(sf::Texture * vis, sf::Texture * tran) {
		this->vis = vis;
		this->tran = tran;
	}
	void loadVisible(std::string visible) {
		vis->loadFromFile(visible);
		
	}
	void loadTransperant( std::string transperant) {
		
		tran->loadFromFile(transperant);
	}
	void load(std::string visible,std::string transperant) {
		vis->loadFromFile(visible);
		tran->loadFromFile(transperant);
	}

};
class TransSprite : public  sf::Sprite{
public:
	TransSprite();
	TransSprite(sf::Texture * vis,sf::Texture * trans);
	virtual void setVisibleTexture(sf::Texture * vis);
	virtual void setTransperantTexture(sf::Texture * tran);
	virtual void setTransperant();
	void setVisible();
	bool CheckCollision(sf::Sprite * entity);
	
private:
	sf::Texture * visible;
	sf::Texture * transperant;
	
};
