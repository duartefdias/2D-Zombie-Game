//
// Created by bob on 23-05-2018.
// Example for implementing factory methods:
// https://sourcemaking.com/design_patterns/factory_method/cpp/1
//

#ifndef ZOMBIEGAME_POWERUP_H
#define ZOMBIEGAME_POWERUP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unistd.h>
#include <iostream>
#include <math.h>
#include <memory>
#include <bits/shared_ptr.h>

#include "Game.h"

enum poweUpType {ammo, zombieOverload};

class PowerUp{
public:
    PowerUp(std::shared_ptr<Game> game);

    //This is a factory method
    //It creates different PowerUps based on the "type"
    static std::shared_ptr<PowerUp> makePowerUp(std::shared_ptr<Game> game, int type);

    int getX();
    int getY();

    virtual void startPower(std::shared_ptr<Game> game){};
    virtual void endPower(std::shared_ptr<Game> game){};

    void renderSprite(std::shared_ptr<Game> game);

protected:

    //Position
    int X;
    int Y;

    //Sprite
    sf::Sprite sprite;
    sf::Texture spriteTexture;

    //Sound effect
    sf::SoundBuffer buffer;
    sf::Sound SFX;
};

#endif //ZOMBIEGAME_POWERUP_H
