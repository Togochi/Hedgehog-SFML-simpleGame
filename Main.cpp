#include <iostream>
#include "Game.h"

int main()
{
	
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));
	//Init Game 
	Game game;

	//Init Music
	sf::Music music;
	if (!music.openFromFile("Audio/music.wav")) {
		std::cerr << "ERROR: Failed load music";
	}
	music.setLoop(true);
	music.play();
	music.setVolume(50);

	//Game loop
	while (game.running())
	{
		//update
		game.update();

		//render
		game.render();
	}

	//End of application
	return 0;
}