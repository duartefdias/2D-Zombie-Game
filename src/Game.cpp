//
// Created by bob on 18-05-2018.
//

#include "../headers/Game.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

Game::Game(int windowWidth, int windowHeight) {
    window.create(sf::VideoMode(windowWidth, windowHeight), "2D Zombies");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    backgroundMusic.setVolume(50);
    backgroundMusic.setLoop(true);
    if (backgroundMusic.openFromFile("../assets/sound/music/escape.ogg")){
        backgroundMusic.play();
    }
}

void Game::setupBackground(std::string fileName, int width, int height) {
    background.setSize(sf::Vector2f(width, height));

    //The white square problem... the code below won't work
    /*sf::Texture bgTexture;
    std::cout << "texture path: " << fileName << std::endl;
    if (!bgTexture.loadFromFile(fileName)) {
        std::cout << "\nError loading texture!" << std::endl;
    }
    background.setTexture(&bgTexture);*/
}

void Game::renderBackground() {
    window.draw(background);
}

sf::RenderWindow & Game::getWindow() {
    return window;
}

sf::RectangleShape & Game::getBackground() {
    return background;
}

void Game::setScoreText() {
    scoreText.setString("Current score: ");
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(20, 15);
}

void Game::renderScoreText() {
    window.draw(scoreText);
}

sf::Text & Game::getScoreText() {
    return scoreText;
}

sf::Font & Game::getScoreTextFont() {
    return scoreTextFont;
}

int Game::getGameScore() {
    return gameScore;
}

void Game::setScoreString(int gameScore) {
    std::string score = std::to_string(gameScore);
    scoreString.setString(score);
    scoreString.setCharacterSize(30);
    scoreString.setFillColor(sf::Color::Red);
    scoreString.setStyle(sf::Text::Bold);
    scoreString.setPosition(250, 15);
}

void Game::renderScoreString() {
    window.draw(scoreString);
}

sf::Text & Game::getScoreString() {
    return scoreString;
}

sf::Font & Game::getScoreStringFont() {
    return scoreStringFont;
}

sf::Mouse & Game::getMouse() {
    return mouse;
}

void Game::incrementGameScore() {
    gameScore++;
    setScoreString(getGameScore());
}

void Game::bulletSFX() {
    if(bulletBuffer.loadFromFile("../assets/sound/sfx/shooting.ogg")){
        shootingSFX.setBuffer(bulletBuffer);
        shootingSFX.setVolume(12);
        shootingSFX.play();
    }
}

void Game::zombieSFX() {
    if(zombieBuffer.loadFromFile("../assets/sound/sfx/zombieDeath.ogg")){
        zombieDeathSFX.setBuffer(zombieBuffer);
        zombieDeathSFX.setVolume(30);
        zombieDeathSFX.play();
    }
}

int Game::getBulletFrequency() {
    return bulletFrequency;
}

int Game::getZombieFrequency() {
    return zombieFrequency;
}

void Game::setBulletFrequency(int value) {
    if(value > 0){
        bulletFrequency = value;
    }
}

void Game::setZombieFrequency(int value) {
    if(value > 0){
        zombieFrequencyAux = zombieFrequency;
        zombieFrequency = value;
    }
}

int Game::getZombieFrequencyAux(){
    return zombieFrequencyAux;
}

void Game::setZombieFrequencyAux(int value){
    zombieFrequencyAux = value;
}

void Game::incrementZombiesSpawned() {
    zombiesSpawned++;
}

void Game::incrementZombiesKilled() {
    numZombiesKilled++;
    //Subject Observer design pattern - notifies all observers
    notify(zombiesKilled, this->getZombiesKilled());
}

int Game::getZombiesSpawned() {
    return zombiesSpawned;
}

int Game::getZombiesKilled() {
    return zombiesKilled;
}

void Game::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Game::removeObserver(Observer *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Game::notify(Event event, int value) {
    for(auto iter = observers.begin(); iter != observers.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->onNotify(shared_from_this(), event, value);
        }
    }
}

int Game::getTimeSurvived() {
    sf::Time elapsedTime = gameClock.getElapsedTime();
    return (int) elapsedTime.asSeconds();
}

void Game::setBulletFrequencyAux(int value) {
    bulletFrequencyAux = value;
}

int Game::getBulletFrequencyAux() {
    return bulletFrequencyAux;
}