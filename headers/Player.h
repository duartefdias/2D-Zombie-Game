#ifndef PLAYER_H
#define  PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(int x, int y);

    void setupSprite();
    void renderSprite();


private:
    int playerX;
    int playerY;

    sf::CircleShape sprite;

};

#endif //PLAYER_H
