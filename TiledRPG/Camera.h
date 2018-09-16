#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
class Camera : public sf::View
{
public:
	
	Camera(int x, int y);
	Camera(int x, int y, Entity * target);
	void Update(sf::RenderWindow * window);
	void Render(sf::RenderWindow * window);

private:
	sf::Clock *fpsTime;
	sf::Font *fpsFont;
	sf::Text *fpsText;
	Entity * target;
	float speed;
};