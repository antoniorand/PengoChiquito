#pragma once

struct AnimationComponent{

    unsigned int animationSize;
    unsigned int animationSpeedMilliseconds;
    unsigned int currentMilliseconds{0};
    unsigned int numberOfAnimations;
    unsigned int currentAnimation;
    unsigned int currentAnimationStep{0};
    bool running;

};