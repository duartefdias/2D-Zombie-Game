#include "../headers/Zombie.h"
#include "../headers/Game.h"

#include <iostream>
#include <math.h>

#define PI 3.14159265

Zombie::Zombie(Game* game) {
    zombieX = 20;
    zombieY = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    zombieX = rand() % windowX;
    zombieY = windowY-80;

    //Setup zombie sprite
    spriteTexture.loadFromFile("assets/sprites/zombie/zombieSprite.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(30, 30, 220, 200)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(95, 85);
    sprite.setPosition(zombieX, zombieY);

    dead = 0;
}

void Zombie::renderSprite(Game* game) {
    if(!dead)
    game->getWindow().draw(sprite);
}

void Zombie::move(Player* player, int speed) {
    //Based on linear interpolation
    moveX = player->getPlayerX() - zombieX;
    moveY = player->getPlayerY() - zombieY;
    moveX = moveX / 200;
    moveY = moveY / 200;

    if(moveX == 0 && moveY == 0) {
        moveX = 1;
    }

    zombieX += (moveX * speed);
    zombieY += (moveY * speed);

    //Calculate angle
    float angle = atan2(player->getPlayerY() - zombieY, player->getPlayerX() - zombieX);
    angle *= 180 / PI;

    sprite.setRotation(angle);

    //std::cout << "moveX: " << moveX*speed << std::endl;
    //std::cout << "moveY: " << moveY*speed << std::endl;

    sprite.setPosition(zombieX, zombieY);
}

int Zombie::getZombieX() {
    return zombieX;
}

int Zombie::getZombieY() {
    return zombieY;
}

void Zombie::kill(Game* game) {
if(dead == 0) {
    game->incrementGameScore();
    game->setScoreString(game->getGameScore());
}
    dead = 1;
}

int Zombie::isDead() {
    return dead;
}
