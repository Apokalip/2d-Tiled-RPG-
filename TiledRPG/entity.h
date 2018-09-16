#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "map.h"


class Entity : public sf::Sprite
{
public:
	sf::Vector2f velocity;

	Entity(Map * m );

	void Load(std::string filename);

	virtual void Update(sf::RenderWindow* window);

	bool CheckCollision(Entity* entity);

	virtual void OnCollision(Entity* entity);
	
	sf::Vector2f getVel();

	int GroupID();

	int Active();

	void Destroy();
	virtual void setVisibleTexture(sf::Texture * vis);
	virtual void setTransperantTexture(sf::Texture * tran);
	virtual void setTransperant();
	


	~Entity();
protected:
	int active;
	int groupId;
	Map * map;

private:
	sf::Texture* texture = nullptr;

};

