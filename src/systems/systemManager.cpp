#include "systemManager.hpp"

void SystemManager::menuScreenUpdate(entt::registry& engine){

    //if the components aren't loaded

    if(!loaded){
        //load components into RAM
        //to be changed
        if(loadMenuComponents(engine))
            loaded = true;
    }

    //we update the systems
    else{
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

bool SystemManager::loadMenuComponents(entt::registry&engine){
    //EMPTY BABYYYY

    return true;
}