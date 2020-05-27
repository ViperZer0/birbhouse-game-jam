#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

#include "AnimatedSprite.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "QuadTree.hpp"
#include "GameObject.hpp"
class Game{
    private:
        sf::RenderWindow window;
        sf::Texture *tilemap;
        Player player; 
        std::vector<GameObject *> objects; 
        const int framelimit = 30;
        //std::vector<Obstacle> obstacles;
        Quadtree *quad;
    public:
        bool running;
        Game();
        void events();
        void loop();
        void render();
        //Set framerate limit to eliminate clipping
        void wait();
        ~Game();
};
