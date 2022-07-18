#include "loaderSystem.hpp"

bool LoaderSystem::update(entt::registry& engine, std::string file){

    
    bool devolver = false;
    if(!loaded){
        Json::Value root;
        std::ifstream config_doc(file, std::ifstream::binary);

        config_doc >> root;

        const Json::Value my_layers = root["layers"];
        
        for(unsigned int index = 0; index < my_layers.size(); index++){
            if( my_layers[index]["name"] ==  "Entities"){
                entities = my_layers[index]["objects"];
                loaded = true;
                break;
            }
        }
    }

    for(std::uint32_t toLoad = LoadedEntities + maxEntitiesLoadPerFrame; 
        LoadedEntities <= toLoad; LoadedEntities++){
            if(LoadedEntities < entities.size()){
                const auto entity = engine.create();
                parseEntity(entities[LoadedEntities]["properties"], engine,entity);
            }
            else{
                devolver = true;
                entities.clear();
                loaded = false;
                break;
            }
    }

    return devolver;
}

void LoaderSystem::parseRender(Json::Value value, entt::registry&engine, const entt::entity entityId){

    auto file = value["File"].asString();

    std::cout << file << std::endl;

    if(textureResources.find(file) == textureResources.end()){
        sf::Texture text;
        if(text.loadFromFile(file)){
            textureResources.emplace(file,text);
        }
    }

    {
        RenderComponent cmp;
        cmp.sprite.setTexture(textureResources[file]);
        cmp.sprite.setTextureRect(sf::IntRect{0,0,value["Width"].asInt(),value["Height"].asInt()});
        cmp.sprite.setPosition(value["PositionX"].asFloat(),value["PositionY"].asFloat());
        cmp.posXInterpolated = value["PositionX"].asFloat();
        cmp.posYInterpolated = value["PositionY"].asFloat();
        engine.emplace<RenderComponent>(entityId,cmp);
    }


}

void LoaderSystem::parseAnimation(Json::Value value, entt::registry&engine, const entt::entity entityId){

    {
        AnimationComponent cmp;
        cmp.animationSize = value["AnimationSize"].asUInt();
        cmp.animationSpeedMilliseconds = value["AnimationSpeedMilliseconds"].asUInt();
        cmp.numberOfAnimations = value["NumberOfAnimations"].asUInt();
        cmp.currentAnimation = value["FirstAnimation"].asUInt();
        cmp.running = value["Running"].asBool();
        engine.emplace<AnimationComponent>(entityId,cmp);
    }

}

void LoaderSystem::parsePosition(Json::Value value, entt::registry&engine, const entt::entity entityId){


}

void LoaderSystem::parseOption(Json::Value value, entt::registry&engine, const entt::entity entityId){


}

void LoaderSystem::parseLayer(Json::Value value, entt::registry&engine, const entt::entity entityId){


}


void LoaderSystem::parseEntity(Json::Value entity, entt::registry&engine, const entt::entity entityId){

    enum class ComponentType : unsigned int{

        RenderComponent = 0,
        AnimationComponent = 1,
        PositionComponent = 2,
        OptionComponent = 3,
        LayerComponent = 4

    };

    unsigned int componentSize = entity.size();
    static std::map<std::string,unsigned int> componentsType;
    
    if(componentsType.empty()){
        componentsType["RenderComponent"] = (unsigned int)ComponentType::RenderComponent;
        componentsType["AnimationComponent"] = (unsigned int)ComponentType::AnimationComponent;
        componentsType["PositionComponent"] = (unsigned int)ComponentType::PositionComponent;
        componentsType["OptionComponent"] = (unsigned int)ComponentType::OptionComponent;
        componentsType["LayerComponent"] = (unsigned int)ComponentType::LayerComponent;
    }
    
    for(unsigned int i = 0; i < componentSize; i++){

        auto switchType = componentsType[entity[i]["propertytype"].asString()];

        switch (switchType){
            case (unsigned int)(ComponentType::RenderComponent) :
                parseRender(entity[i]["value"],engine, entityId);
            break;
            case (unsigned int)(ComponentType::AnimationComponent) :
                parseAnimation(entity[i]["value"],engine, entityId);
            break;
            case (unsigned int)(ComponentType::PositionComponent) :
                parsePosition(entity[i]["value"],engine, entityId);
            break;
            case (unsigned int)(ComponentType::OptionComponent) :
                parseOption(entity[i]["value"],engine, entityId);
            break;
            case (unsigned int)(ComponentType::LayerComponent) :
                parseLayer(entity[i]["value"],engine, entityId);
            break;
        
            default:
            break;
        }

    }
    
}