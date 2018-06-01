//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_GAMECHARACTER_H
#define ZOMBIEGAME_GAMECHARACTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unistd.h>
#include <iostream>
#include <math.h>

#include "../headers/Game.h"

#define PI 3.14159265

class GameCharacter{
public:

    GameCharacter();
    ~GameCharacter();

    virtual void setupSprite();
    void renderSprite(std::shared_ptr<Game> game);
    sf::Sprite & getSprite();

    int getX();
    int getY();

protected:

    //Player position
    int X;
    int Y;

    //Sprite
    sf::Sprite sprite;
    sf::Texture spriteTexture;

    //Death sound effect
    sf::SoundBuffer buffer;
    sf::Sound SFX;
};

#endif //ZOMBIEGAME_GAMECHARACTER_H
