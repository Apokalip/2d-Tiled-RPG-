#pragma once

#include "entity_manager.h"
#include "game_state.h"
#include "score.h"
#include "lives.h"
#include "map.h"
#include "player.h"
#include "Camera.h"

extern bool gameOver;


class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Score* score;
	Lives* lives;
	sf::Text* pausedText;
	

	sf::Font* menu_font;

	bool starting;
	bool paused, enterKey;

	EntityManager* manager;

	Map * map;
	Camera * view;
	Player * p1;
	sf::Texture * testTx;
	sf::Texture * testTxTrans;
	sf::Sprite * test;

};