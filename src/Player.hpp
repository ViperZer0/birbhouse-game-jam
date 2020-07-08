#pragma once
#include <SFML/Window/Event.hpp>
#include "AnimatedSprite.hpp"
#include "GameActor.hpp"

class Game;
//Forward declaration
class Equipment;
enum class Slot;
//class PlayerState;
class Player: public GameActor{
    private:
        //Removing playerstate for now, might bring this back
        //PlayerState *state;
        int coins;
        bool pickingUp;
        //bool squatting;
        
        Game *game;
        //Equipment
        Equipment *helmet;
        Equipment *mainHand;
        Equipment *offHand;
        Equipment *foot;

        std::vector<Equipment *> equipment;
        sf::Vector2f equipOffset;

    public:
        Player(Game *g);
        ~Player() {}
        //void setSprite(AnimatedSprite *sprite);
        virtual void update();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void handleInput(sf::Event event);
        void equip(Equipment* equip);
        void pickUp(GameObject *obj);
        void addCoins(int val);
        virtual void flip();
        void swap(Equipment* a, std::vector<Equipment *>::iterator b);
        void linkSlot(Equipment *a);
};

