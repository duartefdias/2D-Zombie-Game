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
