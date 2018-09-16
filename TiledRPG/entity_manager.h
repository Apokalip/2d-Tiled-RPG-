#pragma once

#include <unordered_map>
#include <vector>
#include "Player.h"
#include "entity.h"
#include "map.h"
#include <iostream>
#include <algorithm>
#include "TransSprite.h"


class EntityManager
{
public:
	EntityManager();
	EntityManager(Player * player,Map * map);
	void Add( Entity* entity);
	void Load();

	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);

	~EntityManager();
private:
	Player  * player;
	
	std::vector <sf::Sprite * > drawables;
	Map * map;
};