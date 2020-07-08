#include "Equipment.hpp"
#include "Logger.hpp"

void Equipment::handleInput(sf::Event event){
}

void Equipment::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(sprite);
}

void Equipment::flip(){
    /*
    sf::Vector2f off = sprite.getOrigin();
    sf::Vector2f bounds = sf::Vector2f(\
            sprite.getGlobalBounds().width,\
            sprite.getGlobalBounds().height);
    Logger::log(Log::DEBUG,"Bounds:",bounds/2.f);    
    sprite.setOrigin(bounds/2.f);
    Logger::log(Log::DEBUG,"Origin:",sprite.getOrigin());
    sprite.scale(-1.f,1.f);
    //sprite.setOrigin(off);
    Logger::log(Log::DEBUG,"Origin:",sprite.getOrigin());
    */
    sprite.scale(-1.f,1.f);
}

void Equipment::update(){
    if(wearer)
        Logger::log(Log::DEBUG,"wearer->getOffset():",wearer->getOffset());

    if(inHand){
        if(wearer->isFlipped()){
            sprite.setPosition(wearer->getSprite()->getGlobalBounds().left + wearer->getSprite()->getGlobalBounds().width - offset.x,wearer->getSprite()->getGlobalBounds().top + offset.y);
        }
        else{
            Logger::log(Log::DEBUG,"STUFF");
            Logger::log(Log::DEBUG,wearer->getSprite()->getGlobalBounds());
            Logger::log(Log::DEBUG,offset);
            sprite.setPosition(wearer->getSprite()->getGlobalBounds().left + offset.x,wearer->getSprite()->getGlobalBounds().top + offset.y);
        }
    }
}

void Equipment::equipped(GameActor *equipper){
    wearer = equipper;
    pickedUp = true;
    inHand = true;
}

void Equipment::dropped(){
    wearer = nullptr;
    inHand=false;
}

Slot Equipment::getSlot(){
    return slot;
}

int Equipment::getValue(){
    return value;
}

bool Equipment::getPickedUp(){
    return pickedUp;
}
