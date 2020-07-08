#include "Game.hpp"

void Game::removeObject(GameObject *obj){
    std::vector<GameObject *>::iterator it;
    it = find(objects.begin(), objects.end(), obj);
    if(it != objects.end())
        objects.erase(it);
}

void Game::addObject(GameObject *obj){
    objects.push_back(obj);
}
