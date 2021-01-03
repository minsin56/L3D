#include "LuaScript.h"


#include "Framework/Graphics.h"
#include "LuaFunctions.h"
#include "Framework/Utils/VertexArray.h"

LuaScript::LuaScript(std::string Path)
{
    L = luaL_newstate();
    luaL_openlibs(L);

    
    Graphics::RegisterToLua(L);
    VertexArray::Register(L);
    luaL_dofile(L,Path.c_str());
}

void LuaScript::Close()
{
    lua_close(L);
}

void LuaScript::CallFunction(std::string Name)
{
    lua_getglobal(L,Name.c_str());
    if(lua_isfunction(L,-1))
    {
        lua_pcall(L,0,0,0);
    }
}