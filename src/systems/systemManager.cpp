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

        aa.update(deltaTime,engine);

        //update rendersystem, it can return false
        if(!rs.update(deltaTime,engine))
            this->currentPhase = Phase::none;
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