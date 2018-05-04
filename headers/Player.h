#ifndef PLAYER_H
#define  PLAYER_H

#include <SFML/Graphics.hpp>
#include "../headers/Game.h"
#include "../headers/Bullet.h"

class Player {
public:
    Player(int x, int y);

    void setupSprite();
    void renderSprite(Game* game);

    sf::Sprite & getSprite();

    //Movement
    void move(Game* game, float speed = 1);
    void rotate(Game* game);

    bool shoot();

    int getPlayerX();
    int getPlayerY();

    void kill();
    int isDead();

private:
    int playerX;
    int playerY;

    sf::Sprite sprite;
    sf::Texture spriteTexture;

    int press = false;
    int pressAux = false;

    int dead;

};

#endif //PLAYER_H
