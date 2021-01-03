#include "Screen.h"

#include <iostream>

GLFWwindow* Screen::Window;

void Screen::Init(int Width, int Height)
{
    if(!glfwInit())
    {
        Close();
        return;
    }
    Window = glfwCreateWindow(Width,Height,"L3D",NULL,NULL);

    if(!Window)
    {

        Close();
        return;
    }

    glfwMakeContextCurrent(Window);
}

void Screen::Close()
{       
    glfwDestroyWindow(Window);
    glfwTerminate();
}