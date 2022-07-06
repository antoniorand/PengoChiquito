#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../systems/systemManager.hpp"
class Pengo{

    //the engine will store all of the game data
    entt::registry engine;
    //the systems will be the game logic
    SystemManager systems;


    public:
        //default constructor
        Pengo() = default;
        //run this crap!
        void run();
        //default destructor
        ~Pengo() = default;

};