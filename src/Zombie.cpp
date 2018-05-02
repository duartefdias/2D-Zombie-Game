#include "../headers/Zombie.h"
#include "../headers/Game.h"

#include <iostream>

Zombie::Zombie(Game* game) {
    int x = 20;
    int y = 20;

    int windowX = game->getWindow().getSize().x;
    int windowY = game->getWindow().getSize().y;

    x = rand() % windowX;
    y = windowY-40;

    //Setup zombie sprite
    sprite.setRadius(40);
    sprite.setFillColor(sf::Color(220, 20, 60));
    sprite.setPosition(x, y);
}

void Zombie::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
    std::cout << "Zombie created! Run!" << std::endl;
}
