#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.hpp"

class Obstacle: public GameObject{
    private:
        sf::Sprite sprite;
    public:
        Obstacle(sf::Texture *tex, sf::FloatRect bounds){
            id = "obstacle";
            sprite.setTexture(*tex);
            sprite.setTextureRect(sf::IntRect(260,0,100,100));
            sprite.setPosition(bounds.left,bounds.top);
            sf::FloatRect currentBounds;
            currentBounds = sprite.getGlobalBounds();
            sprite.setScale(bounds.width/currentBounds.width,bounds.height/currentBounds.height);
            collideable=true;
        }
        
        virtual ~Obstacle(){}
        
        virtual sf::FloatRect getGlobalBounds(){
            return sprite.getGlobalBounds();
        }

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
            target.draw(sprite);
        }
};

