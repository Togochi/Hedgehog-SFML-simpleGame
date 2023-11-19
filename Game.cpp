#include "Game.h"
#include "Player.h"

//Private func



void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->endGame = false;
	this->points = 0;
	this->health = 20;
	this->enemySpawnTimerMax = 30.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 8;
	this->speed = 1.f;

	this->ckickBuffer.loadFromFile("Audio/sound.ogg");
	this->sound.setBuffer(ckickBuffer);
	this->sound.setVolume(15);
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game_1 Leaf_fall", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(true);
}

void Game::initEnemies()
{
	this->enemy1.setScale(0.15f, 0.15f);
	this->enemy2.setScale(0.15f, 0.15f);
	this->enemy3.setScale(0.15f, 0.15f);
	this->enemy4.setScale(0.15f, 0.15f);
	this->enemy5.setScale(0.01f, 0.01f);

	this->leaf5.setScale(0.15f, 0.15f);
	this->cone.setScale(0.06f, 0.06f);
	this->acorn.setScale(0.03f, 0.03f);
}

void Game::initFonts()
{
	if (!(this->font.loadFromFile("Fonts/Dosis-Light.ttf")))
		std::cout << "ERROR::GAME::INITFONTS: Failed to load font" << '\n';
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");

	this->stopText.setFont(this->font);
	this->stopText.setCharacterSize(24);
	this->stopText.setFillColor(sf::Color::White);
	this->stopText.setString("");
}

void Game::initTextures()
{

	if (!this->backgroundTexture.loadFromFile("Pictures/forest.jpeg"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load background texture" << '\n';
	}

	if (!this->leaf1Texture.loadFromFile("Pictures/leaf1.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->leaf2Texture.loadFromFile("Pictures/leaf2.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->leaf3Texture.loadFromFile("Pictures/leaf3.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->leaf4Texture.loadFromFile("Pictures/leaf4.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->snowTexture.loadFromFile("Pictures/snow1.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->leaf5Texture.loadFromFile("Pictures/leaf5.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->coneTexture.loadFromFile("Pictures/cone.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}

	if (!this->acornTexture.loadFromFile("Pictures/acorn.png"))
	{
		std::cerr << "ERROR::GAME::initTextures: Failed to load leaves texture" << '\n';
	}
}

void Game::initSprites()
{
	this->backgroundSprite.setTexture(backgroundTexture);
	this->backgroundSprite.setScale((*this->window).getSize().x / backgroundSprite.getLocalBounds().width, (*this->window).getSize().y / backgroundSprite.getLocalBounds().height);

	this->enemy1.setTexture(leaf1Texture);
	this->enemy2.setTexture(leaf2Texture);
	this->enemy3.setTexture(leaf3Texture);
	this->enemy4.setTexture(leaf4Texture);
	this->enemy5.setTexture(snowTexture);

	this->leaf5.setTexture(leaf5Texture);
	this->cone.setTexture(coneTexture);
	this->acorn.setTexture(acornTexture);
}

//Constructor / Destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTextures();
	this->initSprites();
	this->initFonts();
	this->initText();
	this->initEnemies();
	this->player = Player();
	this->player.initPlayerSprite();
	this->player.setPlayerPosition(window->getSize().x / 2, window->getSize().y - player.getPlayerGlobalBouns().height / 2);
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}


//Functions

void Game::spawnEnemy()
{
	/*
	Spawns enemies and sets positions randomly
	- Sets a random types (diff).
	- Sets a random position
	- Adds enemy to the vector.
	*/

	int type = rand() % 8;
	switch (type)
	{

	case 0:
		this->enemy1.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy1.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(enemy1);
		break;
	case 1:
		this->enemy2.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy2.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(enemy2);
		break;
	case 2:
		this->enemy3.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy3.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(enemy3);
		break;
	case 3:
		this->enemy4.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy4.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(enemy4);
		break;
	case 4:
		this->enemy5.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy5.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(enemy5);
		break;
	case 5:
		this->cone.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->cone.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(cone);
		break;
	case 6:
		this->leaf5.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->leaf5.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(leaf5);
		break;

	case 7:
		this->acorn.setPosition(
			static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->acorn.getGlobalBounds().width)),
			0.f
		);
		this->enemies.emplace_back(acorn);
		break;
	}
}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->ev.key.code == sf::Keyboard::P)
			{
				this->togglePause();
			}
			break;			
		}
	}
}


void Game::togglePause()
{
	paused = !paused;
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << '\n'
		<< "Skips to the end: " << this->health << '\n';

	this->uiText.setString(ss.str());
}



void Game::updateEnemies()
{
	/*
	Updates the enemy spawn timer and spawn enemies
	when the total amounts of enemies is smaller than the max.
	 Moves the enemies downwards.
	 Removes the enemies at the edge of the screen.
	*/

	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies) {

		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	//Moving and updating enemies
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool deleted = false;

		this->enemies[i].move(0.f, speed);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			//std::cout << "Health: " << this->health << '\n';
		}
	}

	//Chek if intersects

	for (size_t i = 0; i < this->enemies.size(); i++)
	{

		if (this->enemies[i].getGlobalBounds().intersects(player.getPlayerGlobalBouns()))
		{
			this->sound.play();
			//Gain points
			if (enemies[i].getTexture() == &snowTexture)
				this->points += 10;
			else if (enemies[i].getTexture() == &coneTexture)
				this->points += 4;
			else if (enemies[i].getTexture() == &acornTexture)
				this->points += 7;
			else
				this->points += 1;
			//std::cout << "Points: " << this->points << '\n';

			this->enemies.erase(this->enemies.begin() + i);
		}
	}

	if (this->points >= 1000)
		this->speed = 1.5f;
}


void Game::update()
{
	this->pollEvents();
	this->updateText();

	if (!this->endGame && !paused) {

		this->updateEnemies();
		this->player.update(this->window);
	}
	else if (this->paused)
		stopText.setString("PAUSE");
		sf::FloatRect textBounds = stopText.getGlobalBounds();
		stopText.setPosition(this->window->getSize().x /2 - textBounds.width/2, this->window->getSize().y / 2 - textBounds.height/2);
	

	//End game condition
	if (this->health <= 0)
	{
		this->endGame = true;
		stopText.setString("GAME OVER");
		sf::FloatRect textBounds = stopText.getGlobalBounds();
		stopText.setPosition(this->window->getSize().x / 2 - textBounds.width / 2, this->window->getSize().y / 2 - textBounds.height / 2);
	}
}


void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
	if (this->paused) 
		target.draw(this->stopText);
	if (this->endGame)
		target.draw(this->stopText);
}

void Game::renderEnemies(sf::RenderTarget& target)
{
	// Rendering all the enemies
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}


void Game::render()
{
	/*
	 - clear old frame
	 - render objects
	 - display frame in window

	*/
	this->window->clear();

	//Draw game objects
	window->draw(this->backgroundSprite);
	
	this->renderEnemies(*this->window);
	this->renderText(*this->window);
	this->player.render(*this->window);

	this->window->display();
}
