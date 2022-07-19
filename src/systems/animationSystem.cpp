#include "animationSystem.hpp"


void AnimationSystem::update(sf::Time delta,entt::registry& engine){
    bool devolver = true;

    auto view = engine.view<RenderComponent,AnimationComponent>();

    for(auto entity : view){
        auto& animationCMP = view.get<AnimationComponent>(entity);
        animationCMP.currentMilliseconds+=(unsigned int)delta.asMilliseconds();
        if(animationCMP.currentMilliseconds >= animationCMP.animationSpeedMilliseconds){
            
            animationCMP.currentAnimationStep++;

            if(animationCMP.currentAnimationStep == animationCMP.animationSize)
                animationCMP.currentAnimationStep = 0;

            auto& renderCMP = view.get<RenderComponent>(entity);
        }
    }

    //////

}