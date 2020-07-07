cmake_minimum_required(VERSION 3.1)

project(birbhouse-game-jam)

set(EXECUTABLE_OUTPUT_PATH ../)
set(CMAKE_BUILD_TYPE Debug)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(birbhouse-game-jam 
    src/main.cpp
    src/Game.cpp
    src/GameInit.cpp
    src/GameEvents.cpp
    src/GameLoop.cpp
    src/GameRender.cpp
    src/GameExit.cpp
    src/AnimatedSprite.cpp
    src/AnimationSequence.cpp
    src/GameActor.cpp
    src/Player.cpp
    src/QuadTree.cpp
    src/Equipment.cpp
    src/Sword.cpp
    src/Helmet.cpp
    src/Logger.cpp
    )
target_link_libraries(birbhouse-game-jam sfml-graphics sfml-audio)
