#pragma once
#include <iostream>
#include <SFML/Graphics/Rect.hpp>

enum class Log{DEBUG=0,WARNING=1,ERROR=2};

class Logger{
    private:
        static constexpr std::ostream& output = std::cout;
        static constexpr Log minLevel = Log::DEBUG;
    public:
        template <typename T>
        static void log(Log logLevel, T first){
            if(logLevel >= minLevel)
                output << first << std::endl;
        }

        template <typename T,typename... Ts>
        static void log(Log logLevel,T first, Ts... message){
            if(logLevel >= minLevel){
                output << first;
                Logger::log(logLevel, message...);
            }
        }
};
/*
template <typename T>
std::ostream& operator<<(std::ostream& os, sf::Rect<T> rect){
    os << "(Left: " << rect.left << ", Top: " << rect.top << ", Width: " << rect.width << ", Height: " << rect.height << ")";
    return os;
}*/

std::ostream& operator<<(std::ostream& os, sf::FloatRect rect);
std::ostream& operator<<(std::ostream& os, sf::Vector2f vec);
std::ostream& operator<<(std::ostream& os, float array[2]);
/*
template <typename T>
std::ostream& operator<<(std::ostream& os, T* ptr){
    os << static_cast<void const *>(ptr);
    return os;
}*/

