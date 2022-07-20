#include "renderSystem.hpp"

RenderSystem::RenderSystem(unsigned int frameLimit){
    window.create(sf::VideoMode(400, 240), "Pengo Chiquito");
    window.setFramerateLimit(frameLimit);
    events_Stored.emplace(sf::Keyboard::Key::W,false);
    events_Stored.emplace(sf::Keyboard::Key::A,false);
    events_Stored.emplace(sf::Keyboard::Key::S,false);
    events_Stored.emplace(sf::Keyboard::Key::D,false);
    events_Stored.emplace(sf::Keyboard::Key::Up,false);
    events_Stored.emplace(sf::Keyboard::Key::Down,false);
    events_Stored.emplace(sf::Keyboard::Key::Left,false);
    events_Stored.emplace(sf::Keyboard::Key::Right,false);
    events_Stored.emplace(sf::Keyboard::Key::Space,false);
    events_Stored.emplace(sf::Keyboard::Key::RControl,false);
}

bool RenderSystem::updateInputs(entt::registry& engine){

    bool devolver = true;

    if(frameCounterInput < framesToWait)
        frameCounterInput++;
    else{
        sf::Event event{};

        while(window.pollEvent(event)){
            
            if(event.type == sf::Event::KeyPressed){
                
                auto it = events_Stored.find(event.key.code);
                if(it != events_Stored.end()){
                    inputsRead = true;
                    it->second = true;
                }
            }

            if(event.type == sf::Event::Closed){
                window.close();
                devolver = false;
            }
        }

        if(inputsRead){
            auto itBegin = events_Stored.begin();
            auto itEnd = events_Stored.end();

            while(itBegin != itEnd){
                itBegin->second = false;
                itBegin++;
            }

            inputsRead = false;
        }

        frameCounterInput = 0;
    }

    return devolver;

}

void RenderSystem::update(sf::Time delta,entt::registry& engine){
    window.clear();
    
    //////

    auto view = engine.view<RenderComponent>();

    for(auto entity : view){
        auto& renderCMP = view.get<RenderComponent>(entity);
        window.draw(renderCMP.sprite);
    }
    //////

    window.display();
     
}