#pragma once
#include "cocos2d.h"

class SimpleShaderExample : public cocos2d::Scene
{
public:
    virtual bool init();
    virtual void update(float delta);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SimpleShaderExample);
};
