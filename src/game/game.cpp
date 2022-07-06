#include "game.hpp"


void Pengo::run(){

    //if the game is still running
    while (systems.stillRunning()){
        //then update the systems (game logic)
        systems.update(engine);
    }

}

