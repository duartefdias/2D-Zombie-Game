#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../headers/Game.h"
#include "../headers/Bullet.h"
#include "../headers/Player.h"
#include <SFML/Graphics.hpp>


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
    sf::CircleShape sprite;

    //Player direction
    float moveX;
    float moveY;

    int dead;

};

#endif // ZOMBIE_H
