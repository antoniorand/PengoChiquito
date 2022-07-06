
#include <iostream>
#include "game/game.hpp"

int main(){


    //CREATES IN THE CONSTRUCTOR THE APPLICATIONN
    Pengo game;

    //RUNS THE APPLICATION
    game.run();

    //THE GAME RESOURCES WILL BE DESTROYED CORRECTLY
    //SAY THANKS TO RAII DESIGN PATTERN
    

    //thanks raii :)

    return 0;
}