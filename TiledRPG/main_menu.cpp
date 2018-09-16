#include <iostream>
#include "main_menu.h"
#include "main_game.h"
#include "game_state.h"
#include <Windows.h>
#include "map.h"


void main_menu::Initialize(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	this->selected = 0;
	
	this->menu_font = new sf::Font();
	this->menu_font->loadFromFile("Graphics/menuFont.ttf");

	this->title = new sf::Text("TITLE", *this->menu_font, 256U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2 - 30);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);


	this->play = new sf::Text("Play", *this->menu_font, 128U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->quit = new sf::Text("Quit", *this->menu_font, 128U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play->getGlobalBounds().height);

	//backgroundT = new sf::Texture();
	//backgroundT->loadFromFile("Graphics/images/menuBackground.png");
	//background = new sf::Sprite();
	//backgroundT->setRepeated(false);
	//background->setTexture(*backgroundT);
	//background->setScale(GetSystemMetrics(SM_CXSCREEN)/background->getGlobalBounds().width, GetSystemMetrics(SM_CYSCREEN)/ background->getGlobalBounds().height);
	//background->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	
	
	


}

void main_menu::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		this->selected += 1;
	}
	if (this->selected > 1)
	{
		this->selected = 0;
	}
	if (this->selected < 0)
	{
		this->selected = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			coreState.SetState(new main_game());
			return;
		case 1:
			quitGame = true;
			break;
		}
	}



	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
void main_menu::Render(sf::RenderWindow* window)
{
	//window->draw(*background);
	this->play->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);
	switch (this->selected)
	{
	case 0:
		this->play->setColor(sf::Color::Blue);
		break;
	case 1:
		this->quit->setColor(sf::Color::Blue);
		break;
	}
	
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);
	

	
}
void main_menu::Destroy(sf::RenderWindow* window)
{
	delete this->menu_font;
	delete this->title;
	delete this->play;
	delete this->quit;
}
