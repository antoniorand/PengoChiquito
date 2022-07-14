
#pragma once
#include <entt/entt.hpp>
#include "renderSystem.hpp"
#include "phaseSystem.hpp"
#include <functional>
#include <chrono>
#include <thread>

enum class Phase{
        menuScreen,
        optionScreen,
        gameplay,
        nextLevel,
        none
    };  

class SystemManager{

    //Enum class that can be only be used by System Manager
    //it defines the phases of the game

    

    //The current phase used for game logic
    Phase currentPhase;
    
    //is the currentPhase loaded???
    bool loaded = false;
    

    //the frame limit, 60 by default
    unsigned int frameLimit {60};

    //the delta time that depends on the frame limit
    sf::Time deltaTime {sf::milliseconds(1000/frameLimit)};
    
    /*
        *********
        *Systems*
        *********

        These are the systems to be used
        We put them in here
        Later, these well be used by their proper
        update function

    */

    //Render system, just renders the sprites or graphics
    //It also handles interpolation movement, but nothing very heavy after this
    RenderSystem rs;
    //SoundSystem ss;
    //InputSystem is;
    //GridSystem gs;
    //Levelsystem ls;
    //AnimationSystem aa;
    PhaseSystem ps;

    /*
        ******************
        *Update functions*
        ******************

        These are the systems to be used
        We put them in here
        Later, these well be used by their proper
        update function

    */

    //It updates the menu screen
    void menuScreenUpdate(entt::registry&engine);

    //Basically, a wrapped function pointer
    //we won't be calling "menuScreenUpdate"
    //we will store the "pointer" and the call currentBehaviour
    //this will eliminate too many ifs :)
    std::function<void(entt::registry&)> currentBehaviour;

    /*
        ******************
        *Load functions*
        ******************

        The first frame or first few frames
        will be used for loading the components into the RAM
        during this time, we will be using
        "loading" until the ram gets all of the resources

    */

    //loads the components from the menu
    void loadMenuComponents(entt::registry&engine);

    public:
    //we will initialize the variables
    //initial behaviour will be menu screen update
    SystemManager() : currentPhase{Phase::menuScreen}, 
        currentBehaviour {std::bind(&SystemManager::menuScreenUpdate,this,std::placeholders::_1)}{
    }
    //default destructor
    ~SystemManager() = default;

    //update this crap!!!
    void update(entt::registry& engine);

    //check if the game is still running
    bool stillRunning(){
        return(!(currentPhase == Phase::none));
    }


};

