#include "Player.h"


Player::Player() 
{
}

Player::Player(sf::RenderWindow* window)
{
    this->speed = 6.0f;
    
    this->playerSprite.setScale(0.5f, 0.5f);
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
    this->playerSprite.setPosition(window->getSize().x / 2, window->getSize().y - playerSprite.getGlobalBounds().height);

}

Player::~Player()
{
}

void Player::initPlayer()
{
    this->playerTexture.loadFromFile("Pictures/player.png");
    playerTexture.setSmooth(true);
    this->playerSprite.setTexture(playerTexture);
}

void Player::update(sf::RenderWindow* window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    { 
           playerSprite.setScale(-0.5f, 0.5f);
           playerSprite.move(-speed, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerSprite.setScale(0.5f, 0.5f);
        playerSprite.move(speed, 0.f);
    }


    if (playerSprite.getPosition().x < 0.)
    {
        playerSprite.setPosition(0.f, playerSprite.getPosition().y);
    }

   if (playerSprite.getPosition().x + playerSprite.getGlobalBounds().width > window->getSize().x)
    {
        playerSprite.setPosition(window->getSize().x - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
    }

    sf::Vector2u windowSize = window->getSize();

    // Check if the player is below the bottom boundary
    if (playerSprite.getPosition().y + playerSprite.getGlobalBounds().height > windowSize.y)
    {
        // Adjust the player's position to stay at the bottom boundary
        float newY = windowSize.y - playerSprite.getGlobalBounds().height+5;
        playerSprite.setPosition(playerSprite.getPosition().x, newY);
    }
}


void Player::render(sf::RenderTarget& target)
{
    target.draw(playerSprite);
}

sf::FloatRect Player::getPlayerGlobalBouns()
{
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    return playerBounds;
}
