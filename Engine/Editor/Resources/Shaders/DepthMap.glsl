// type vertex
#version 450 core
layout(location = 0) in vec3 aPos;

uniform mat4 viewProjection;
uniform mat4 model;

void main()
{
    gl_Position = viewProjection * vec4(aPos, 1.0);
}

// type fragment
#version 450 core

void main()
{
}
