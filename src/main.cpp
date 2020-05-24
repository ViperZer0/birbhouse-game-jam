#include "Game.h"

int main(){
    Game game;
    
    while(game.running){
        game.events();
        game.loop();
        game.render();
    }
    //Deconstruction handled automatically
}
