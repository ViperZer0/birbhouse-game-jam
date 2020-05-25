#include "AnimationSequence.hpp"
#include <iostream>
AnimationSequence::AnimationSequence(){
    this->frame = 0;
    this->right = true;
    this->clock.restart();
}

sf::IntRect AnimationSequence::update(){
    sf::IntRect f = frames[frame];
    if(clock.getElapsedTime() > frameHold[frame]){
        f = next();
        clock.restart();
    }
    return f;
}

sf::IntRect AnimationSequence::next(){
    if(bidirectional){
        if(right){
            frame++;
            if (frame >= frames.size()){
                right = false;
                frame -= 2;
            }
        }
        else{
            frame--;
            if(frame <= 0){
                right = true;
                frame += 2;
            }
        }
    }
    else{
        if(right){
            frame++;
            if(frame >= frames.size()){
                frame = 0;
            }
        }
        else{
            frame--;
            if(frame <=0){
                frame = frames.size()-1;
            }
        }
    }
    return getFrame();
}

sf::IntRect AnimationSequence::prev(){
    if(bidirectional){
            if(!right){
                if (frame < frames.size()) frame++;
                else{
                    right = false;
                    frame--;
                }
            }
            else{
                if(frame > 0) frame--;
                else{
                    right = true;
                    frame++;
                }
            }
        }
        else{
            if(!right){
                if (frame < frames.size()) frame++;
                else{
                    frame = 0;
                }
            }
            else{
                if(frame >0) frame--;
                else{
                    frame = frames.size()-1;
                }
            }
        }
    return getFrame();
}

sf::IntRect AnimationSequence::getFrame(){
    return frames[frame];
}

void AnimationSequence::setBidirectional(bool state){
    bidirectional = state;
}

void AnimationSequence::addFrame(sf::IntRect frame,sf::Time frameHold){
    frames.emplace_back(frame);
    this->frameHold.emplace_back(frameHold);
}

