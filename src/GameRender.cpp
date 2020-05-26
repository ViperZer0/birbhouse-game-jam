#include "Game.hpp"

void Game::render(){
    window.clear(sf::Color::Red);
    window.draw(player);
    for(auto const& value: objects){
        window.draw(*value);
    }
    window.display();
}
