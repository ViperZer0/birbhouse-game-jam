cmake_minimum_required(VERSION 3.1)

project(birbhouse-game-jam)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(birbhouse-game-jam 
    src/main.cpp
    src/GameInit.cpp
    src/GameEvents.cpp
    src/GameLoop.cpp
    src/GameRender.cpp
    src/GameExit.cpp
    )
target_link_libraries(birbhouse-game-jam sfml-graphics sfml-audio)
