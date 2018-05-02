#include "../headers/Bullet.h"

#include <iostream>

Bullet::Bullet(int startX, int startY, int endX, int endY) {
    bulletX = startX;
    bulletY = startY;
    /*std::cout << "startX: " << startX << std::endl;
    std::cout << "startY: " << startY << std::endl;
    std::cout << "endX: " << endX << std::endl;
    std::cout << "endY: " << endY << std::endl;*/

    //Setup bullet sprite
    sprite.setRadius(10);
    sprite.setFillColor(sf::Color(100, 250, 50));
    sprite.setPosition(startX, startY);

    //Based on linear interpolation
    moveX = endX - startX;
    moveY = endY - startY;
    moveX = moveX / 200;
    moveY = moveY / 200;


    std::cout << "moveX: " << moveX << std::endl;
    std::cout << "moveY: " << moveY << "\n" << std::endl;
}

void Bullet::move(int speed) {
    bulletX += (moveX * speed);
    bulletY += (moveY * speed);

    //std::cout << "bulletX: " << bulletX << std::endl;
    //std::cout << "bulletY: " << bulletY << "\n" << std::endl;
    sprite.setPosition(bulletX, bulletY);
}

/*void Bullet::createBullet(List* bulletList) {
    //TODO: Add bullet to bulletList
}*/

void Bullet::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}
