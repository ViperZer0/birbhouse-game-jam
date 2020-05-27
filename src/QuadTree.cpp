#include "QuadTree.hpp"

void Quadtree::clear(){
    objects.clear();
    for(auto const& node: nodes){
        if(node != nullptr){
            node->clear();
        }
    }
}

void Quadtree::split(){
    float subWidth = bounds.width/2;
    float subHeight = bounds.height/2;
    int x = bounds.left;
    int y = bounds.top;

    nodes.push_back(new Quadtree(level+1, sf::FloatRect(x+subWidth, y, subWidth, subHeight)));
    nodes.push_back(new Quadtree(level+1, sf::FloatRect(x,y, subWidth, subHeight)));
    nodes.push_back(new Quadtree(level+1, sf::FloatRect(x,y+subHeight,subWidth, subHeight)));
    nodes.push_back(new Quadtree(level+1, sf::FloatRect(x+subWidth, y+subHeight, subWidth, subHeight)));
}

int Quadtree::getIndex(GameObject* obj){
    /* -1 = doesn't fit in single quadrant.  * 0 = top right
     * 1 = top left
     * 2 = bottom left
     * 3 = bottom right
     */
    int index = -1;
    sf::FloatRect rect = obj->getGlobalBounds();
    double vertMid = bounds.left + bounds.width/2;
    double horizMid = bounds.top + bounds.height/2;

    //object bounds completely fit in top quadrant
    bool topQuad = (rect.top < horizMid) && (rect.top + rect.height < horizMid);
    //Object bounds completely fit in bottom quadrant
    bool botQuad = (rect.top > horizMid);

    //Object can completely fit within left quadrants
    if (rect.left < vertMid && rect.left + rect.width < vertMid){
        if (topQuad) {
            index = 1;
        }
        else if (botQuad){
            index = 2;
        }
    }
    else if (rect.left > vertMid) {
        if (topQuad){
            index = 0;
            }
            else if (botQuad){
                index = 3;
            }
        }
        return index;
}

void Quadtree::insert(GameObject* obj){
    if(!(nodes.empty())){
        int index = getIndex(obj);
        if(index != -1){
            nodes[index]->insert(obj);
            return;
        }
    }

    objects.push_back(obj);

    if (objects.size() > MAX_OBJECTS && level < MAX_LEVELS) {
        if(nodes.empty()){
            split();
        }

        std::vector<GameObject *>::iterator obj;
        for(obj=objects.begin(); obj < objects.end(); obj++){
            int index = getIndex(*obj);
            if(index != -1){
                nodes[index]->insert(*obj);
                obj =  objects.erase(obj);
            }
        }
    }
}

std::vector<GameObject *> Quadtree::retrieve(std::vector<GameObject *> collidables, GameObject *obj){
    int index = getIndex(obj);
    if(index != -1 && !(nodes.empty())){
        nodes[index]->retrieve(collidables,obj);
    }
    //add all objects to collidables. I have no idea what ANY of this actually does tbh 
    collidables.insert(collidables.end(), objects.begin(), objects.end());

    return collidables;
}
