#include "Player.h"

Player::Player()
{
    this->initPlayer();
}

Player::~Player()
{

}

void Player::initPlayer()
{
    this->speed = 7.0f;
}

void Player::initPlayerSprite()
{
    this->playerTexture.loadFromFile("Pictures/player.png");
    this->playerTexture.setSmooth(true);
    this->playerSprite.setTexture(playerTexture);
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    this->playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
    this->playerSprite.setScale(0.5f, 0.5f);
}

void Player::setPlayerPosition(float x, float y)
{
    this->playerSprite.setPosition( x,  y);
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

    if (playerSprite.getGlobalBounds().left < 0.f)
    {
        playerSprite.setPosition(0.f + playerSprite.getGlobalBounds().width/2, playerSprite.getPosition().y);
    } 
    else if (playerSprite.getPosition().x + playerSprite.getGlobalBounds().width/2 > window->getSize().x)
    {
        playerSprite.setPosition(window->getSize().x - playerSprite.getGlobalBounds().width/2, playerSprite.getPosition().y);
    }

    if (playerSprite.getPosition().y - playerSprite.getGlobalBounds().height/2 > window->getSize().y)
    {
        playerSprite.setPosition(playerSprite.getPosition().x, window->getSize().y - playerSprite.getGlobalBounds().height/2) ;
    }
}


void Player::render(sf::RenderTarget& target)
{
    target.draw(playerSprite);
}


sf::FloatRect Player::getPlayerGlobalBouns()
{
    return playerSprite.getGlobalBounds();
}
