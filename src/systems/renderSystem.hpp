#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>

    class RenderSystem{

        sf::RenderWindow window;

        public:
        RenderSystem();

        bool update(sf::Time delta,entt::registry& engine);


    };