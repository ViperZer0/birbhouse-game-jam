#include "Game.h"
#include "AnimatedSprite.h"

Game::Game(){
    window.create(sf::VideoMode(800,600), "Birbhous Game Jam");
    running=true;
    tilemap= new sf::Texture;
    tilemap->loadFromFile("res/tilemap.png");
    player.setTexture(tilemap);
    AnimationSequence *squat;
    squat = new AnimationSequence();
    squat->addFrame(sf::IntRect(0,0,130,200),sf::milliseconds(500));
    squat->addFrame(sf::IntRect(130,0,130,200),sf::milliseconds(500));
    squat->setBidirectional(false);
    player.addAnimationSequence(squat);
    player.setAnimationSeq(0);
    player.getSprite().setPosition(sf::Vector2f(500.f,400.f));
}
