#include "Game.hpp"
#include "AnimatedSprite.hpp"

Game::Game(){
    window.create(sf::VideoMode(800,600), "Birbhous Game Jam");
    window.setKeyRepeatEnabled(false);
    running=true;
    tilemap= new sf::Texture;
    tilemap->loadFromFile("res/tilemap.png");
    
    player.setTexture(tilemap);
}
