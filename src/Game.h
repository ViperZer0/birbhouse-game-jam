#include <SFML/Graphics/RenderWindow.hpp>

class Game{
    private:
        sf::RenderWindow window;

    public:
        bool running;
        Game();
        void events();
        void loop();
        void render();
        ~Game();
};
