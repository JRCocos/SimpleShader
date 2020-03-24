# SimpleShader
This is a simple utility for creating shaders inside of Cocos2dx
it simplifies the creation and usage of fragment shaders.

# Usage
```c++
//create new shader with default vertex shader
auto shader = SimpleShader::createWithFragmentShader("shaders/simple.fsh");

//set float uniform
shader->setUniform("opacity", 0.5f);

//set texture uniform (SimpleShader will manage the texture slots for you)
auto tex = Director::getInstance()->getTextureCache()->addImage("textures/tex.png");
shader->setUniform("someTexture", tex);

//apply shader to a sprite 
sprite->setProgramState(shader->programState);
```

# Simpler Fragment Shaders
SimpleShader makes creating custom fragment shaders easier by eliminating boilerplate code,
all you need to do is define your custom uniforms and main function 

```glsl
uniform sampler2D someTexture;
uniform float opacity;

void main()
{
    //u_texture is the sprites original texture
    vec4 spritesTexture = texture2D(u_texture, cc_FragTexCoord1);

    //the texture we passed as a uniform
    vec4 tex = texture2D(someTexture, cc_FragTexCoord1);

    gl_FragColor = mix(spritesTexture, tex, opacity);
}
```

![Example Shader](https://raw.githubusercontent.com/JRCocos/SimpleShader/master/example.png)

SimpleShader automatically injects these uniforms into your shaders
```glsl
//the texture of the sprite the shader is applied to 
u_texture

//the texture coordinates
cc_FragTexCoord1

//the color of the sprite the shader is applied to
cc_FragColor

//the current time in seconds 
cc_Time
```

# Time Based Effects
by default SimpleShader adds a ```cc_Time``` uniform to all fragment shaders for easily creating time based effects,
to update the time uniform for all shaders simply call the ```updateShaderTime``` method on the SimpleShaderManager object in your scenes update method

```c++
//call scheduleUpdate() in your scenes init method to enable update callbacks
virtual void update(float delta)
{
    SimpleShaderManager::getInstance()->updateShaderTime();
}
```