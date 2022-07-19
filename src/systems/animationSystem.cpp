#include "animationSystem.hpp"


void AnimationSystem::update(sf::Time delta,entt::registry& engine){

    //get the entities that has render and animation component
    auto view = engine.view<RenderComponent,AnimationComponent>();

    //for every entity that we got
    for(auto entity : view){
        
        //get the animation component
        AnimationComponent& animationCMP = view.get<AnimationComponent>(entity);
        //update it's milliseconds
        animationCMP.currentMilliseconds+=(unsigned int)delta.asMilliseconds();
        //if the milliseconds have surpassed it's limit, we need to manipulate the sprite
        if(animationCMP.currentMilliseconds >= animationCMP.animationSpeedMilliseconds){
            //get the difference
            unsigned int difference = animationCMP.currentMilliseconds - animationCMP.animationSpeedMilliseconds;
            //turn the animation millisecond to 0 and add the difference
            animationCMP.currentMilliseconds = 0 + difference;
            //we change the animation step
            animationCMP.currentAnimationStep++;
            //and if this is the last step, we go back to 0
            if(animationCMP.currentAnimationStep == animationCMP.animationSize)
                animationCMP.currentAnimationStep = 0;

            //scope in which we instance the animation sprite logic
            {
                //get the render component
                RenderComponent& renderCMP = view.get<RenderComponent>(entity);
                //get the texture rect
                auto textureRect = renderCMP.sprite.getTextureRect();
                //the corner is now current animation step multiplied by width
                //for example, if we are in step 3, this will be the sprite number 3, in a collection
                //of 20*20 size sprites. We make a square that starts in sprite number 3 so the left-side point is
                //2*20 (the third sprite) with a size of 20*20. The top point of the texture rect doesn't change here
                textureRect.left = textureRect.width*animationCMP.currentAnimationStep;
                renderCMP.sprite.setTextureRect(textureRect);
                //std::cout << "animation step: " << animationCMP.currentAnimationStep << std::endl;
                //std::cout << "width: " << textureRect.width << std::endl;
            }
        }
    }

    //////

}