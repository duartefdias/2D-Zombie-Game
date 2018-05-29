//
// Created by bob on 18-05-2018.
//

#include "../headers/Player.h"

Player::Player(int x, int y) {
    X = x - 40;
    Y = y - 40;
}

void Player::move(Game* game, float speed) {
    int windowWidth = game->getWindow().getSize().x;
    int windowHeight = game->getWindow().getSize().y;
    //Move UP
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (Y >= 10)
            Y -= 5 * speed;
        else
            Y = 10;
    }
    //Move RIGHT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (X <= windowWidth - 80)
            X += 5 * speed;
        else
            X = windowWidth - 80;
    }
    //Move DOWN
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (Y <= windowHeight - 80)
            Y += 5 * speed;
        else
            Y = windowHeight - 80;
    }
    //Move LEFT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (X >= 10)
            X -= 5 * speed;
        else
            X = 10;
    }
    //Cheat
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        game->setBulletFrequency(35);
    }
    sprite.setPosition(X, Y);
}

void Player::rotate(Game* game) {
    int x = game->getMouse().getPosition(game->getWindow()).x;
    int y = game->getMouse().getPosition(game->getWindow()).y;

    //Calculate angle
    float angle = atan2(y - Y, x - X);
    angle *= 180 / PI;

    sprite.setRotation(angle + 90);

    //std::cout << "Player " << "x: " << playerX << " " << "y: " << playerY << std::endl;
    //std::cout << "Mouse " << "x: " << x << " " << "y: " << y << std::endl;
    //std::cout << angle << std::endl;
}

bool Player::shoot() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return true;
    }
    return false;
}

void Player::kill() {
    if(buffer.loadFromFile("../assets/sound/sfx/WilhelmScream.ogg")){
        SFX.setBuffer(buffer);
        SFX.setVolume(100);
        SFX.play();
    }
    usleep(1000000);
    std::cout << "\nYou got killed by a zombie :(" << std::endl;
}