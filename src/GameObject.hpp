#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
class Player; 

class GameObject: public sf::Drawable{
    protected:
        std::string id;
        bool collideable;
        //Might not use this?
        bool render;
    public:
        GameObject() { id = "";render=true;}
        bool canCollide() { return collideable;}
        virtual sf::FloatRect getGlobalBounds() {return sf::FloatRect(0,0,0,0);}
        virtual ~GameObject() {} 
        std::string getId() const{ 
            return id;
        }
        virtual void detectCollisions(GameObject *obj) {};
        virtual void update(Player *player) {};
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {};
        virtual sf::Sprite* getSprite() {}; 
};

