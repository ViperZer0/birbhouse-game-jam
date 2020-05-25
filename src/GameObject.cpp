#include "GameObject.hpp"

GameObject::GameObject(){
    pos[0] = 0;
    pos[1] = 0;
    vel[0] = 0;
    vel[1] = 0;
    acc[0] = 0;
    acc[1] = 0;
    jumpVel=50;
    moveSpeed=50;
    fallAcc=10;
    jumpDebounce=false;
    falling=false;
    collideRight=false;
    collideLeft=false;

    delta.restart();
}

void GameObject::jump(){
    if(jumpDebounce == false){
        vel[1] +=  jumpVel;
        falling=true;
        jumpDebounce=true;
    }
}

void GameObject::right(){
    vel[0] = moveSpeed;
}

void GameObject::left(){
    vel[0] = -moveSpeed;
}

void GameObject::stop(){
    vel[0] = 0;
}

void GameObject::update(){
    float timeElapsed = delta.getElapsedTime().asSeconds();
    if(falling){
        acc[1] = -fallAcc;
        vel[1] += acc[1]*timeElapsed;
        pos[1] += vel[1]*timeElapsed;
    }
    else{
        acc[1] = 0;
        vel[1] = 0;
    }
    pos[0] += vel[0]*timeElapsed;
}
