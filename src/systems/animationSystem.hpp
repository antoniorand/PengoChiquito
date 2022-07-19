#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include "../components/allComponents.hpp"
#include <iostream>

    class AnimationSystem{

        public:
        AnimationSystem();

        void update(sf::Time delta,entt::registry& engine);


    };