//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_BULLET_H
#define ZOMBIEGAME_BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "../headers/Game.h"
#include "../headers/GameCharacter.h"

class Bullet{
public:
    Bullet(int startX, int startY, int endX, int endY);

    void move(int speed = 1);

    //void createBullet(List* bulletList);
    void renderSprite(Game* game);

    int getBulletX();
    int getBulletY();

    bool isOutOfScreen(Game* game);

private:
    int bulletX;
    int bulletY;

    float moveX;
    float moveY;

    sf::CircleShape sprite;

    Bullet* bulletAux;

};

#endif //ZOMBIEGAME_BULLET_H
