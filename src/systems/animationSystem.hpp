#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entity/registry.hpp>
#include "../components/allComponents.hpp"
#include <iostream>

    class AnimationSystem{

        public:
        AnimationSystem() = default;

        void update(sf::Time delta,entt::registry& engine);


    };