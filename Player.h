#pragma once

#include <SFML/Graphics.hpp>

class Player {
private:

   float speed;

   sf::Texture playerTexture;
   sf::Sprite playerSprite;

public:
    Player();
    ~Player();

    void initPlayer();
    void initPlayerSprite();

    void setPlayerPosition(float x, float y);

    sf::FloatRect getPlayerGlobalBouns();

    void update(sf::RenderWindow* window);
    void render(sf::RenderTarget& target);

};