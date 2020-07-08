#include "Equipment.hpp"

class Sword: public Equipment{
    private: 
        //Stats proly
        float attack;
        sf::Time swingTime;
    public:
        Sword(sf::Texture *tex,sf::Vector2f position);
        virtual void update();
}; 
