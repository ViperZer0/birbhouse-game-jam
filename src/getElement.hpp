#include <vector>
#include <string>
#include "GameObject.hpp"

GameObject* getElement(std::vector<GameObject *> objects,const std::string id){
    std::vector<GameObject *>::iterator obj;
    for(obj=objects.begin();obj<objects.end();obj++){
        if((*obj)->getId() == id)
            return *obj;
    }
    return nullptr;
}


