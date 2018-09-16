#include "main_game.h"
#include "main_menu.h"
#include "game_over.h"
#include "win_screen.h"
#include <Windows.h>
#include "player.h"
#include <iostream>


bool gameOver = false;


void main_game::Initialize(sf::RenderWindow* window)
{
	
	this->menu_font = new sf::Font();
	this->menu_font->loadFromFile("Graphics/menuFont.ttf");

	this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *menu_font, 64U);
	this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
	this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	
	
	this->paused = false;
	this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);

	map = new Map();
	map->Load("test.map");
	p1 = new Player(map, 50, 50);
	manager = new EntityManager(p1,map);
	
	view = new Camera(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),p1);
	manager->Load();
	//p1->scale(0.5f, 0.5f);
	
	view->zoom(0.8f);
	window->setView(*view);

	
	

}
void main_game::Update(sf::RenderWindow* window)
{
	//std::cout << p1->getPosition().x<<"  "<<p1->getPosition().y;
	//system("cls");
		view->Update(window);	
		if (this->paused)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey)
			{
				this->paused = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				coreState.SetState(new main_menu());
			return;
			}
		}
		else
		{
			//p1->Update(window);
			
			

			

			this->manager->Update(window);
			
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey)
			{
				this->paused = true;
			}
		}
		
		if (gameOver )
		{
			gameOver = false;
			coreState.SetState(new game_over());
			return;
		}
		
	
	this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void main_game::Render(sf::RenderWindow * window)
{		
	
	this->manager->Render(window);
	
	
	//map->RenderCol(window);
//	map->RenderTrans(window);
	
	
	if (this->paused)
	{
		window->draw(*this->pausedText);
	}
	view->Render(window);
}
void main_game::Destroy(sf::RenderWindow* window)
{
	
	delete this->pausedText;
	delete p1;
	delete this->menu_font;

	delete this->manager;
}
