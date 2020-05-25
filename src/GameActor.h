#include "GameObject.hpp"
#include <SFML/Graphics/Sprite.hpp>

class GameActor: public GameObject{
    private: 
        AnimatedSprite sprite;
    public:
        void update();
}

