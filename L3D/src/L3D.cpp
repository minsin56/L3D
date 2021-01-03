#include <fstream>
#include <iostream>
#include <string>
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "LuaScript.h"
#include "Framework/Screen.h"
//#include "Lua/lua.hpp"

int main(int argc, char* argv[])
{
    LuaScript* InitScript = new LuaScript("Game/Init.lua");
   
    Screen::Init(luabridge::getGlobal(InitScript->L,"Width").cast<int>(),luabridge::getGlobal(InitScript->L,"Height").cast<int>());
    InitScript->Close();
    LuaScript* Script = new LuaScript("Game/Main.lua");

    while(!glfwWindowShouldClose(Screen::Window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        Script->CallFunction("BeginDraw");
        
        Script->CallFunction("Draw");
                
        glfwSwapBuffers(Screen::Window);
        glfwPollEvents(); 
    }

    Screen::Close();
    
    Script->Close();

    return 0;
}
