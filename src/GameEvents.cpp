#include "Game.hpp"
#include <SFML/Window/Event.hpp>

void Game::events(){
    sf::Event event;

    while(window.pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                running=false;
                break;
            default:
                player.handleInput(event);
        }
    }
}
