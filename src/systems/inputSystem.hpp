#pragma once

#include <SFML/Window.hpp>
#include <entt/entity/registry.hpp>
#include "../components/allComponents.hpp"
#include <iostream>
#include <vector>

    class InputSystem{

        sf::Window* window; //yikes... she wasn't lying object-oriented programming sure is awful sometimes...

        const unsigned int max_size_events{120};

        std::vector<sf::Event> events_Stored;

        void readFromKeyBoard();

        public:
        InputSystem(){
            events_Stored.reserve(max_size_events);
        };

        bool update(entt::registry& engine);


        void setWindowAddress(sf::Window* input){
            window = input;
        }; //This one is the worst function ever, actually;

    };