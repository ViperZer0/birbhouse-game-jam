#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "AnimatedSprite.hpp"
#include "Player.hpp"
class Game{
    private:
        sf::RenderWindow window;
        sf::Texture *tilemap;
        Player player; 

    public:
        bool running;
        Game();
        void events();
        void loop();
        void render();
        ~Game();
};
