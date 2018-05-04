#include "../headers/Zombie.h"
#include "../headers/Game.h"

#include <iostream>

Zombie::Zombie(Game* game) {
    zombieX = 20;
    zombieY = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    zombieX = rand() % windowX;
    zombieY = windowY-80;

    //Setup zombie sprite
    sprite.setRadius(40);
    sprite.setFillColor(sf::Color(220, 20, 60));
    sprite.setPosition(zombieX, zombieY);
    sprite.setOrigin(20, 20);

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
    std::cout << "moveX: " << moveX*speed << std::endl;
    std::cout << "moveY: " << moveY*speed << std::endl;

    sprite.setPosition(zombieX, zombieY);
}

int Zombie::getZombieX() {
    return zombieX;
}

int Zombie::getZombieY() {
    return zombieY;
}

void Zombie::kill(Game* game) {
    dead = 1;
    game->incrementGameScore();
    game->setScoreString(game->getGameScore());
}

int Zombie::isDead() {
    return dead;
}
