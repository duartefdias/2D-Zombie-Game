//
// Created by bob on 18-05-2018.
//

#ifndef ZOMBIEGAME_GAME_H
#define ZOMBIEGAME_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include "Observer.h"

class Game : public std::enable_shared_from_this<Game> {
public:

    Game(int windowWidth = 900, int windowHeight = 700);

    void setupBackground(std::string fileName, int width = 900, int height = 700);
    void renderBackground();

    sf::RenderWindow & getWindow();
    sf::RectangleShape & getBackground();

    void setScoreText();
    void renderScoreText();
    sf::Text & getScoreText();
    sf::Font & getScoreTextFont();

    int getGameScore();
    void setScoreString(int score);
    void renderScoreString();
    sf::Text & getScoreString();
    sf::Font & getScoreStringFont();

    sf::Mouse & getMouse();

    void incrementGameScore();

    //Sound effects
    void bulletSFX();
    void zombieSFX();

    int getBulletFrequency();
    void setBulletFrequency(int value);
    int getBulletFrequencyAux();
    void setBulletFrequencyAux(int value);

    int getZombieFrequency();
    void setZombieFrequency(int value);
    int getZombieFrequencyAux();
    void setZombieFrequencyAux(int value);

    void incrementZombiesSpawned();
    void incrementZombiesKilled();
    int getZombiesSpawned();
    int getZombiesKilled();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void removeAllObservers();
    void notify(Event event, int value);

    int getTimeSurvived();

    void setObserverText(sf::Text text);
    void renderObserverText();

private:
    sf::RenderWindow window;
    sf::RectangleShape background;
    sf::Text scoreText;
    sf::Font scoreTextFont;

    int gameScore = 0;
    sf::Text scoreString;
    sf::Font scoreStringFont;

    sf::Mouse mouse;
    sf::Music backgroundMusic;

    sf::SoundBuffer bulletBuffer;
    sf::Sound shootingSFX;
    sf::SoundBuffer zombieBuffer;
    sf::Sound zombieDeathSFX;

    int bulletFrequency = 300; //In milliseconds (1000 milliseconds = 1 second)
    int bulletFrequencyAux = 300;
    int zombieFrequency = 1000;
    int zombieFrequencyAux = 1000;

    std::list<Observer*> observers; //Vector of observers

    int zombiesSpawned = 0;
    int numZombiesKilled = 0;

    sf::Clock gameClock;

    sf::Text observerText;
};

#endif //ZOMBIEGAME_GAME_H
