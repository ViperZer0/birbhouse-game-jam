#pragma once
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>
class AnimationSequence{
    private:
        unsigned int frame;
        bool right;
        bool bidirectional;
        std::vector<sf::IntRect> frames;
        std::vector<sf::Time> frameHold;
        sf::Clock clock;
    public:
        AnimationSequence();
        //A generic update() keeps track of the time passed, updates the frame accordingly, keeping track of bidirectionality and stuff
        sf::IntRect update();
        //Same as update() but doesn't care about time.
        sf::IntRect next();
        //Same as next() but goes in the opposite direction of the right flag
        sf::IntRect prev();
        //Should frames go "back and forth"? (1, 2, 3, 4, 5, 4, 3, 2...)
        void setBidirectional(bool state);
        //add a frame
        void addFrame(sf::IntRect frame,sf::Time frameHold);
        //get current frame 
        sf::IntRect getFrame();
};

