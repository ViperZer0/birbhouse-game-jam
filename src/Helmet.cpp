#include "Helmet.hpp"

Helmet::Helmet(sf::Texture *tex, sf::Vector2f position){
    slot = Slot::HEAD;
    sprite.setTexture(*tex);
    sprite.setTextureRect(sf::IntRect(520,0,130,79));
    offset = sf::Vector2f(0.f,0.f);
    sprite.setPosition(position);
}
