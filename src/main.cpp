#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <list>

#include "../headers/Game.h"
#include "../headers/GameCharacter.h"
#include "../headers/Player.h"
#include "../headers/Bullet.h"
#include "../headers/Zombie.h"

int main()
{
    //Create Window
    Game* game = new Game(900, 700);

    //Create a rectangle for the background and set a texture for it
    game->setupBackground("../assets/textures/background1.jpg", 900, 700);

    //Need to define texture here because of "The white square problem"
    //https://www.sfml-dev.org/tutorials/2.1/graphics-sprite.php#the-white-square-problem
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("../assets/textures/background1.jpg")) {
        std::cout << "\nError loading texture!" << std::endl;
    }
    game->getBackground().setTexture(&bgTexture);

    //Set scoreText styles
    game->setScoreText();
    if(!game->getScoreTextFont().loadFromFile("../assets/fonts/Raleway-Medium.ttf")) {
        std::cout << "\nProblem loading game.scoreTextFont" << std::endl;
    }
    game->getScoreText().setFont(game->getScoreTextFont());

    //Set scoreString styles
    game->setScoreString(game->getGameScore());
    if(!game->getScoreStringFont().loadFromFile("../assets/fonts/Raleway-Medium.ttf")) {
        std::cout << "\nProblem loading game.scoreTextFont" << std::endl;
    }
    game->getScoreString().setFont(game->getScoreStringFont());

    //Create player
    Player* player = new Player((game->getWindow().getSize().x)/2, (game->getWindow().getSize().y)/2);
    player->setupSprite();

    //Game Clock for bullets
    sf::Clock clock;
    sf::Time elapsedTime;

    //List of bullets
    std::list<Bullet*> bullets;

    //Game Clock for zombies
    sf::Clock clockZombies;
    sf::Time elapsedTimeZombies;
    int zombieFrequency = 1000; //In milliseconds (1000 milliseconds = 1 second)

    //List of zombies
    std::list<Zombie*> zombies;

    //Number zombies created
    int zombieIndex = 0;

    while (game->getWindow().isOpen())
    {
        sf::Event event;
        while(game->getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed)
                game->getWindow().close();
        }

        //Everything that needs to be drawn goes between clear() and display()
        game->getWindow().clear();
        game->renderBackground();
        game->renderScoreText();
        game->renderScoreString();
        player->renderSprite(game);

        //Draw all bullets
        for(std::list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it){
            (*it)->renderSprite(game);
            (*it)->move(10);
        }

        //Draw all zombies
        for(std::list<Zombie*>::iterator it = zombies.begin(); it != zombies.end(); ++it){
            (*it)->renderSprite(game);
            (*it)->move(player, 2);
        }

        game->getWindow().display();

        //W, D, S, A movement keys
        player->move(game);
        player->rotate(game);

        //Fire shots
        if(player->shoot()) {
            elapsedTime = clock.getElapsedTime();
            if((int) elapsedTime.asMilliseconds() > 200) {
                Bullet* toShoot = new Bullet(player->getX(), player->getY(), game->getMouse().getPosition(game->getWindow()).x, game->getMouse().getPosition(game->getWindow()).y);
                bullets.push_back(toShoot);
                clock.restart();
                std::cout << "BAAAAAM" << std::endl;
            }
        }

        //Remove bullets that are out of the screen
        for(std::list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it){
            if((*it)->isOutOfScreen(game)){
                delete (*it);
                bullets.erase(it++); //remove from the list and take next
            }
        }

        //Create new zombie every 2 seconds
        elapsedTimeZombies = clockZombies.getElapsedTime();
        if ((int) elapsedTimeZombies.asMilliseconds() > zombieFrequency) {
            if(zombieFrequency > 100) {
                zombieFrequency -= 10;
            }
            Zombie* toSpawn = new Zombie(game);
            zombies.push_back(toSpawn);
            zombieIndex += 1;
            clockZombies.restart();
            std::cout << "Zombie " << zombieIndex + 1 << " created! Run!" << std::endl;
        }

        //Check Zombie <-> Bullet collision and eliminate both
        for(std::list<Zombie*>::iterator itZombie = zombies.begin(); itZombie != zombies.end(); ++itZombie){
            for(std::list<Bullet*>::iterator itBullet = bullets.begin(); itBullet != bullets.end(); ++itBullet){
                if((*itZombie)->getX() > (*itBullet)->getBulletX() - 40 &&  (*itZombie)->getX() > (*itBullet)->getBulletX() + 40){
                    if((*itZombie)->getY() > (*itBullet)->getBulletY() - 40 &&  (*itZombie)->getY() > (*itBullet)->getBulletY() + 40){
                        delete (*itBullet);
                        bullets.erase(itBullet++); //remove from the list and take next
                        delete (*itZombie);
                        zombies.erase(itZombie++); //remove from the list and take next
                    }
                }
            }
        }




    } //End of game loop

    return 0;
}