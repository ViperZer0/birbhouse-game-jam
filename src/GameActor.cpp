#include "GameActor.hpp"
#include "Obstacle.hpp"
#include <iostream>
#include <cmath>
#include "Logger.hpp"
GameActor::GameActor(){
    pos[0] = 0;
    pos[1] = 0;
    vel[0] = 0;
    vel[1] = 0;
    acc[0] = 0;
    acc[1] = 0;
    jumpVel=500;
    moveSpeed=500;
    fallAcc=500;
    acc[1] = fallAcc;
    jumpDebounce=false;
    falling=true;
    collideRight=false;
    collideLeft=false;

    delta.restart();
}

void GameActor::jump(){
    if(jumpDebounce == false){
        vel[1] = -jumpVel;
        jumpDebounce=true;
    } }
void GameActor::right(){
    if(!collideRight)
        vel[0] = moveSpeed;
}

void GameActor::left(){
    if(!collideLeft)
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
void GameActor::hitTimer(){
    timeElapsed = delta.getElapsedTime().asSeconds();
}

void GameActor::resetTimer(){
    delta.restart();
}

void GameActor::update(){
    Logger::log(Log::DEBUG,"Vel:", vel, "Acc:", acc);
    if(falling){
        //positive Y is down
        acc[1]=fallAcc; 
        vel[1] += acc[1]*timeElapsed;
        pos[1] += vel[1]*timeElapsed;
    }
    else{
        acc[1] = 0;
    }
    if(collideLeft)
        if (vel[0] > 0)
            vel[0] = 0;
    if(collideRight)
        if (vel[0] < 0) 
            vel[0] = 0;
    if(bonking)
        if(vel[1] < 0) 
            vel[1] = 0;

    pos[0] += vel[0]*timeElapsed;
    sprite->setPosition(pos[0],pos[1]);
    sprite->update();
    //Reset collisions for next loop
    falling=true;
    bonking=false;
    collideRight=false;
    collideLeft=false;
    resetTimer();
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
    hitTimer();
    sf::FloatRect cur = getGlobalBounds();
    Logger::log(Log::DEBUG,"Vel:",vel);
    sf::FloatRect next = sf::FloatRect( \
            //Assume movement because if we base it off current velocity it might be 0. No wait we can't do that I guess.
            cur.left + vel[0]*timeElapsed,\
            //Incorporate gravity here?
            cur.top + vel[1]*timeElapsed + 1.0/2.0*fallAcc*pow(timeElapsed,2), \
            cur.width,\
            cur.height\
            );

    Direction currentCol = getDirection(cur,obj->getGlobalBounds());
    Direction nextCol = getDirection(next,obj->getGlobalBounds());
    Logger::log(Log::DEBUG,"timeElapsed:", timeElapsed);
    Logger::log(Log::DEBUG,"Acceleration:", 1.0/2.0*fallAcc*timeElapsed*timeElapsed);
    Logger::log(Log::DEBUG,"fallAcc:",fallAcc, " Calculated drop: ", vel[1]*timeElapsed + 1.0/2.0*fallAcc*timeElapsed*timeElapsed);
    Logger::log(Log::DEBUG,"Cur: ",cur);
    Logger::log(Log::DEBUG,"Next: ", next);
    Logger::log(Log::DEBUG,"currentCol:", currentCol);
    Logger::log(Log::DEBUG,"nextCol:", nextCol);

    if (nextCol == Direction::collide){
        Logger::log(Log::DEBUG,"Colliding!");
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
                Logger::log(Log::WARNING,"GameActor got Direction::collide. Probably something got stuck inside something else.");
                //whoops we broke shit this is NOT good.
                break;
            default:
                Logger::log(Log::WARNING,"This message should NEVER appear.");
                //Also not good.
                break;

        }
    }
}

std::ostream& operator<<(std::ostream& os, Direction direction){
    switch(direction){
        case Direction::left:
            os << std::string("LEFT");
            break;
        case Direction::right:
            os << std::string("RIGHT");
            break;
        case Direction::up:
            os << std::string("UP");
            break;
        case Direction::down:
            os << std::string("DOWN");
            break;
        case Direction::collide:
            os << std::string("COLLIDE");
            break;
        default:
            os << std::string("NONE");
            break;
    }
    return os;
}


