#version 330

varying vec2 texCoord0;

uniform sampler2D diffuse;

out vec4 out_Color;

void main()
{
	out_Color = texture2D(diffuse, texCoord0);
}