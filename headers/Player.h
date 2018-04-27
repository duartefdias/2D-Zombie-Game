#ifndef PLAYER_H
#define  PLAYER_H

#include <SFML/Graphics.hpp>
#include "../headers/Game.h"

class Player {
public:
    Player(int x, int y);

    void setupSprite();
    void renderSprite(Game* game);

    sf::CircleShape & getSprite();

    //Movement
    void move(Game* game, float speed = 1);


private:
    int playerX;
    int playerY;

    sf::CircleShape sprite;

};

#endif //PLAYER_H
