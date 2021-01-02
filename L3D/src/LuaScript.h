#pragma once
#include <string>

#include "Lua/lua.hpp"
#include "LuaBridge/LuaBridge.h"
class LuaScript
{
public:
    LuaScript(std::string Path);

    void Close();
    void CallFunction(std::string Name);
    lua_State* L;
};
