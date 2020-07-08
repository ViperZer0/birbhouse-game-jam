#include "Logger.hpp"

std::ostream& operator<<(std::ostream& os, sf::FloatRect rect){
    os << "(Left: " << rect.left << ", Top: " << rect.top << ", Width: " << rect.width << ", Height: " << rect.height << ")";
    return os;
}
std::ostream& operator<<(std::ostream& os, sf::Vector2f vec){
    os << "(" << vec.x << "," << vec.y << ")";
    return os;
}
std::ostream& operator<<(std::ostream& os, float array[2]){
    os << "(" << array[0] << "," << array[1] << ")";
    return os; 
}
