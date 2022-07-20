#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <entt/entity/registry.hpp>
#include "../components/allComponents.hpp"
#include <iostream>
#include <map>

    class RenderSystem{

        sf::RenderWindow window{};

        ////Input
        const unsigned int max_size_events{120};
        std::map<sf::Keyboard::Key,bool> events_Stored;
        bool inputsRead {false};
        unsigned int frameCounterInput{0};
        const unsigned int framesToWait{6};

        public:
        RenderSystem(unsigned int frameLimit);

        void update(sf::Time delta,entt::registry& engine);
        bool updateInputs(entt::registry& engine);

    };