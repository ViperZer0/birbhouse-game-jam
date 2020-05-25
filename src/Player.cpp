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
    jumpVel=50;
    moveSpeed=50;
    fallAcc=10;
    jumpDebounce=false;
    falling=false;
    collideRight=false;
    collideLeft=false;
    delta.restart();

    //Setup player
    sprite = new AnimatedSprite();
    AnimationSequence *squat;
    squat = new AnimationSequence();
    squat->addFrame(sf::IntRect(0,0,130,200),sf::milliseconds(500));
    squat->addFrame(sf::IntRect(130,0,130,200),sf::milliseconds(500));
    squat->setBidirectional(false);
    sprite->setAnimationSeq(squat);
    sprite->getSprite().setPosition(sf::Vector2f(500.f,400.f));
}

void Player::handleInput(sf::Event event){
    if(event.type == sf::Event::KeyPressed){
        switch(event.key.code){
            case sf::Keyboard::Right:
                right();
                break;

            case sf::Keyboard::Left:
                left();
                break;
            default:
                break;
        }
    }
}

