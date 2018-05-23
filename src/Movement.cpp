//
// Created by bob on 23-05-2018.
//

#include <cstdlib>
#include "../headers/Movement.h"

Movement::Movement() {
    int choice = rand() % 5;

    if(choice < 3){
        offensive = false;
    }
    else{
        offensive = true;
    }
};

void Movement::move(Player* player, int speed){
    switch(offensive){
        case false:

            break;
        case true:

            break;
    }
}