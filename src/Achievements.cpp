//
// Created by bob on 27-05-2018.
//

#include "../headers/Achievements.h"

void ZombiesKilled::onNotify(Game* game, Event event, int value) {
    //Display message that you killed "value" zombies
    if(event == zombiesKilled && (value % 10) == 0){
        std::cout << "Wow! You killed " << value << " zombies!" << std::endl;
    }

}