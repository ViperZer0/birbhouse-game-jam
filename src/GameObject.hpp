#include <SFML/System/Clock.hpp>

class GameObject{
    protected:
        //Array of size 2, X and Y coordinates
        int pos[2]; //pixel
        int vel[2]; //pixels per second
        int acc[2]; //Pixels per second^2
        int jumpVel;
        int fallAcc;
        int moveSpeed;
        bool jumpDebounce;
        //Note we don't actually handle collisions in this function, we're gonna have children that do this.
        bool falling;
        bool collideRight;
        bool collideLeft;
        sf::Clock delta;

    public:
        GameObject();
        void jump();
        void right();
        void left();
        void stop();
        virtual void update();

};