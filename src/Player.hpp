#pragma once
#include <SFML/Window/Event.hpp>
#include "AnimatedSprite.hpp"
#include "GameActor.hpp"

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
        //EQUIPMENT (keep this as a backup, I think I have a better idea.)
        /*
        Shield *shield;
        Melee *melee;
        Ranged *ranged;
        Helmet *helmet;
        Boots *boots;
        */

        std::vector<Equipment *> equipment;
        sf::Vector2f equipOffset;

    public:
        Player();
        ~Player() {}
        //void setSprite(AnimatedSprite *sprite);
        virtual void update(Player *player);
        void handleInput(sf::Event event);
        void equip(Equipment* equip);
        void pickUp(GameObject *obj);
        void addCoins(int val);
        void swap(Equipment* a, std::vector<Equipment *>::iterator b);
        sf::Vector2f getOffset() {return equipOffset;}

};

