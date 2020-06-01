#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AnimatedSprite.hpp"
#include "Obstacle.hpp"
#include "GameObject.hpp"

enum class Direction{left,right,up,down,collide};

class GameActor: public GameObject{
    protected:
       float pos[2]; //pixel
        float vel[2]; //pixels per second
        float acc[2]; //Pixels per second^2
        float jumpVel;
        float fallAcc;
        float moveSpeed;
        bool jumpDebounce;
        //Note we don't actually handle collisions in this function, we're gonna have children that do this.
        bool bonking;
        bool falling;
        bool collideRight;
        bool collideLeft;

        sf::Clock delta;
        float timeElapsed;
        
        AnimatedSprite *sprite;
    public:
        GameActor();

        ~GameActor(){
            delete sprite;
        }
        void jump();
        void right();
        void left();
        void stop();
        virtual void update(Player *player);
        virtual sf::FloatRect getGlobalBounds(){
            return sprite->getGlobalBounds();
        }
        Direction getDirection(sf::FloatRect self,sf::FloatRect other);
        void hitTimer();
        void resetTimer();
        void detectCollisions(GameObject *obj);
        void setTexture(sf::Texture *tex);
        void setSprite(AnimatedSprite *sprite);
        
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        virtual sf::Sprite getSprite();
};

std::ostream& operator<<(std::ostream& os, Direction direction);


