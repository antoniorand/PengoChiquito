#include "renderSystem.hpp"

RenderSystem::RenderSystem(unsigned int frameLimit){
    window.create(sf::VideoMode(400, 240), "SFML works!");
    window.setFramerateLimit(frameLimit);
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

    auto view = engine.view<RenderComponent>();

    for(auto entity : view){
        auto& renderCMP = view.get<RenderComponent>(entity);
        window.draw(renderCMP.sprite);

    //////

    window.display();
     
    return devolver;
}