//
// Created by bob on 27-05-2018.
//

#include "../headers/Achievements.h"
#include "../headers/Game.h"

void ZombiesKilled::onNotify(Game* game, Event event, int value) {

    if(!runOnce){
        if(!this->getTextFont().loadFromFile("../assets/fonts/Raleway-Medium.ttf")) {
            std::cout << "\nProblem loading game.displayTextFont" << std::endl;
        }
        displayText.setCharacterSize(30);
        displayText.setFillColor(sf::Color::Red);
        displayText.setStyle(sf::Text::Bold);
        displayText.setOrigin(1100, 15);
        displayText.setPosition(1170, 15);
        displayText.setFont(textFont);
    }

    if(event == zombiesKilled){

        if(value == 0){
            text = "The zombies are coming!";
        }
        else if(value == 10){
            //You killed your first 10 zombies!
            text = "You killed your first 10 zombies!";
        }
        else if(value == 30){
            text = "Zombies are coming faster!";
        }
        else if((value % 100) == 0){
            //"value" kills! You are a master zombie slayer!
            text = std::to_string(value);
            text += " kills! You're a master zombie slayer!";
        }
        else if((value % 20) == 0){
            //Wow!! You killed "value" zombies!!
            std::cout << "Wow! You killed " << value << " zombies!" << std::endl;
            text = "Wow! You killed ";
            text += std::to_string(value);
            text += " zombies!";
        }
        displayText.setString(text);
        displayText.setOrigin(displayText.getLocalBounds().width, 0);
        game->getWindow().draw(displayText);
        runOnce = true;
    }

}

void TimeSurvived::onNotify(Game *game, Event event, int value) {

    if(event == timeSurvived){
        if(value > 5){
            std::cout << "You survived for " << value << " seconds!" << std::endl;
        }
    }
}