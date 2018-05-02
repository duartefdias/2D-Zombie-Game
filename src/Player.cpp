#include "../headers/Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

#define PI 3.14159265

Player::Player(int x, int y) {
    playerX = x - 40;
    playerY = y - 40;
}

void Player::setupSprite() {
    sprite.setPosition(playerX, playerY);
    spriteTexture.loadFromFile("assets/sprites/player/player_spriteT.png");
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, 150, 190)); //(minWidth, minHeight, maxWidth, maxHeight)
    sprite.setScale(0.5, 0.5);
    sprite.setOrigin(75, 95);
}

void Player::renderSprite(Game* game) {
    game->getWindow().draw(sprite);
}

sf::Sprite & Player::getSprite() {
    return sprite;
}

void Player::move(Game* game, float speed) {
    int windowWidth = game->getWindow().getSize().x;
    int windowHeight = game->getWindow().getSize().y;
    //Move UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (playerY >= 10)
            playerY -= 5 * speed;
        else
            playerY = 10;
    }
    //Move RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (playerX <= windowWidth - 80)
            playerX += 5 * speed;
        else
            playerX = 820;
    }
    //Move DOWN
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (playerY <= windowHeight - 80)
            playerY += 5 * speed;
        else
            playerY = 620;
    }
    //Move LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (playerX >= 10)
            playerX -= 5 * speed;
        else
            playerX = 10;
    }
    sprite.setPosition(playerX, playerY);
}

void Player::rotate(Game* game) {
    int x = game->getMouse().getPosition(game->getWindow()).x;
    int y = game->getMouse().getPosition(game->getWindow()).y;

    //Calculate angle
    float angle = atan2(y - playerY, x - playerX);
    angle *= 180 / PI;

    sprite.setRotation(angle + 90);

    //std::cout << "Player " << "x: " << playerX << " " << "y: " << playerY << std::endl;
    //std::cout << "Mouse " << "x: " << x << " " << "y: " << y << std::endl;
    //std::cout << angle << std::endl;
}

int Player::getPlayerX() {
    return playerX;
}
int Player::getPlayerY() {
    return playerY;
}

bool Player::shoot() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "BAAAAAM" << std::endl;
        return true;
    }
    return false;
}
