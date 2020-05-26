#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

Player::Player(){
    pos[0] = 0;
    pos[1] = 0;
    vel[0] = 0;
    vel[1] = 0;
    acc[0] = 0;
    acc[1] = 0;
    jumpVel=400;
    moveSpeed=200;
    fallAcc=500;
    jumpDebounce=false;
    falling=false;
    collideRight=false;
    collideLeft=false;
    delta.restart();
    id = "player";
    //Setup player
    sprite = new AnimatedSprite();
    AnimationSequence *squat;
    squat = new AnimationSequence();
    squat->addFrame(sf::IntRect(0,0,130,200),sf::milliseconds(500));
    squat->addFrame(sf::IntRect(130,0,130,200),sf::milliseconds(500));
    squat->setBidirectional(false);
    sprite->setAnimationSeq(squat);
    pos[0]=200;
    pos[1]=200;
}

void Player::handleInput(sf::Event event){
    static bool right;
    static bool left;
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Right){
            right = true;
            left = false;
        }
        if(event.key.code == sf::Keyboard::Left)
        {
            left = true;
            right = false;
        }
        if(event.key.code == sf::Keyboard::Space)
            this->jump();
    }
    else if(event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::Right)
            right = false;
        if(event.key.code == sf::Keyboard::Left)
            left = false;
    }

    if(right) this->right();
    else if(left) this->left();
    else this->stop();
}

