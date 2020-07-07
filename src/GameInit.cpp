#include "Game.hpp"
#include "AnimatedSprite.hpp"
#include "Sword.hpp"
#include "Helmet.hpp"
#include "GameObject.hpp"
Game::Game(){
    
    window.create(sf::VideoMode(800,600), "Birbhous Game Jam");
    //Intentional delay, might move this to my own thing?
    window.setFramerateLimit(framelimit);
    window.setKeyRepeatEnabled(false);
    running=true;
    tilemap= new sf::Texture;
    tilemap->loadFromFile("res/tilemap.png");
    player = new Player(this); 
    player->setTexture(tilemap);

    quad = new Quadtree(0, sf::FloatRect(0,0,800,600));
    addObject(player);
    addObject(new Obstacle(tilemap, sf::FloatRect(260,500,500,100)));
    addObject(new Obstacle(tilemap, sf::FloatRect(760,400,100,100)));
    addObject(new Sword(tilemap, sf::Vector2f(760,400)));
    addObject(new Helmet(tilemap, sf::Vector2f(500,400)));
}
