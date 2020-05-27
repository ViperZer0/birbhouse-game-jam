#include <SFML/Graphics/Rect.hpp>
#include "GameActor.hpp"
#include "Obstacle.hpp"
#include <iostream>
#include <cmath>
#include "Logger.hpp"
GameActor::GameActor(){
    pos[0] = 0; pos[1] = 0;
    vel[0] = 0;
    vel[1] = 0; 
    acc[0] = 0; 
    acc[1] = 0; 
    jumpVel=5;
    moveSpeed=5;
    fallAcc=1;
    acc[1] = fallAcc;
    jumpDebounce=false;
    falling=false;
    collideRight=false;
    collideLeft=false;

    delta.restart();
}

void GameActor::jump(){
    if(jumpDebounce == false){
        vel[1] = -jumpVel;
        jumpDebounce=true;
    } 
}
void GameActor::right(){ vel[0] = moveSpeed;
}

void GameActor::left(){
    vel[0] = -moveSpeed;
}

void GameActor::stop(){
    vel[0] = 0;
}

/*
void GameActor::update(std::vector<Obstacle> obstacles){j
    float timeElapsed = delta.getElapsedTime().asSeconds();
    for(auto const& obs: obstacles){
        detectCollisions(obs);
    }
    if(falling){
        //positive Y is down
        acc[1] = fallAcc;
        vel[1] += acc[1]*timeElapsed;
        pos[1] += vel[1]*timeElapsed;
    }
    else{
        acc[1] = 0;
        vel[1] = 0;
    }
    pos[0] += vel[0]*timeElapsed;
    sprite->setPosition(pos[0],pos[1]);
    sprite->update();
}
*/
void GameActor::update(){
    float timeElapsed = delta.restart().asSeconds();
    if(falling){
        //positive Y is down
        acc[1]=fallAcc; 
        vel[1] += acc[1]*timeElapsed;
        pos[1] += vel[1]*timeElapsed;
    }
    else{
        acc[1] = 0;
    }
    if(collideRight)
        if (vel[0] > 0) 
            vel[0] = 0;
    
    if(collideLeft)
        if (vel[0] < 0) 
            vel[0] = 0;
    if(bonking)
        if(vel[1] < 0) 
            vel[1] = 0;

    pos[0] += vel[0]*timeElapsed;
    sprite->setPosition(pos[0],pos[1]);
    sprite->update();
}

void GameActor::setSprite(AnimatedSprite *sprite){
    this->sprite = sprite;
}

void GameActor::setTexture(sf::Texture *tex){
    sprite->setTexture(tex);
    }
void GameActor::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(*sprite);
}

Direction GameActor::getDirection(sf::FloatRect self,sf::FloatRect other){
    if (self.left + self.width < other.left) return Direction::left;
    if (self.left > other.left + other.width) return Direction::right;
    if (self.top + self.height < other.top) return Direction::up;
    if (self.top > other.top + other.height) return Direction::down;
    return Direction::collide;
}

void GameActor::detectCollisions(GameObject *obj){
    float timeElapsed = delta.getElapsedTime().asSeconds();
    sf::FloatRect cur = getGlobalBounds();
    sf::FloatRect next = sf::FloatRect( \
            cur.left + vel[0]*timeElapsed,\
            //Incorporate gravity here?
            cur.top + vel[1]*timeElapsed + 1/2*acc[1]*pow(timeElapsed,2), \
            cur.width, \
            cur.height);
    Direction currentCol = getDirection(cur,obj->getGlobalBounds());
    Direction nextCol = getDirection(next,obj->getGlobalBounds());
    Logger::log(Log::DEBUG,"Cur: ",cur);
    Logger::log(Log::DEBUG,"Next: ", next);
    if (nextCol == Direction::collide){
        std::cout << "AGH" << std::endl;
        switch(currentCol){
            case Direction::left:
                collideLeft = true;
                break;

            case Direction::right:
                collideRight = true;
                break;
                
            case Direction::up:
                jumpDebounce=false;
                falling=false;
                break;
            case Direction::down:
                bonking=true;
                break;
            case Direction::collide:
                //whoops we broke shit this is NOT good.
                break;
            default:
                //Also not good.
                break;

        }
    }
}
