#include "Game.hpp"
#include "Logger.hpp"

void Game::render(){
    Logger::log(Log::DEBUG,"Hi, rendering.");
    window.clear(sf::Color(127,164,249));
    window.draw(*player);
    for(auto const& value: objects){
        window.draw(*value);
    }
    window.display();
}
