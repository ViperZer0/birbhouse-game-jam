#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AnimatedSprite.hpp"
class GameActor: public sf::Drawable{
    protected:
       int pos[2]; //pixel
        int vel[2]; //pixels per second
        int acc[2]; //Pixels per second^2
        int jumpVel;
        int fallAcc;
        int moveSpeed;
        bool jumpDebounce;
        //Note we don't actually handle collisions in this function, we're gonna have children that do this.
        bool falling;
        bool collideRight;
        bool collideLeft;
        sf::Clock delta;
        
        AnimatedSprite *sprite;
    public:
        GameActor();
        void jump();
        void right();
        void left();
        void stop();
        void update();
        void setTexture(sf::Texture *tex);
        void setSprite(AnimatedSprite *sprite);
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
