#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../headers/Game.h"
#include "../headers/Zombie.h"
#include "../headers/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Zombie {
public:

    Zombie(Game* game);

    void renderSprite(Game* game);

    void move(Player* player, int speed = 1);

    int getZombieX();
    int getZombieY();

    void kill(Game* game);
    int isDead();

private:

    //Player position
    int zombieX;
    int zombieY;

    //Sprite
    sf::Sprite sprite;
    sf::Texture spriteTexture;

    //Player direction
    float moveX;
    float moveY;

    int dead;

    sf::SoundBuffer buffer;
    sf::Sound deathSFX;

};

class zombieNode {
public:
    Zombie *zombie;
    zombieNode *next;
};

 class ZombieList{
 public:

     ZombieList();

     void insertNodeEnd(Zombie* newZombie);
     zombieNode* getNextNode(zombieNode* node);
     zombieNode* deleteNode(zombieNode* node);

     zombieNode* getHead();
     zombieNode* getTail();

     //TODO:~ZombieList();


 private:

     zombieNode *head, *tail;

 };

#endif // ZOMBIE_H
