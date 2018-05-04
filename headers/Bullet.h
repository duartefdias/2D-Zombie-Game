#ifndef BULLET_H
#define  BULLET_H

#include "../headers/Game.h"
#include <SFML/Graphics.hpp>

class Bullet{
public:
    Bullet(int startX, int startY, int endX, int endY);

    void move(int speed = 1);

    //void createBullet(List* bulletList);
    void renderSprite(Game* game);

    int getBulletX();
    int getBulletY();

private:
    int bulletX;
    int bulletY;

    float moveX;
    float moveY;

    sf::CircleShape sprite;

    Bullet* bulletAux;

};

//LIST TO STORE BULLETS
/*struct bulletNode {
    Bullet *bullet;
    bulletNode *next;
};*/

class bulletNode {
public:
    Bullet *bullet;
    bulletNode *next;
};

 class BulletList{
 public:

     BulletList();

     void insertNodeEnd(Bullet* newBullet);
     bulletNode* getNextNode(bulletNode* node);
     void deleteNode(bulletNode* previousNode, bulletNode* node);

     bulletNode* getHead();
     bulletNode* getTail();

     //TODO:~BulletList();


 private:

     bulletNode *head, *tail;

 };

#endif //BULLET_H
