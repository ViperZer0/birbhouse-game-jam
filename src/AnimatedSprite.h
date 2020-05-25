#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "AnimationSequence.h"

class AnimatedSprite: public sf::Drawable{
    private:
        sf::Texture *tex;
        sf::Sprite sprite;
        std::vector<AnimationSequence*> animations;
        unsigned int currentSeq;
    public:
        AnimatedSprite();
        AnimatedSprite(sf::Texture *tex);
        void setTexture(sf::Texture *tex);
        void addAnimationSequence(AnimationSequence* seq);
        void setAnimationSeq(int currentSeq); 
        sf::Sprite getSprite();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void update();
};

