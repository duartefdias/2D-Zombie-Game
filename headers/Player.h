#ifndef PLAYER_H
#define  PLAYER_H

#include <SFML/Graphics.hpp>
#include "../headers/Game.h"

class Player {
public:
    Player(int x, int y);

    void setupSprite();
    void renderSprite(Game* game);

    sf::Sprite & getSprite();

    //Movement
    void move(Game* game, float speed = 1);


private:
    int playerX;
    int playerY;

    sf::Sprite sprite;
    sf::Texture spriteTexture;

};

#endif //PLAYER_H
