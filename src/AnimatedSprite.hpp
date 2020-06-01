#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "AnimationSequence.hpp"

class AnimatedSprite: public sf::Drawable{
    private:
        sf::Texture *tex;
        sf::Sprite sprite;
        AnimationSequence* animation;

    public:
        AnimatedSprite();
        AnimatedSprite(sf::Texture *tex);
        ~AnimatedSprite(){
            delete animation;
        }
        void setTexture(sf::Texture *tex);
        void setAnimationSeq(AnimationSequence* seq);
        sf::Sprite getSprite();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        void setPosition(float x, float y){
            sprite.setPosition(x,y);
        }

        sf::FloatRect getGlobalBounds(){
            return sprite.getGlobalBounds();
        }
        
        int getFrame();

        void update();
};

