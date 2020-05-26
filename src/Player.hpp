#pragma once
#include <SFML/Window/Event.hpp>
#include "AnimatedSprite.hpp"
#include "GameActor.hpp"
//class PlayerState;
class Player: public GameActor{
    private:
        //Removing playerstate for now, might bring this back
        //PlayerState *state;
    public:
        Player();
        ~Player() {}
        void setSprite(AnimatedSprite *sprite);
        void handleInput(sf::Event event);

};

