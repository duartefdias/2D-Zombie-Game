//
// Created by bob on 23-05-2018.
//

#ifndef ZOMBIEGAME_POWERUP_H
#define ZOMBIEGAME_POWERUP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unistd.h>
#include <iostream>
#include <math.h>

#include "Game.h"
#include "Powers.h"

class PowerUp{
public:
    PowerUp(Game* game);

    static PowerUp *makePowerUp(Game* game, int type);

    int getX();
    int getY();

    virtual void startPower(Game* game){};
    virtual void endPower(Game* game){};

    void renderSprite(Game* game);

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
