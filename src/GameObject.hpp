#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <string>
class GameObject: public sf::Drawable{
    protected:
        std::string id;
    public:
        GameObject() { id = "";}
        virtual sf::FloatRect getGlobalBounds() {return sf::FloatRect(0,0,0,0);}
        virtual ~GameObject() {}
        std::string getId() const{ 
            return id;
        }
        virtual void detectCollisions(GameObject *obj) {}
        virtual void update() {}
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {}

};

