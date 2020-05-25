#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AnimatedSprite.h"
class Game{
    private:
        sf::RenderWindow window;
        sf::Texture *tilemap;
        AnimatedSprite player; 
    public:
        bool running;
        Game();
        void events();
        void loop();
        void render();
        ~Game();
};
