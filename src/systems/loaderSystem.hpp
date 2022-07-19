#pragma once

#include <SFML/Graphics.hpp>
#include <entt/entity/registry.hpp>
#include <cstdint>
#include <fstream>
#include <json/json.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include "../components/allComponents.hpp"

    class LoaderSystem{

        std::unordered_map<std::string,sf::Texture> textureResources;
        void parseRender(Json::Value value, entt::registry&engine, const entt::entity entityId);

        void parseAnimation(Json::Value value, entt::registry&engine, const entt::entity entityId);

        void parsePosition(Json::Value value, entt::registry&engine, const entt::entity entityId);

        void parseOption(Json::Value value, entt::registry&engine, const entt::entity entityId);

        void parseLayer(Json::Value value, entt::registry&engine, const entt::entity entityId);


        std::uint32_t LoadedEntities {0};
        Json::Value entities{};
        bool loaded {false};

        const std::uint32_t maxEntitiesLoadPerFrame {100};

        void parseEntity(Json::Value entity, entt::registry&engine, const entt::entity entityID);

        public:
        LoaderSystem() = default;
        bool update(entt::registry& engine, std::string file);
    };