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
#include "../headers/PowerUp.h"
#include "../headers/Achievements.h"

int main()
{
    //Create Window
    Game* game = new Game(1200, 900);

    //Create a rectangle for the background and set a texture for it
    game->setupBackground("../assets/textures/background1.jpg", 1200, 900);

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
    int bulletFrequency = 300; //In milliseconds (1000 milliseconds = 1 second)zz

    //List of bullets
    std::list<Bullet*> bullets;

    //Game Clock for zombies
    sf::Clock clockZombies;
    sf::Time elapsedTimeZombies;
    int zombieFrequency = 1000; //In milliseconds (1000 milliseconds = 1 second)

    //List of zombies
    std::list<Zombie*> zombies;

    //PowerUp
    PowerUp* powerUp; //NEW
    sf::Clock clockPowerUp;
    sf::Time elapsedTimePowerUp;
    bool powerUpOnMap = false;
    sf::Clock clockPowerUpSpawn;
    sf::Time elapsedTimePowerUpSpawn;
    int powerUpSpawnDelay = 2000; //In milliseconds

    game->addObserver(new ZombiesKilled);

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

        if(powerUpOnMap){
            powerUp->renderSprite(game);
        }

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
            //(*it)->move(player, game, 2);
            (*it)->getMovementStrategy()->doMove(player, game, (*it), 2);//NEW
        }

        game->getWindow().display();

        //W, D, S, A movement keys
        player->move(game);
        player->rotate(game);

        //Fire shots
        if(player->shoot()) {
            elapsedTime = clock.getElapsedTime();
            if((int) elapsedTime.asMilliseconds() > game->getBulletFrequency()) {
                Bullet* toShoot = new Bullet(player->getX(), player->getY(), game->getMouse().getPosition(game->getWindow()).x, game->getMouse().getPosition(game->getWindow()).y);
                bullets.push_back(toShoot);
                game->bulletSFX();
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
        if ((int) elapsedTimeZombies.asMilliseconds() > game->getZombieFrequency()) {
            if(zombieFrequency > 100) {
                zombieFrequency -= 10;
            }
            Zombie* toSpawn = new Zombie(randomize, player, game, toSpawn, 1); //NEW
            toSpawn->movementStrategy->sayHi();
            zombies.push_back(toSpawn);
            game->incrementZombiesSpawned();
            clockZombies.restart();
            std::cout << "Zombie " << game->getZombiesSpawned() + 1 << " created! Run!" << std::endl;

        }

        //Check Zombie <-> Bullet collision and eliminate both
        //Compares every zombie to every bullet
        for(std::list<Zombie*>::iterator itZombie = zombies.begin(); itZombie != zombies.end(); ++itZombie){
            for(std::list<Bullet*>::iterator itBullet = bullets.begin(); itBullet != bullets.end(); ++itBullet){
                if((*itZombie) != nullptr && (*itBullet) != nullptr){
                    if((*itZombie)->getX() > (*itBullet)->getBulletX() - 40 &&  (*itZombie)->getX() < (*itBullet)->getBulletX() + 40){
                        if((*itZombie)->getY() > (*itBullet)->getBulletY() - 40 &&  (*itZombie)->getY() < (*itBullet)->getBulletY() + 40){
                            //Deletion of bullet
                            delete (*itBullet);
                            itBullet = bullets.erase(itBullet); //remove from the list and take next
                            //Deletion of zombie
                            delete (*itZombie);
                            itZombie = zombies.erase(itZombie); //remove from the list and take next
                            game->zombieSFX();
                            game->incrementGameScore();
                            game->incrementZombiesKilled();
                            if(itZombie == zombies.end()){
                                itZombie = zombies.begin(); //This prevents segmentation fault
                            }
                            game->notify(zombiesKilled, game->getZombiesKilled());
                        }
                    }
                }
            }
        }

        //Check Zombie <-> Player collision and kill Player
        //Iterates through every zombie and compares it to the player's position
        for(std::list<Zombie*>::iterator itZombie = zombies.begin(); itZombie != zombies.end(); ++itZombie){
            if((*itZombie)->getX() > player->getX() - 40 &&  (*itZombie)->getX() < player->getX() + 40){
                if((*itZombie)->getY() > player->getY() - 40 &&  (*itZombie)->getY() < player->getY() + 40){
                    player->kill();
                    std::cout << "Your score was: " << game->getGameScore() << std::endl;
                    return 0;
                }
            }
        }

        //Makes zombies aggressive when close to the player
        for(std::list<Zombie*>::iterator itZombie = zombies.begin(); itZombie != zombies.end(); ++itZombie){
            if((*itZombie)->getX() > player->getX() - 300 &&  (*itZombie)->getX() < player->getX() + 300){
                if((*itZombie)->getY() > player->getY() - 300 &&  (*itZombie)->getY() < player->getY() + 300){
                    //(*itZombie)->becomeOffensive();
                    (*itZombie)->setMovementStrategy(offensive, player, game, (*itZombie), 1); //NEW
                }
            }
        }

        //Place a PowerUp on the map every "powerUpSpawnDelay/1000" seconds
        elapsedTimePowerUpSpawn = clockPowerUpSpawn.getElapsedTime();
        if((int) elapsedTimePowerUpSpawn.asMilliseconds() > powerUpSpawnDelay && !powerUpOnMap){
            //Randomly picks a type of PowerUp
            int powerType = rand() % 2;
            powerUp = PowerUp::makePowerUp(game, powerType);
            powerUpOnMap = true;
            clockPowerUpSpawn.restart();
        }

        if(powerUpOnMap){
            //Player picks up PowerUp
            if(powerUp->getX() > player->getX() - 40 && powerUp->getX() < player->getX() + 40){
                if(powerUp->getY() > player->getY() - 40 && powerUp->getY() < player->getY() + 40){
                    std::cout << "POWERUP!!" << std::endl;
                    powerUp->startPower(game);
                }
            }
        }

        if(powerUpOnMap){
            //PowerUp ends after a few seconds
            elapsedTimePowerUp = clockPowerUp.getElapsedTime();
            if((int) elapsedTimePowerUp.asMilliseconds() > 4000){
                powerUp->endPower(game);
                clockPowerUp.restart();
                powerUpOnMap = false;
            }
        }

        //zombie->movementStrategy->move();

    } //End of game loop

    return 0;
}