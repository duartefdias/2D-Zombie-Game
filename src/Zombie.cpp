//
// Created by bob on 18-05-2018.
//

#include "../headers/Zombie.h"

Zombie::Zombie(Game* game) {
    X = 20;
    Y = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    //Choose side of window where zombie spawns
    int side = rand() % 4;

    switch (side) {
        //Top
        case 0:
            X = rand() % windowX;
            Y = 80;
            break;
            //Right
        case 1:
            X = windowX - 80;
            Y = rand() % windowY;
            break;
            //Down
        case 2:
            X = rand() % windowX;
            Y = windowY-80;
            break;
            //Left
        default:
            X = 80;
            Y = rand() % windowY;
            break;
    }

    //Setup zombie sprite
    spriteTexture.loadFromFile("../assets/sprites/zombie/zombieSprite.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(X, Y);
}

void Zombie::move(Player* player, int speed) {
    //Based on linear interpolation
    moveX = player->getX() - X;
    moveY = player->getY() - Y;
    moveX = moveX / 200;
    moveY = moveY / 200;

    if(moveX == 0 && moveY == 0) {
        moveX = 1;
    }

    X += (moveX * speed);
    Y += (moveY * speed);

    //Calculate angle
    float angle = atan2(player->getY() - Y, player->getX() - X);
    angle *= 180 / PI;

    sprite.setRotation(angle);

    //std::cout << "moveX: " << moveX*speed << std::endl;
    //std::cout << "moveY: " << moveY*speed << std::endl;

    sprite.setPosition(X, Y);
}

void Zombie::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}

int Zombie::getX() {
    return X;
}

int Zombie::getY() {
    return Y;
}