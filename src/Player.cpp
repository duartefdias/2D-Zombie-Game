#include "../headers/Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Player::Player(int x, int y) {
    playerX = x - 40;
    playerY = y - 40;
}

void Player::setupSprite() {
    sprite.setRadius(40);
    sprite.setFillColor(sf::Color(150, 50, 250));
    sprite.setPosition(playerX, playerY);
}

void Player::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}

sf::CircleShape & Player::getSprite() {
    return sprite;
}

void Player::moveUp() {
    if (playerY >= 20)
        playerY -= 5;
    else
        playerY = 20;
    sprite.setPosition(playerX, playerY);
}

void Player::moveRight() {
    if (playerX <= 880)
        playerX += 5;
    else
        playerX = 880;
    sprite.setPosition(playerX, playerY);
}

void Player::moveDown() {
    if (playerY <= 680)
        playerY += 5;
    else
        playerY = 680;
    sprite.setPosition(playerX, playerY);
}

void Player::moveLeft() {
    if (playerX >= 20)
        playerX -= 5;
    else
        playerX = 20;
    sprite.setPosition(playerX, playerY);
}
