#include "Sword.hpp"

Sword::Sword(sf::Texture *tex,sf::Vector2f position){
    slot = Slot::MAINHAND;
    sprite.setTexture(*tex);
    sprite.setTextureRect(sf::IntRect(390,0,57,200));
    sprite.setOrigin(57/2.f,200/2.f);
    offset = sf::Vector2f(127,98);
    sprite.setPosition(position);
}

void Sword::update(){
    Equipment::update();
    if(inHand){
        if(wearer->isFlipped())
            sprite.setRotation(-90);
        else
            sprite.setRotation(90);
    }
    else{
        sprite.setRotation(0);
    }
}

