#include "Game.hpp"
#include <iostream>
void Game::loop(){
    /*
    quad->clear();
    std::vector<GameObject*>::iterator obj;
    for(obj=objects.begin();obj<objects.end();obj++){
        quad->insert(*obj);
    }

    std::vector<GameObject *> collidables;

    //Might temporarily get rid of using quadtrees until I figure out why it's not working.
    
    for(obj=objects.begin();obj<objects.end();obj++){
        collidables.empty();
        quad->retrieve(collidables,*obj);

        std::vector<GameObject*>::iterator collision;
        for(collision=collidables.begin();collision<collidables.end();collision++){
            std::cout << (*collision)->getId() << std::endl;    
            (*obj)->detectCollisions(*collision);
        }
    }

    for(obj=objects.begin();obj<objects.end();obj++){
        (*obj)->update();
    }*/

    std::vector<GameObject*>::iterator obj,other;

    for(obj=objects.begin();obj<objects.end();obj++){
        for(other=objects.begin();other<objects.end();other++){
            if(obj != other){
                std::cout << "Obj:" << (*obj)->getId() << "Other:" << (*other)->getId() << std::endl;
                (*obj)->detectCollisions(*other);
            }
        }
        (*obj)->update();
    }
}
