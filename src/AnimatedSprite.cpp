#include "AnimatedSprite.hpp"
#include <iostream>
AnimatedSprite::AnimatedSprite(){
    //Empty :C
}

AnimatedSprite::AnimatedSprite(sf::Texture *tex){
    setTexture(tex);
}

void AnimatedSprite::setTexture(sf::Texture* tex){
    this->tex = tex;
    sprite.setTexture(*tex);
}

void AnimatedSprite::setAnimationSeq(AnimationSequence* seq){
    animation = seq;
}

void AnimatedSprite::update(){
    sprite.setTextureRect(animation->update());
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(sprite);
}

sf::Sprite AnimatedSprite::getSprite(){
    return sprite;
}

int AnimatedSprite::getFrame(){
    return animation->getFrameNum();
}

