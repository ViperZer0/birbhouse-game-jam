#include <vector>
#include "GameObject.hpp"

class Quadtree {
    private:
        int MAX_OBJECTS=10;
        int MAX_LEVELS =5;
        int level;
        std::vector<GameObject *> objects;
        sf::FloatRect bounds;
        std::vector<Quadtree *> nodes;
    public:
        Quadtree(int level, sf::FloatRect bounds){
            this->level = level;
            this->bounds = bounds;
        }
        
        void clear();
        
        void split();

        int getIndex(GameObject* obj);
            
        void insert(GameObject* obj);

        std::vector<GameObject *> retrieve(std::vector<GameObject *> collidables, GameObject *obj);
};
