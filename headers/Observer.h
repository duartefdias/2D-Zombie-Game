//
// Created by bob on 27-05-2018.
//

#ifndef ZOMBIEGAME_OBSERVER_H
#define ZOMBIEGAME_OBSERVER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

enum Event {zombiesKilled, timeSurvived};

class Game;

class Observer{
public:
    virtual ~Observer() {}
    virtual void onNotify(Game* game, Event event, int amount) = 0;

    sf::Font & getTextFont(){ return textFont; }

protected:

    sf::SoundBuffer buffer;
    sf::Sound SFX;

    sf::Text displayText;
    sf::Font textFont;
};

#endif //ZOMBIEGAME_OBSERVER_H
