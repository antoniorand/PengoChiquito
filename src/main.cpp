
#include <iostream>
#include <fstream>
#include "game/game.hpp"
#include <json/json.h>

int main(){

    /*Json::Value root;
    std::ifstream config_doc("resources/menu.json", std::ifstream::binary);

    config_doc >> root;

    const Json::Value my_layers = root["layers"];
    Json::Value entities;
    for(unsigned int index = 0; index < my_layers.size(); index++){
        if( my_layers[index]["name"] ==  "Entities")
            entities = my_layers[index]["objects"];  
    }*/

    //CREATES IN THE CONSTRUCTOR THE APPLICATIONN
    Pengo game;

    //RUNS THE APPLICATION
    game.run();

    //THE GAME RESOURCES WILL BE DESTROYED CORRECTLY
    //SAY THANKS TO RAII DESIGN PATTERN
    

    //thanks raii :)

    return 0;
}