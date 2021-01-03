#pragma once
#include <string>

extern "C" {
# include "lua/lua.h"
# include "lua/lauxlib.h"
# include "lua/lualib.h"
}

#include "LuaBridge/LuaBridge.h"
class LuaScript
{
public:
    LuaScript(std::string Path);

    void Close();
    void CallFunction(std::string Name);
    lua_State* L;
};
