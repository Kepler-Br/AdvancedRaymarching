#version 330 core
out vec4 fragColor;

in vec2 textureCoord;

uniform sampler2D inputTexture;

void main()
{
    fragColor = texture(inputTexture, vec2(textureCoord.x, -textureCoord.y));
//    fragColor = vec4(textureCoord, 1.0f, 1.0f);
}