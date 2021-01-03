#version 440 core

layout(location = 0) in vec3 InPos;

out vec3 OutPos;

void main()
{
    gl_Position  = vec4(InPos.x, InPos.y,InPos.z,1);
    OutPos = InPos;
}
