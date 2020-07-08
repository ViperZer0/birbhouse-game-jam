#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.hpp"
#include "Player.hpp"

class Item: public GameObject{
    protected:
        sf::Sprite sprite;
    public:
        Item() {id = "item";collideable=false;}
        virtual sf::FloatRect getGlobalBounds(){
            return sprite.getGlobalBounds();
        }

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const{
            target.draw(sprite);
        }
        
        //IDK what to do about this but I'll fix it later. Might just have to go the other way around with players detecting game objects again A
        virtual void detectCollisions(GameObject *obj){
            if(obj->getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds())){
                if(obj->getId() == std::string("player")){
                    //Forgive me, father, for i have sinned
                    Player *player = static_cast<Player*>(obj);
                    player->pickUp(this);
                }
            }
        }
};

