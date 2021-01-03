#include "Screen.h"

#include <iostream>

GLFWwindow* Screen::Window;

void Screen::Init(int Width, int Height, const char* Title)
{
    if(!glfwInit())
    {
        Close();
        return;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window = glfwCreateWindow(Width,Height,Title,NULL,NULL);

    if(!Window)
    {
        Close();
        return;
    }

    
    glfwMakeContextCurrent(Window);
    glewExperimental=true; // Needed in core profile

    GLenum E = glewInit();
    if(!E)
    {
        std::cout<<glewGetErrorString(E);
    }

    glViewport(0,0,Width,Height);

}

void Screen::Close()
{       
    glfwDestroyWindow(Window);
    glfwTerminate();
}