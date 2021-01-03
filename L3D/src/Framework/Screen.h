#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

class Screen
{
public:
    static GLFWwindow* Window;

    static void Init(int Width,int Height, const char* Title = "L3D Game");
    static void Close();
};
