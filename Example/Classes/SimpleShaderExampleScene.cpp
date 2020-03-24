#include "SimpleShaderExampleScene.h"
#include "SimpleShader.h"

USING_NS_CC;

bool SimpleShaderExample::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //create sprite
    auto sprite = Sprite::create("textures/1.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //create new shader with default vertex shader
    auto shader = SimpleShader::createWithFragmentShader("shaders/simple.fsh");

    //set float uniform
    shader->setUniform("speed", 1.0f);

    //set texture uniform (SimpleShader will manage the texture slots for you)
    auto tex = Director::getInstance()->getTextureCache()->addImage("textures/2.png");
    shader->setUniform("someTexture", tex);

    //apply shader to a sprite 
    sprite->setProgramState(shader->programState);

    //add sprite to scene
    this->addChild(sprite);

    scheduleUpdate();
    return true;
}

void SimpleShaderExample::update(float delta)
{
    //update cc_Time for all simple shaders
    SimpleShaderManager::getInstance()->updateShaderTime();
}
