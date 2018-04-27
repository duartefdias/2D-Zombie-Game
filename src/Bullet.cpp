#include "../headers/Bullet.h"

#include <iostream>

Bullet::Bullet(int startX, int startY, int endX, int endY) {
    bulletX = startX;
    bulletY = startY;
    std::cout << "startX: " << startX << std::endl;
    std::cout << "startY: " << startY << std::endl;
    std::cout << "endX: " << endX << std::endl;
    std::cout << "endY: " << endY << std::endl;

    //Setup bullet sprite
    sprite.setRadius(10);
    sprite.setFillColor(sf::Color(100, 250, 50));
    sprite.setPosition(startX, startY);

    //Based on linear equations
    float mX = endX - startX;
    float mY = endY - startY;
    float m = mY/mX;
    std::cout << "m: " << m << std::endl;

    moveX = 1;
    moveY = m;

    //3rd and 4th Quadrant
    if(endX < startX) {
        moveX = mY/mX;
        moveY = 1;
    }

    //3rd Quadrant
    if(endX < startX && endY < startY) {
        moveX = -moveX;
        moveY = -moveY;
    }


    std::cout << "moveX: " << moveX << std::endl;
    std::cout << "moveY: " << moveY << "\n" << std::endl;
}

void Bullet::move(int speed) {
    bulletX += (moveX * speed);
    bulletY += (moveY * speed);
    sprite.setPosition(bulletX, bulletY);
}

/*void Bullet::createBullet(List* bulletList) {
    //TODO: Add bullet to bulletList
}*/

void Bullet::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}
