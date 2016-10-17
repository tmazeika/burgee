#version 330 core

#define PI 3.1415926535897932384626433832795f

in vec3 vert_color;

out vec4 color;

uniform float time;

void main()
{
    color = vec4(abs(sin(time)) * vert_color.r, abs(sin(time - 4.0f * PI / 3.0f)) * vert_color.g, abs(sin(time - 2.0f * PI / 3.0f)) * vert_color.b, 1.0f);
}
