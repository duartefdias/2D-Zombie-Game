#include "../headers/Zombie.h"
#include "../headers/Game.h"

#include <iostream>

Zombie::Zombie(Game* game) {
    int x = 20;
    int y = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    x = rand() % windowX;
    y = windowY-80;

    //Setup zombie sprite
    sprite.setRadius(40);
    sprite.setFillColor(sf::Color(220, 20, 60));
    sprite.setPosition(x, y);
}

void Zombie::renderSprite(Game* game) {
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

    sprite.setPosition(zombieX, zombieY);
}

int Zombie::getZombieX() {
    return zombieX;
}

int Zombie::getZombieY() {
    return zombieY;
}
