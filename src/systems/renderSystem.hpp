#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entity/registry.hpp>
#include "../components/allComponents.hpp"
#include <iostream>

    class RenderSystem{

        sf::RenderWindow window{};

        public:
        RenderSystem(unsigned int frameLimit);

        bool update(sf::Time delta,entt::registry& engine);


    };