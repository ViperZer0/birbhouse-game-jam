#include "Game.hpp"

void Game::render(){
    window.clear(sf::Color::Red);
    window.draw(player);
    window.display();
}
