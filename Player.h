#pragma once

#include <SFML/Graphics.hpp>

class Player {
private:
    float speed;

    bool isJumping;
    float jumpSpeed;
    float jumpHeight;
    float currentJumpHeight;
    float gravity;

   sf::Texture playerTexture;
   sf::Sprite playerSprite;

public:
    Player();
    Player(sf::RenderWindow* window);
    ~Player();

    void initPlayer();
    sf::FloatRect getPlayerGlobalBouns();
    void update(sf::RenderWindow* window);
    void render(sf::RenderTarget& target);

};