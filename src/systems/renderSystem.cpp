#include "renderSystem.hpp"

RenderSystem::  RenderSystem(){
    window.create(sf::VideoMode(400, 240), "SFML works!");
}

bool RenderSystem::update(sf::Time delta,entt::registry& engine){
    bool devolver = true;
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape){
            window.close();
            devolver = false;
        }
    }         

    window.clear();
    
    //////

    

    //////

    window.display();
     
    return devolver;
}