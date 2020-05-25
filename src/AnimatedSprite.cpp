#include "AnimatedSprite.h"
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

void AnimatedSprite::addAnimationSequence(AnimationSequence* seq){
    animations.push_back(seq);
}

void AnimatedSprite::setAnimationSeq(int currentSeq){
    if((currentSeq >= 0) && (currentSeq < animations.size())){
        this->currentSeq = currentSeq;
    }
}

void AnimatedSprite::update(){
    sprite.setTextureRect(animations[currentSeq]->update());
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    std::cout << "texture:" << sprite.getTexture() << std::endl;
    std::cout << "sprite:(" << sprite.getTextureRect().left << "," << sprite.getTextureRect().top << "," << sprite.getTextureRect().width << "," << sprite.getTextureRect().height << ")" << std::endl;
    target.draw(sprite);
}

sf::Sprite AnimatedSprite::getSprite(){
    return sprite;
}

