#include "Game.hpp"

void Game::render(){
    window.clear(sf::Color(127,164,249));
    window.draw(*player);
    for(auto const& value: objects){
        window.draw(*value);
    }
    window.display();
}
