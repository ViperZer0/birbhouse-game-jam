#include "Game.hpp"
#include "AnimatedSprite.hpp"

Game::Game(){
    window.create(sf::VideoMode(800,600), "Birbhous Game Jam");
    window.setKeyRepeatEnabled(false);
    running=true;
    tilemap= new sf::Texture;
    tilemap->loadFromFile("res/tilemap.png");
    
    player.setTexture(tilemap);

    quad = new Quadtree(0, sf::FloatRect(0,0,800,600));
    objects.push_back(&player);
    objects.push_back(new Obstacle(tilemap, sf::FloatRect(260,500,500,100)));
    objects.push_back(new Obstacle(tilemap, sf::FloatRect(760,400,100,100)));

}
