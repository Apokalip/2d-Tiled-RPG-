#include "entity_manager.h"
struct sortWay {
	bool operator ()(const sf::Sprite *  i, const sf::Sprite * j) {
		float x = i->getPosition().y + i->getGlobalBounds().height;
		float y = j->getPosition().y + j->getGlobalBounds().height;
		return x < y;
	}
};


EntityManager::EntityManager()
{
	this->map = new Map();
}
EntityManager::EntityManager(Player * player, Map * map)
{
	this->player = player;
	this->map = map;
	drawables.push_back(player);
	

}
void EntityManager::Load()
{
	for (int i = 0;i < map->sprites.size();i++) {
		drawables.push_back(map->sprites.at(i));
	}
	std::sort(drawables.begin(), drawables.end(), sortWay());
}

void EntityManager::Add( Entity* entity)
{
	drawables.push_back(entity);
	std::sort(drawables.begin(), drawables.end(), sortWay());
}



void EntityManager::Update(sf::RenderWindow* window)
{
	player->Update(window);

	for (int i = 0;i < map->sprites.size();i++) {
		if ((player->getPosition().y + player->getGlobalBounds().height) < (map->sprites.at(i)->getPosition().y + map->sprites.at(i)->getGlobalBounds().height)) {
			if (player->getGlobalBounds().intersects(map->sprites.at(i)->getGlobalBounds())) {
				map->sprites.at(i)->setTransperant();
			}
			else{
				map->sprites.at(i)->setVisible();
			}
		}
	}
	std::sort(drawables.begin(), drawables.end(), sortWay());
	
}
void EntityManager::Render(sf::RenderWindow* window)
{
	
	
	
	map->Render(window);
	for (auto& it : drawables) {
		window->draw(*it);
	}
	
	}
	




EntityManager::~EntityManager()
{
	
}