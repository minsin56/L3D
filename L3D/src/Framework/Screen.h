#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

class Screen
{
public:
    static GLFWwindow* Window;

    static void Init(int Width,int Height);
    static void Close();
};
