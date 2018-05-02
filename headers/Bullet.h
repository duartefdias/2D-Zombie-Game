#ifndef BULLET_H
#define  BULLET_H

#include "../headers/Linked_list.h"
#include "../headers/Game.h"
#include <SFML/Graphics.hpp>

class Bullet{
public:
    Bullet(int startX, int startY, int endX, int endY);

    void move(int speed = 1);

    //void createBullet(List* bulletList);
    void renderSprite(Game* game);

private:
    int bulletX;
    int bulletY;

    float moveX;
    float moveY;

    sf::CircleShape sprite;

    Bullet* bulletAux;
    
};

#endif //BULLET_H
