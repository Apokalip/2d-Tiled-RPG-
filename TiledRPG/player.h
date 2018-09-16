#pragma once
#include "entity.h"
#include "map.h"
class Player : public Entity {
public:
	Player(Map * map,float x,float y);
	void Update(sf::RenderWindow *  window);
	void Collision(Entity * entity);



private:
	Map * map;
	float speed;
};
