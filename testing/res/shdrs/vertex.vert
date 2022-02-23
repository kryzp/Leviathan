#version 330 core

layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 a_colour;
layout (location = 2) in vec2 a_tex_coord;

out vec3 our_colour;
out vec2 tex_coord;

void main()
{
    gl_Position = vec4(a_pos, 1.0);
    our_colour = a_colour;
    tex_coord = a_tex_coord;
}
