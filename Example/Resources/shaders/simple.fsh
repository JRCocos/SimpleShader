uniform sampler2D someTexture;
uniform float speed;

void main()
{
    //u_texture is the sprites original texture
    vec4 spritesTexture = texture2D(u_texture, cc_FragTexCoord1);

    //the texture we passed as a uniform
    vec4 tex = texture2D(someTexture, cc_FragTexCoord1);

    //a value ocillating between 0 and 1
    float mixValue = sin(cc_Time * speed) * 0.5 + 0.5;

    //set final color
    gl_FragColor = cc_FragColor * mix(spritesTexture, tex, mixValue);
}