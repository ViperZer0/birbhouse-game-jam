#pragma once
#include "Item.hpp"

enum class Slot{HEAD,OFFHAND,MAINHAND,FOOT};

class Equipment: public Item{
    protected:
        bool pickedUp;
        bool inHand;
        int value;
        Slot slot;
        //Determine where to put the sprite on the birb
        //
        sf::Vector2f offset;
        GameActor *wearer;
    public:
        Equipment() {pickedUp=false;id = "equipment";inHand=false;value = 0;wearer=nullptr;}
        virtual void handleInput(sf::Event event);
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        virtual void update();
        virtual void equipped(GameActor *equipper);
        virtual void dropped();
        void flip();

        Slot getSlot();
        int getValue();
        bool getPickedUp();
};
