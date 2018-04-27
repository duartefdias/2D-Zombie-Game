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

void Player::move(float speed) {
    //Move UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (playerY >= 20)
            playerY -= 5 * speed;
        else
            playerY = 20;
    }
    //Move RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (playerX <= 880)
            playerX += 5 * speed;
        else
            playerX = 880;
    }
    //Move DOWN
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (playerY <= 680)
            playerY += 5 * speed;
        else
            playerY = 680;
    }
    //Move LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (playerX >= 20)
            playerX -= 5 * speed;
        else
            playerX = 20;
    }
    sprite.setPosition(playerX, playerY);
}
