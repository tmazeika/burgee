#version 330 core

in vec2 position;
in vec3 color;

out vec3 vert_color;

void main()
{
    vert_color = color;
    gl_Position = vec4(position, 0.0f, 1.0f);
}