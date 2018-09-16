//#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "game_state.h"
#include "main_menu.h"
#include "main_game.h"
#include "System.h"
game_state coreState;
bool quitGame = false;


//#ifdef _DEBUG
int main()
//#else
//int CALLBACK WinMain(
	//_In_  HINSTANCE hInstance,
	//_In_  HINSTANCE hPrevInstance,
	//_In_  LPSTR lpCmdLine,
	//_In_  int nCmdShow
	//)
//#endif
{
	sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "Role Call", sf::Style::Fullscreen);
	//sf::RenderWindow window(sf::VideoMode(1280, 768), "Role Call", sf::Style::Close);
	
	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());
	
	
	//window.setFramerateLimit(60);
	//sf::SoundBuffer musicBuffer;
	//musicBuffer.loadFromFile("Sounds/music.wav");
	//sf::Sound music(musicBuffer);
	

	//music.setLoop(true);
	//music.setVolume(10);
	//music.play();
	float lastTime = 0;
	
	window.setVerticalSyncEnabled(true);

	

	// run the program as long as the window is open

	while (window.isOpen())
	{
	
		
		
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
			window.clear(sf::Color::Black);
			sys->Update();
			coreState.Update();
			coreState.Render();
			

			window.display();

			if (quitGame)
			{
				window.close();
			}

			
		
	}

	//music.stop();

	return 0;
}
