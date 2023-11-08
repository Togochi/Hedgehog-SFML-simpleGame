#pragma once
#include "Player.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


/*
	Class that acts as the Game Engine.
	Wrapper class.
*/

class Game
{
private:
	//Variables
	bool paused;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Resources
	sf::Font font;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture leaf1Texture;
	sf::Texture leaf2Texture;
	sf::Texture leaf3Texture;
	sf::Texture leaf4Texture;
	sf::Texture leaf5Texture;
	sf::Texture snowTexture;
	sf::Texture coneTexture;
	sf::Texture acornTexture;
	sf::Texture chestnut1Texture;

	//Text
	sf::Text uiText;
	sf::Text stopText;

	//Sound
	sf::SoundBuffer ckickBuffer;
	sf::Sound sound;

	//Game logic
	bool endGame;
	unsigned points;
	float speed = 0.f;
	int health = 0;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game objects
	Player player;

	std::vector<sf::Sprite> enemies;
	sf::Sprite enemy1;
	sf::Sprite enemy2;
	sf::Sprite enemy3;
	sf::Sprite enemy4;
	sf::Sprite enemy5;

	sf::Sprite leaf5;
	sf::Sprite cone;
	sf::Sprite acorn;
	sf::Sprite chestnut1;

	//Private func
	void initVariables();
	void initWindow();
	void initEnemies();
	void initFonts();
	void initText();
	void initTextures();
	void initSprites();

public:

	// Constructor / Destructor
	Game();
	~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	// Functions
	void spawnEnemy();
	void pollEvents();

	void togglePause();

	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
};


