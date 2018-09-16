#pragma once
#include <SFML/Graphics.hpp>
class System {
public:
		System();
		void Update();
		float getLastFrameTime();
private:
	sf::Clock * timer;
	float deltaTime;
	



};
extern System * sys;
