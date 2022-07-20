#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entity/registry.hpp>
#include "../components/allComponents.hpp"
#include <iostream>

    class AnimationSystem{

        unsigned int frameCounterAnimation{0};
        const unsigned int framesToWait{6};
        sf::Time accumulatedTime{sf::milliseconds(0)};

        public:
        AnimationSystem() = default;

        void update(sf::Time delta,entt::registry& engine);


    };