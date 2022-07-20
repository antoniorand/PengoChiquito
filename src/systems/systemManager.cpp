#include "systemManager.hpp"

void SystemManager::menuScreenUpdate(entt::registry& engine){

    //if the components aren't loaded

    if(!loaded){
        //load components into RAM
        //to be changed
        loadMenuComponents(engine);
    }

    //we update the systems
    else{
        if(!rs.updateInputs(engine))
            currentPhase = Phase::none;
        aa.update(deltaTime,engine);
        //update rendersystem, it can return false
        rs.update(deltaTime,engine);
    }

}

void SystemManager::update(entt::registry&engine){
    //update this crap!!!
    currentBehaviour(engine);

    //wait until the frame is completed, unless we take too much time in game logic
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}

void SystemManager::loadMenuComponents(entt::registry&engine){
    
    //When PhaseSystem ends loading the entities, it will return true
    loaded = loaders.update(engine,"resources/menu.json");

}