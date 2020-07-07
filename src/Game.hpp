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
        Player *player; 
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

        void removeObject(GameObject *);
        void addObject(GameObject *);
};
/*
void Game::removeObject(GameObject *obj){
    std::vector<GameObject *>::iterator it;
    it = find(objects.begin(), objects.end(), obj);
    if(it != objects.end())
        objects.erase(it);
}

void Game::addObject(GameObject *obj){
    objects.push_back(obj);
}*/
