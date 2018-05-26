//
// Created by bob on 26-05-2018.
//

#include "../headers/MovementTypes.h"

void Roaming::doMove(Player *player, Game *game, Zombie* zombie int speed) {
    int randDirection = rand() % 4;

    //Zombie moves randomly
    int maxX = game->getWindow().getSize().x;
    int maxY = game->getWindow().getSize().y;
    switch (randDirection) {
        case 0:
            moveX = 0;
            moveY = -0.5;
            angle = -90.0;
            if (Y < 10) {
                randDirection = 2;
            }
            break;
        case 1:
            moveX = 0.5;
            moveY = 0;
            angle = 0;
            if (X > maxX - 10) {
                randDirection = 3;
            }
            break;
        case 2:
            moveX = 0;
            moveY = 0.5;
            angle = 90;
            if (Y > maxY - 10) {
                randDirection = 0;
            }
            break;
        case 3:
            moveX = -0.5;
            moveY = 0;
            angle = 180;
            if (X < 10) {
                randDirection = 1;
            }
            break;
    }

    X += (moveX * speed);
    Y += (moveY * speed);
    sprite.setRotation(angle);

    //std::cout << "moveX: " << moveX*speed << std::endl;
    //std::cout << "moveY: " << moveY*speed << std::endl;

    sprite.setPosition(X, Y);
}

void Offensive::doMove(Player *player, Game *game, Zombie* zombie int speed) {
    //Zombie moves torwards player
    else if(offensive) {
        //Based on linear interpolation
        moveX = player->getX() - X;
        moveY = player->getY() - Y;
        moveX = moveX / 200;
        moveY = moveY / 200;

        if (moveX == 0 && moveY == 0) {
            moveX = 1;
        }

        //Calculate angle
        angle = atan2(player->getY() - Y, player->getX() - X);
        angle *= 180 / PI;

        X += (moveX * speed);
        Y += (moveY * speed);
        sprite.setRotation(angle);

        //std::cout << "moveX: " << moveX*speed << std::endl;
        //std::cout << "moveY: " << moveY*speed << std::endl;

        sprite.setPosition(X, Y);
}